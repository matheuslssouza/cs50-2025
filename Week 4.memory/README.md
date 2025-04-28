# Week 4 - Memory

---

## Pixel Art

In **Pixel Art**, colors are represented using the **RGB** system, which expresses the amount of **red**, **green**, and **blue** in a pixel. Each color channel can have a value between 0 and 255.

### Hexadecimal Representation
The numerical representation for colors in RGB is `(255, 255, 255)`, but we use the **hexadecimal system** to represent colors more efficiently. The hexadecimal system uses values from **0 to 9** and **A to F**, where **F** represents 15 in decimal.

For example:
- **Red** → `#FF0000`
- **Green** → `#00FF00`
- **Blue** → `#0000FF`

In hexadecimal, we use the prefix `0x` to avoid misinterpretation. For instance, `0x10` in hexadecimal equals **16** in decimal, not **10**.

---

## Pointers

In **C**, pointers are variables that store the memory address of another variable. There are two important symbols:
- **`*` (dereference operator)** → Accesses the value stored at a memory address.
- **`&` (address-of operator)** → Retrieves the memory address of a variable.

### Example:
```c
int n = 10;
int *p = &n;
```

In this example:

Using p gives us the address of n.

Using *p accesses the value stored at that address (10).

Pointers typically occupy 8 bytes on modern 64-bit systems.

--- 

**Pointers and Strings**
A string in C is simply an array of characters, and a string variable is actually a pointer to the first character of that array. C strings are null-terminated, meaning they end with the special character \0.

```c
char *word = "Hi!";
The CS50 library defines an alias for char* as string using typedef:
```

```c
typedef char *string;
```
This makes string a more readable alias for char*.

--- 

**Pointer Arithmetic**
Pointer arithmetic involves performing operations on memory addresses, such as adding or subtracting offsets. For example, when working with arrays, pointer arithmetic is used:

```c
int numbers[] = {1, 2, 3};
int *ptr = numbers;  // Equivalent to &numbers[0]
```
Accessing numbers[i] is the same as *(numbers + i) due to pointer arithmetic. The function strcmp (from the C standard library) uses pointer arithmetic to compare strings by dereferencing pointers and checking each character sequentially.

---

**Memory Allocation**
When modifying a char*, memory must be manually allocated using functions like malloc:

```c
char *copy = malloc(strlen(original) + 1);
strcpy(copy, original);
```
To free allocated memory, use free(copy). If free is not called, the memory remains allocated, causing a memory leak.

---

**Debugging and Memory Management**
To track memory issues, tools like Valgrind can be used:

```bash
valgrind ./program_name
```
This helps detect memory leaks and errors in C programs.

---

**Passing by Value vs. Passing by Reference**
In C, when you pass a variable to a function, it is passed by value, meaning a copy of the variable is created. Any modifications inside the function do not affect the original variable.

If you want the function to modify the original variable, you need to pass it by reference, which means passing the memory address. This is done using pointers.

```c
void swap(int *a, int *b);
When calling the function:
```

```c
int x = 10, y = 20;
swap(&x, &y);
```
Inside the function, dereferencing *a and *b allows direct modification of the original variables.

---

**Stack and Heap Memory**
Memory in C is managed in two main regions:

*Stack:* Stores local variables and function calls. Memory is automatically allocated and deallocated when functions are called and return. Excessive function calls or deep recursion can cause a stack overflow, where the program exceeds allocated stack memory.

*Heap:* Used for dynamic memory allocation (e.g., malloc). Unlike stack memory, memory allocated on the heap must be manually deallocated using free. Failure to deallocate leads to memory leaks.

Excessive heap allocation without proper deallocation can cause heap exhaustion, but this is not the same as a stack overflow.

---

**Scanf and Memory Safety**
The scanf function reads user input and stores it in a variable. However, when reading a string (char *), you must ensure the pointer has valid memory allocation to avoid undefined behavior or segmentation faults.

Correct Usage:
```c
char name[50];  // Allocates space for 50 characters
scanf("%49s", name);  // Prevents buffer overflow
```
If using a pointer (char *), allocate memory before using scanf:

```c
char *name = malloc(50 * sizeof(char));
scanf("%49s", name);
```
Failing to allocate memory before using scanf can cause the program to access an invalid memory address.

---

**File Input and Output**
C provides functions to work with files. The FILE type handles file operations. To open a file, use fopen:

```c
FILE *file = fopen("example.txt", "r");
The second argument specifies the mode:

"r" – Read

"w" – Write (overwrites existing content)

"a" – Append

"rb", "wb", "ab" – Binary modes
```

After opening a file, you can use functions like fprintf (for writing) and fscanf (for reading). When finished, always close the file:

```c
fclose(file);
```
For efficient file copying, process the file in chunks (buffers) instead of loading the entire file into memory at once.

**Important Note on Structs and File Formats**
Remember, a file is just a sequence of bytes on disk. However, these bytes are usually ordered to represent different things in the file. File formats exist because standards define what each byte means. You could read a file into memory as a large array of bytes, but structuring them with named fields makes it easier to access and understand.

For example, in bmp.h, we use structs to map the bytes of a BMP file into readable fields, making it easier to process the data.
