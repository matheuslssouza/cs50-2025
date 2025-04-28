# Week 2 - Arrays - CS50

## Compiler

A **compiler** converts source code into machine code — instructions that the computer can execute.

When you run **Clang** (a compiler), it goes through four phases:

1. **Preprocessing**  
   Directives like `#include` cause the contents of a header file to be copied into the source file.  
   Example:  
   Using `#include <stdio.h>` and calling `printf`, the preprocessor copies the function prototype from `stdio.h`.

2. **Compiling**  
   Translates C code into **assembly language**, a low-level language understandable by the processor.

3. **Assembling**  
   Converts assembly code into **machine code** (binary instructions).

4. **Linking**  
   Combines all necessary files, like `.c` source files and precompiled libraries, into a single executable.  
   Resolves function references and ensures the actual implementations are included.

---

## Reverse Engineering

- **Decompilation**  
  Converts machine code back into high-level code, but the result may differ from the original (due to optimizations and loss of variable names/comments).

- **Disassembly**  
  Converts machine code into **assembly language** — easier to analyze but still low-level.

> 🔍 Full reconstruction of the original source code is generally **not possible**.

---

## Debugging

The best way to fix broken programs is **not** using `printf`, but using a **debugger**.

- In CS50, `debug50` automates debugging.
- You must set **breakpoints** in your code.
- Always **initialize** numeric variables (e.g., `{0}`) to avoid **garbage memory** and unpredictable values.

---

## Arrays

- An **array** is a sequence of contiguous memory locations that store elements of the same data type.
- A **string** is an array of `char`.
- A **2D array** of strings is like a **matrix** (e.g., 2×2).

In `printf`, characters are printed sequentially until reaching the **null terminator** (`\0`), which has the ASCII value **zero**.

<img src="../static/array.jpg" alt="Arrays">

---

## Command-Line Arguments

Programs can receive arguments from the command line:

```c
int main(int argc, string argv[]);
```

argc (argument count) → Number of command-line arguments.

argv[] (argument vector) → Array of strings containing the arguments.

📌 argv[0] is always the program's name.
