# Week 3 - Algorithms - CS50

An algorithm is a sequence of actions designed to solve problems efficiently, even as the problem size grows.

Linear Search
Sequential search through elements.

Binary Search
Picks the middle element, compares it, and decides whether to search the left or right half.
Requires a sorted list!

Big O Notation
Big O describes the upper bound of an algorithm’s complexity:


Complexity	Example
O(1)	Constant time
O(log n)	Binary Search
O(n)	Linear Search
O(n log n)	Efficient sorting
O(n²)	Nested loops
Ω (Omega) → Lower bound.

Θ (Theta) → Tight bound (upper and lower are the same).

📈 Execution time increases with input size according to these patterns.

<img src="../static/time.png" alt="Algorithms">

String Comparison and Use Case
Use strcmp (from <string.h>) to compare strings.

Example:

Initially, two separate arrays (names and phone numbers) were used.

Arrays had to stay aligned, which was fragile and error-prone.

Solution: Structs were introduced to store related data together more effectively.

# Data Structures & Sorting Algorithms

## Data Structures

A **data structure** is a container for various kinds of data (custom data types).  
It allows for **data encapsulation**, grouping related information and operations into a structured format.  
For example, a **person** can be a data structure with attributes (like name, age) and associated functions (like `introduce()`).
**Data structures** are ways of organizing and storing data efficiently. They can be **linear** or **non-linear**, depending on how the elements are organized and accessed.

---

## Linear Data Structures

### 1. **Array (Vector)**
- **Description**: Stores elements of the same type in contiguous memory positions.  
  Ideal for **fast access** to elements by **index**.
  
- **Use Case**: Storing fixed lists, such as a list of students or numbers.

### 2. **List**
- **Description**: Allows for dynamic addition or removal of elements, using **nodes** that point to the next element.  
  Ideal for situations where **insertion order** matters.

- **Use Case**: Linked lists in programs that require fast insertion and removal of elements.

### 3. **Stack**
- **Description**: Uses the **LIFO (Last In, First Out)** principle. The last element inserted is the first to be removed.  
  Ideal for **depth-first search** algorithms and function call management.
  
- **Use Case**: Implementing tree traversal algorithms and managing recursive function calls.

### 4. **Queue**
- **Description**: Uses the **FIFO (First In, First Out)** principle. The first element inserted is the first to be removed.  
  Ideal for **breadth-first search** algorithms and task management in operating systems.
  
- **Use Case**: Implementing print queues, where the first job sent to the printer is the first to be printed.

---

## Non-Linear Data Structures

### 1. **Tree**
- **Description**: A **hierarchical** structure, where each element (node) can have **zero or more children**.  
  Used for organizing data and efficient searching.
  
- **Use Case**: File systems, such as directories and subdirectories.

### 2. **Graph**
- **Description**: Represents a set of **vertices (or nodes)** and **edges**. Ideal for modeling **networks** and **relationships** between elements.
  
- **Use Case**: Modeling social networks, such as friend connections, or network routing.

### 3. **Hash Table**
- **Description**: Enables fast data retrieval using a **key**.  
  Ideal for storing and retrieving data quickly in databases.

- **Use Case**: Storing users and passwords, where the username is the key.

---

## Other Data Types

### 1. **Set**
- **Description**: Stores **unique, unordered** elements.
  
- **Use Case**: Storing tags or categories, where duplicate elements are not allowed.

### 2. **Dictionary (or Map)**
- **Description**: Stores **key-value** pairs, allowing fast access to data via the **key**.

- **Use Case**: Storing configuration settings, where the keys are options and the values are configurations.

### 3. **Composite (or Complex) Types**
- **Description**: Allows storing multiple values of different types, such as **structures** and **classes**.

- **Use Case**: Representing complex objects, such as a person (with name, age, address) in a system.

### 4. **Primitive Types**
- **Description**: Basic data types such as **integers**, **floats**, **characters**, **booleans**, etc.

- **Use Case**: Storing simple data like age, temperature, or a process state.


---

## Sorting Algorithms

Sorting algorithms are essential for organizing data efficiently. To determine the **Big O** notation of a sorting algorithm, its **mathematical formula** is analyzed, and the **dominant term** is used to define its complexity.

### Selection Sort

- **Description**:  
  Selection Sort divides the list into two parts: the sorted and unsorted sections.  
  In each iteration, it finds the smallest element in the unsorted section and swaps it with the first element of that section.  
  This process repeats until the entire list is sorted.

- **Time Complexity**: O(n²)  
  This makes it inefficient for large datasets.

---

### Bubble Sort

- **Description**:  
  Bubble Sort repeatedly swaps adjacent elements to sort the array.  
  It checks if adjacent elements are in the wrong order and swaps them.  
  The algorithm runs more efficiently if no swaps are made in a pass, which indicates that the array is already sorted.

- **Time Complexity**:  
  - **Worst Case**: O(n²)
  - **Best Case**: O(n) (when the array is already sorted or partially sorted).

---

## Recursion (Understanding Before Merge Sort)

**Recursion** is when a function calls itself to solve a problem by breaking it down into smaller instances until a **base case** is met.  
In a recursive program, execution follows a **stack-based approach**, meaning the remaining code is stored in the call stack and executed in reverse order once the base condition is reached.

---

## Merge Sort

**Merge Sort** is a **divide-and-conquer** algorithm that uses recursion and a binary tree structure to efficiently sort elements.  
It divides the dataset into smaller subarrays, sorts them, and then merges them back together in the correct order.

- **Time Complexity**: O(n log n)  
  This makes it an efficient algorithm for large datasets.
  
---

## Summary

- **Selection Sort**: O(n²) — inefficient for large datasets.
- **Bubble Sort**: O(n²) (worst case), O(n) (best case) — slightly more optimized with early exit.
- **Merge Sort**: O(n log n) — efficient, especially for large datasets.
- **Recursion**: Essential to understand for efficient algorithms like Merge Sort.