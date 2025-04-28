import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        # TODO: Add the user's entry into the database
        if request.form:

           name = request.form.get("name")
           month = int(request.form.get("month"))
           day = int(request.form.get("day"))

           if ( (name.isalpha()) and (month >= 1 and month <= 12) and (day >= 1 and day <= 31)):
            db.execute("INSERT INTO birthdays (name,month,day) VALUES (?,?,?)", name,month,day)

        return redirect("/")

    else:
        data = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", data = data)


