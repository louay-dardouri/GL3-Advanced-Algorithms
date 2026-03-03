# AVL Tree: The Strictly Balanced BST

A standard Binary Search Tree (BST) offers an average time complexity of $O(\log n)$ for search, insertion, and deletion. However, BSTs have a critical weakness: if data is inserted in a sorted or nearly-sorted order, the tree "leans" and becomes a **degenerate tree** (essentially a linked list). In this state, performance collapses to $O(n)$.

The **AVL Tree** (named after inventors Adelson-Velsky and Landis) was the first data structure to solve this problem. It is a **self-balancing binary search tree** that guarantees logarithmic time complexity for all primary operations by ensuring the tree never becomes too skewed.

---

## 1. The Core Logic: The Balance Factor

The AVL tree maintains its balance by enforcing a strict rule: for every node in the tree, the heights of its left and right subtrees can differ by **at most one**.

To track this, we calculate the **Balance Factor (BF)** for every node:

$$
\text{BF} = \text{Height}(\text{LeftSubtree}) - \text{Height}(\text{RightSubtree})
$$

*   **$\text{BF} = 0$**: The node is perfectly balanced.
*   **$\text{BF} = 1$ or $-1$**: The node is slightly "heavy" on one side but still satisfies the AVL property.
*   **$|\text{BF}| > 1$**: The node is imbalanced and requires a **Rotation**.

---

## 2. Rebalancing via Rotations

When an insertion or deletion causes a node to have a Balance Factor of $2$ or $-2$, the tree performs one of four types of rotations to restore balance.

### Single Rotations
*   **Left-Left (LL) Case**: Occurs when a node is left-heavy and its left child is also left-heavy (a straight line).
    *   *Fix:* A single **Right Rotation**.
*   **Right-Right (RR) Case**: Occurs when a node is right-heavy and its right child is also right-heavy.
    *   *Fix:* A single **Left Rotation**.

### Double Rotations
*   **Left-Right (LR) Case**: Occurs when a node is left-heavy but its left child is right-heavy (a "Z" shape).
    *   *Fix:* A **Left Rotation** on the child, followed by a **Right Rotation** on the parent.
*   **Right-Left (RL) Case**: Occurs when a node is right-heavy but its right child is left-heavy.
    *   *Fix:* A **Right Rotation** on the child, followed by a **Left Rotation** on the parent.

---

## 3. Complexity Analysis

Because the tree is strictly balanced, the height $h$ is always kept in check relative to the number of nodes $n$. This guarantees the following:

| Operation | Average | Worst Case |
| :--- | :--- | :--- |
| **Search** | $O(\log n)$ | $O(\log n)$ |
| **Insert** | $O(\log n)$ | $O(\log n)$ |
| **Delete** | $O(\log n)$ | $O(\log n)$ |
| **Space** | $O(n)$ | $O(n)$ |

---

## 4. AVL vs. Red-Black Trees

While both are self-balancing BSTs, they are optimized for different operational workloads:

*   **AVL Trees** maintain a **strict balance**. This results in a "flatter" tree with a smaller maximum height, ensuring **optimal lookup speeds**. The trade-off is that insertions and deletions may require more frequent rotations to maintain this symmetry.
*   **Red-Black Trees** maintain a **looser balance**. They allow for more height variation, which results in **faster insertions and deletions** because the structure requires fewer rebalancing operations on average.

**Ideal Use Case:** AVL trees are best suited for applications where data is searched frequently but updated rarely (e.g., a static dictionary or a fixed lookup table). Red-Black trees are generally preferred for general-purpose libraries where insertions and deletions occur as often as searches.

---

## 5. How to Build and Run

This implementation includes a `Makefile` to automate compilation.

### Commands

1.  **Compile the Demo:**
    ```bash
    make
    ```
    Creates the `avl_demo` executable.

2.  **Run the Demo:**
    ```bash
    make run
    ```
    Builds and runs the `main.c` program to visualize tree operations.

3.  **Run Automated Tests:**
    ```bash
    make test
    ```
    Executes unit tests in `test_avl.c` using C `assert()` statements to verify logic.

4.  **Clean Files:**
    ```bash
    make clean
    ```
    Removes all executables and `.o` files.

---

## 6. Visualization

The `pretty_print` function uses box-drawing characters to show the tree structure and metadata (Height and Balance Factor) in the terminal:

```text
20 (h:3, bf:0)
├── 10 (h:1, bf:0)
└── 30 (h:2, bf:-1)
    ├── 25 (h:1, bf:0)
    └── 40 (h:1, bf:0)
```
