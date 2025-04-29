# Week 1 - Introduction to Computer Science - CS50

> Computers only understand zeros and ones — the binary system — which means two possible states.

A **bit** stands for **binary digit**.  
Inside all electronic devices, there are countless tiny "light switches" called **transistors**, which can be either **on** or **off**. This is how information is stored.

The more bits we use, the more information we can store.  
A standard was created for organization:

- **1 byte = 8 bits**
- With 8 bits, we can represent values from **0 to 255** (256 possibilities).

---

## How Computers Represent Letters with Bits

To represent text, the **ASCII** pattern was created, where each number corresponds to a letter.

> 🛑 ASCII only covers the English alphabet.

For languages with more characters, **UNICODE** was developed — a standard that supports virtually all languages.

<img src="../static/ascii.jpg" alt="Ascii">
---

## Representing Colors with Bytes

Colors are represented using **RGB notation**, consisting of **three bytes**:

- **R (Red)** 
- **G (Green)**
- **B (Blue)**

Each byte defines the intensity of the corresponding color.  
Example:

```text
R: 73, G: 75, B: 33 → A shade of yellow
```

The Role of Software
When we write software, we translate bits into meaningful actions:

```text
Input → Software (Algorithm) → Output
```

An algorithm is a set of steps to solve a problem.
Some algorithms can be slow — and finding better implementations can make a huge difference in performance.

**Summary**
Computers use binary to represent information.

Bytes group bits for better organization.

ASCII and UNICODE allow representing text.

RGB uses bytes to define colors.

Software bridges input, processing, and output through algorithms.

