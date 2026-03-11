# Binary Heap (Max-Heap)

A **Binary Heap** is a complete binary tree that satisfies the **Heap Property**: in a Max-Heap, for any given node $i$, the value of $i$ is greater than or equal to the values of its children.

Unlike AVL trees, heaps are physically stored in an **array**, which makes them extremely memory-efficient as they don't require pointers for child nodes.

## 1. Array Representation
The tree-to-array mapping follows these formulas for a node at index $i$:
*   $\text{Parent}(i) = \lfloor (i - 1) / 2 \rfloor$
*   $\text{Left Child}(i) = 2i + 1$
*   $\text{Right Child}(i) = 2i + 2$

## 2. Key Operations
*   **Sift-Up (Bubble Up)**: Used during insertion. If a child is larger than its parent, they are swapped until the property is restored.
*   **Sift-Down (Heapify)**: Used during deletion. If a parent is smaller than its children, it is swapped with the larger child until it "sinks" to the correct position.
*   **Build-Heap**: Converting an unordered array into a heap. While it looks like $O(n \log n)$, mathematical analysis proves this operation is actually **$O(n)$**.

## 3. Complexity Analysis

| Operation | Complexity | Note |
| :--- | :--- | :--- |
| **Peek** (Max) | $O(1)$ | Root is always at index 0. |
| **Insert** | $O(\log n)$ | Sifts up the height of the tree. |
| **Extract Max** | $O(\log n)$ | Sifts down the height of the tree. |
| **Build-Heap** | $O(n)$ | More efficient than $n$ insertions. |

## 4. Why use a Heap?
Heaps are the primary data structure used to implement **Priority Queues**. They are essential for:
1. **Heapsort**: An $O(n \log n)$ in-place sorting algorithm.
2. **Graph Algorithms**: Dijkstra's Shortest Path and Prim's MST (using a Min-Heap).
3. **Operating Systems**: Task scheduling and interrupt handling.

## 5. Build and Run
Inside this directory, use the following commands:
*   `make`: Compiles the heap demo.
*   `make run`: Runs the demo showing insertion and $O(n)$ heap construction.
*   `make test`: Runs unit tests for heap properties.

## ⚠️ Implementation Notes & Limitations
This is a standard educational implementation of a Binary Heap. Please note:
*   **Fixed Capacity**: Current insertion does not support dynamic resizing (`realloc`). If the heap reaches capacity, it will exit.
*   **Memory Ownership**: The `heap_sort` and `heap_build` functions operate **in-place** on the provided array to maintain $O(1)$ space complexity. Users should ensure the array passed to these functions is not `NULL`.
*   **Data Type**: This implementation is specialized for `int`. For generic types, function pointers for comparisons would be required.
