# Doubly Linked List Implementation in C++

A robust, custom implementation of a **Doubly Linked List** data structure in C++. This project demonstrates foundational data structure concepts, manual dynamic memory management (`new` and `delete`), pointer manipulation, and sequential data traversal.

##  Features

- **Bidirectional Traversal:** Nodes are linked using both `prev` and `next` pointers.
- **Dynamic Insertions:** Supports inserting elements at the beginning, at the end, or at any specific index position.
- **Safe Deletions:** Handles edge-case node removals (first, last, and middle) with robust boundary checking to prevent crashes.
- **No Memory Leaks:** Properly deallocates memory using `delete` when nodes are removed or when the list lifecycle ends.

---

## 📁 File Structure

- `Node.h` - Defines the structural blueprint of an individual data node.
- `LinkedList.h` - Contains the core logic, state management, and operational methods for the list.
- `main.cpp` - The test driver that executes and verifies the list functions.

---

## 🛠️ Operations Supported

### Insertions
- `insertFirst()`: Prepends a node to the start of the list.
- `insertLast()`: Appends a node to the end of the list.
- `insertMid()`: Inserts a node at a user-specified 1-based index position.

### Deletions
- `deleteFirst()`: Removes and cleans up the first node.
- `deleteLast()`: Removes and cleans up the final node.
- `deleteMiddle(int pos)`: Isolates, detaches, and frees a node at a targeted position.

### Utility & Diagnostics
- `nodeCounter()`: Dynamically calculates and returns the current total node count.
- `printList()`: Iterates through the list sequentially and prints the dataset to the console.

---

## 💻 Getting Started

### Prerequisites
You need a C++ compiler installed on your system (such as `g++` from GCC or Clang).

### Compilation
Open your terminal in the project directory and run the following command to compile the project files:

```bash
g++ main.cpp -o doubly_linked_list
```

### Execution
Run the compiled executable:

```bash
./doubly_linked_list
```
