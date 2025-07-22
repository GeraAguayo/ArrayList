# ArrayList (C++ Template Class)

A simple **dynamic array (ArrayList)** implementation in C++ using templates.  
It supports automatic resizing, element insertion, removal, and basic access methods.

---

## **Features**
✅ **Template-based** – works with any data type (`int`, `float`, `std::string`, custom objects, etc.)  
✅ **Automatic resizing** – doubles capacity when full  
✅ **Basic operations** – push, remove, access elements  
✅ **Easy to use** – simple API similar to Java's `ArrayList` or Python's `list`  

---

## **Installation & Usage**

### **1. Add `ArrayList.h` to your project**
Place `ArrayList.h` in your project folder and include it in your code:

```cpp
#include "ArrayList.h"
```

### **2. Compile & Run**
Example compilation using `g++`:

```bash
g++ main.cpp -o main
./main
```

---

## **Example**

```cpp
#include "ArrayList.h"
#include <iostream>

int main() {
    ArrayList<int> arr;          // Default constructor (capacity = 2)
    arr.push(10);
    arr.push(20);
    arr.push(30);                // Triggers resizing

    std::cout << "Length: " << arr.len() << std::endl;       // Output: 3
    std::cout << "Capacity: " << arr.max_len() << std::endl; // Output: 4

    std::cout << "Element at index 1: " << arr.at(1) << std::endl; // Output: 20

    arr.remove(1);               // Removes value 20
    std::cout << "After removal, length: " << arr.len() << std::endl; // Output: 2
}
```

### **Sample Output**

```
Empty constructor - ArrayList with 2 created at 0x7ffee5e82c
Resizing array
Length: 3
Capacity: 4
Element at index 1: 20
After removal, length: 2
ArrayList destroyed
```

---

## **Public Methods Overview**

| Method | Description |
|--------|-------------|
| `void push(T value)` | Adds a new element to the list. Automatically resizes if capacity is exceeded. |
| `void remove(int index)` | Removes the element at the specified index, shifting remaining elements left. |
| `size_t len()` | Returns the current number of elements stored. |
| `size_t max_len()` | Returns the current capacity (maximum number of elements before resizing). |
| `T at(int index)` | Returns the element at the specified index. *(No bounds checking yet)* |

---
