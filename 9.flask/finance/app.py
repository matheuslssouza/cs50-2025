import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    if request.method == "GET":
        user_id = session["user_id"]
        user_cash = db.execute("SELECT cash FROM users WHERE id = ?", user_id)[0]["cash"]
        transactions = db.execute("""
            SELECT
                symbol,
                SUM(shares) AS sum_quotes,
                SUM(shares * price) AS total_invested
            FROM transactions
            WHERE user_id = ?
            GROUP BY symbol
        """, user_id)

        market_now = []

        for value in transactions:
            price_symbol = lookup(value["symbol"])
            market_now.append({"company": value["symbol"],
                               "price_now": price_symbol["price"]})

        return render_template("index.html", transactions=transactions, market_now=market_now, user_cash=user_cash)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    """Buy shares of stock"""
    if request.method == "POST":
        if request.form:
            symbol = request.form.get("symbol")
            quote = lookup(symbol)
            shares = request.form.get("shares")

            if shares.replace(".", "", 1).isdigit():
                share = int(shares)
                if quote is None:
                    return apology("The symbol not exist")
                elif shares < 1:
                    return apology("Insert a integer positive")

                user_id = session["user_id"]

                rows = db.execute("SELECT cash FROM users WHERE id=?", user_id)
                ammount_user = rows[0]["cash"]

                if ammount_user > (quote["price"] * shares):
                    value = ammount_user - quote["price"]
                    db.execute("UPDATE users SET cash=? WHERE id=?", value, user_id)
                    db.execute("INSERT INTO transactions (user_id, symbol, price, shares, type) VALUES(?,?,?,?,?)",
                               user_id, symbol, quote["price"], share, "BUY")
                    return redirect("/")
                else:
                    return apology("You don't have suficcient money")
            else:
                return apology("Insert correct number in shares")

    if request.method == "GET":
        return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user_id = session["user_id"]
    transactions = db.execute("""
        SELECT symbol, shares, price, type, timestamp
        FROM transactions
        WHERE user_id = ?
        ORDER BY timestamp DESC
    """, user_id)
    return render_template("history.html", transactions=transactions)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "GET":
        quotes = session.get("quotes", [])
        return render_template("quote.html", quotes=quotes)

    elif request.method == "POST":
        if request.form:
            quote = lookup(request.form.get("symbol"))
            if quote is not None:
                if "quotes" not in session:
                    session["quotes"] = []
                session["quotes"].append(quote)
                return render_template("quote.html", quotes=session["quotes"])
            else:
                return apology("Insert correct symbol")
        else:
            return apology("Without Symbol, please insert symbol")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "GET":
        return render_template("register.html")

    elif request.method == "POST":
        if request.form:
            username = request.form.get("username")
            password = request.form.get("password")
            confirmation = request.form.get("confirmation")

            if password == confirmation:
                try:
                    hash = generate_password_hash(password)
                    db.execute("INSERT INTO users (username, hash) VALUES(?,?)", username, hash)

                    return redirect("/")

                except ValueError:
                    return apology("User already exist")

            else:
                return apology("Confirmation different than password")

        else:
            return apology("Miss username or password")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    symbol_options = db.execute("""
            SELECT
            symbol,
            SUM(shares) AS sum_quotes,
            SUM(shares * price) AS total_invested
            FROM transactions
            WHERE user_id = ?
            GROUP BY symbol
        """, session["user_id"])

    if request.method == "GET":
        return render_template("sell.html", symbol_options=symbol_options)

    elif request.method == "POST":
        if request.form:
            company = request.form.get("company")
            shares = request.form.get("shares_quotes")

            if shares.replace(".", "", 1).isdigit():
                share = int(shares)
                quantity = 0
                for verify_company in symbol_options:
                    if verify_company["symbol"] == company:
                        quantity = verify_company["sum_quotes"]

                if quantity < shares:
                    return apology("Error shares is exceded")
                else:
                    market_value = lookup(company)["price"]
                    total = (market_value * shares)
                    db.execute("INSERT INTO transactions (user_id, symbol, shares, price, type) VALUES (?, ?, ?, ?, ?)",
                               session["user_id"], company, -shares, market_value, "SELL")
                    db.execute("UPDATE users SET cash = cash + ? WHERE id = ?",
                               total, session["user_id"])
                    return redirect("/")
            else:
                return apology("Insert correct number of shares")


@app.route("/money", methods=["POST"])
@login_required
def money():
    if request.form:
        number = request.form.get("add-money")
        if number.replace(".", "", 1).isdigit():
            value = float(number)
            db.execute("UPDATE users SET cash = cash + ? WHERE id = ?", value, session["user_id"])
            return redirect("/")
        else:
            return apology("Don't use letters")
