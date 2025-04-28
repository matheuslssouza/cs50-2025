# Data Structures

**Data structures** are ways of organizing and storing data efficiently. They can be **linear** or **non-linear**, depending on how the elements are organized and accessed.

---

## Linear Data Structures

### 1. **Queue**
- **Description**: A queue is a data structure that follows the **FIFO (First In, First Out)** principle. The first element inserted is the first one to be removed.  
  Ideal for algorithms that require **first-come, first-served** processing.

- **Example of use**: A supermarket line or a print queue, where the first customer or document is served first.

---

### 2. **Stack**
- **Description**: A stack is a data structure that follows the **LIFO (Last In, First Out)** principle. The last element inserted is the first one to be removed.  
  Ideal for algorithms that require **depth-first processing** and function call handling.

- **Example of use**: Function call stacks in recursive algorithms or undo features in text editors.

---

### 3. **Array Resizing**
- **Description**: When trying to add a new element to a fixed-size array, a new array must be created with a larger capacity, copying the existing elements into it.  
  This process can be inefficient in terms of time and memory usage. Allocating extra memory might result in wasted space if the additional capacity is never fully utilized.

- **Alternative**: Linked lists can be used instead of arrays for dynamic memory management.

---

### 4. **Linked List**
- **Description**: A linked list is a data structure that uses pointers. Each node in the list contains a value and a pointer to the next node.  
  The last node in the list typically stores a **NULL** pointer to indicate the end of the sequence.

- **Example of use**: Dynamic memory allocation where elements need to be inserted or removed frequently without needing contiguous memory space.

```c
typedef struct node {
    int value;
    struct node *next;
} node;
```

## Non-Linear Data Structures

1. Binary Search Tree (BST)
Description: A Binary Search Tree (BST) is a hierarchical data structure where each node has at most two child nodes (left and right). The left child contains values smaller than the parent, and the right child contains values greater than the parent.
Ideal for searching, inserting, and deleting data efficiently.

Example of use: A binary tree used in database indexing or searching algorithms.

```c
typedef struct node {
    int number;
    struct node *left;
    struct node *right;
} node;
```
---

2. Dictionaries
Description: A dictionary is a data structure that stores key-value pairs, where each key is associated with a specific value.
It is conceptually represented as a two-column table: one for the key (e.g., a word) and the other for the value (e.g., its definition).

Example of use: Storing data such as a word and its definition, or mapping user IDs to user profiles.

---

3. Hash Tables
Description: Hash tables use hash functions to map keys to specific locations in an array, optimizing lookup efficiency.
A hash function takes an input (key) and produces a numerical output (hash value), which determines where the key-value pair will be stored in the table.

Example of use: A hash table used to implement a dictionary, where words (keys) map to their definitions (values).

Note: Although hash tables are often considered O(1) for insertion, search, and deletion in average cases, collisions can lead to worst-case O(n) complexity if multiple keys hash to the same location.









