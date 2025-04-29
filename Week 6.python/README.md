
# 🐍 Introduction to Python

### 🧠 Key Concepts
Python is a user-friendly programming language that abstracts many low-level concepts. Additionally, it is an interpreted language, whereas C is a compiled language, meaning that C code is translated into machine code (binary: 0s and 1s) before execution.

To execute a Python script, one would use the command:

```bash
python hello.py
```

Here, the word `python` at the beginning of the command simply refers to the interpreter.

One of Python’s key advantages is its speed of development and simplicity compared to C. For example, exercises that required approximately 110 lines of code in C can often be significantly reduced to just a few lines in Python due to the availability of libraries (also referred to as modules or packages) that already implement various functionalities.

---

# 📦 Importing Modules

Python allows for the importation of an entire module or a specific function within a module. Examples:

✅ Importing an entire module:
```python
import module_name
```

✅ Importing a specific function from a module:
```python
from module_name import specific_function
```

---

# 🏷️ Named Parameters

Python functions support named parameters, meaning that the order of arguments does not necessarily matter, unlike in C. This allows arguments to be passed explicitly by name. Example:

```python
print("hello, world", end="!
")
```

In this case, `end=""` is an argument explicitly set by name.

---

# 💾 Memory Management and Data Types

A key aspect of Python is its flexibility in handling different data types, including primitive types. This is possible because Python stores data as objects in memory, and variables act as references to these objects. Python employs dynamic memory allocation, which results in greater memory consumption compared to C.

Python provides a limited number of built-in data types, including:

- **Primitive types:** `int`, `str`, `bool`, and `float`
- **Data structures:** Python includes pre-implemented structures such as `range`, `list` (similar to a linked list in C), `tuple`, `dict`, and `set`.

By default, input received in Python is stored as a **string**, requiring conversion to the desired type when necessary.

---

# 🧹 Code Formatting and Syntax

Python enforces strict formatting rules regarding indentation, which is used to define code blocks instead of braces `{}` as in C. Misaligned indentation will result in a syntax error.

For example:

```python
if x < y:
    print("x is smaller than y")
```

---

# 🔀 Conditional Statements

Python supports the following conditional statements:

```python
if condition:
elif condition:
else:
```

Logical operators:
- `||` (OR in C) → `or` in Python  
- `&&` (AND in C) → `and` in Python

Conditions with collections:

```python
if x in ["Y", "y"]:
    print("Confirmed")
```

---

# 🔁 Loops in Python

Python supports both `for` and `while` loops. Unlike C, Python loops do not require parentheses around conditions or braces `{}` to define their scope.

✅ `for` Loop Example:

```python
for element in data_structure:
    function()
```

✅ `while` Loop Example:

```python
count = 0
while count < 5:
    print(count)
    count += 1
```

Python allows iteration over lists, tuples, dictionaries, and strings. It also supports `break` and `continue`.

---

# 🧩 Function Definitions and Execution

Python does not require a `main()` function, but defining one is considered good practice.

Example:

```python
def main():
    meow(3)

def meow(n):
    for i in range(n):  
        print("Meow")

main()
```

If a function is called before being defined, Python raises an error, similar to missing prototypes in C.

---

# 🎯 Floating-Point Precision and Truncation

Python automatically converts integers to floating-point numbers when necessary. However, due to limited precision, small errors may occur. Unlike C, Python uses dynamic memory allocation, which avoids memory overflow issues.

---

# ⚠️ Exception Handling

Unlike C, which uses return codes (e.g., `return 0`, `return 1`), Python uses **exceptions**. If an error occurs, Python terminates execution unless handled using `try` and `except`.

Example:

```python
try:
    x = int(input("Enter a number: "))
except ValueError:
    print("Invalid input")
```

---

# 🧮 Lists in Python

Python lists are dynamically resizable arrays, similar to linked lists in C.

Common list functions:
- `len(list)` – Returns the length of a list
- `append(value)` – Adds a value to the end of a list

Check if an item exists:

```python
if name in names:
    print("Found!")
```

---

# 🗂️ Dictionaries in Python

Dictionaries store key-value pairs and can be defined in multiple ways.

✅ List of dictionaries:

```python
people = [
    {"name": "Alice", "age": 25},
    {"name": "Bob", "age": 30}
]
```

✅ Dictionary as key-value pairs:

```python
people = {
    "Alice": 25,
    "Bob": 30
}
```

---

# 💻 Command-Line Arguments with `sys`

Python supports command-line argument parsing like `argc` and `argv` in C.

Example:

```python
from sys import argv
print(argv[1])  # Access the first argument
```

---

# 📥 Importing Modules (Again)

✅ Importing an entire module:
```python
import module_name
module_name.function()
```

✅ Importing a specific function:
```python
from module_name import function_name
function_name()
```

---

# 📂 File Handling

Python simplifies file handling using `with open(...)` syntax:

```python
with open("file.txt", "r") as file:
    content = file.read()
```

This ensures the file is properly closed after reading or writing.

---
