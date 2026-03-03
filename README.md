# GL3: Advanced Algorithms

This repository contains C implementations of advanced data structures and algorithms covered in the **GL3** curriculum.
## Repository Roadmap
*   [x] **AVL Trees**: Self-balancing BST with $O(\log n)$ guarantees.
*   [ ] **Binary Heaps**: Efficient priority queue implementation using array-based trees.
*   [ ] **B-Trees**: Multi-way search trees optimized for external storage/disk access.
*   [ ] **Complexity Analysis**: LaTeX-formatted Big-O proofs for each structure.

## Technical Highlights
*   **Internal Linkage**: I used `static` functions for internal logic (like tree rotations and rebalancing). This keeps the public header files clean and ensures proper encapsulation by hiding implementation details from the user.
*   **Automated Build System**: Each module is self-contained with its own **automated Makefile**, supporting `make` for building, `make run` for demos, and `make clean` for maintenance.
*   **Unit Testing**: Reliability is verified through automated tests using `assert.h`. You can run these using `make test` within each directory to ensure the logic holds up under different edge cases.
*   **CLI-Based Rendering**: To make debugging and learning easier, I've included CLI visualizers that render the tree and heap structures directly in the terminal using box-drawing characters.

## Tech Stack
*   **Language**: Pure C
*   **Build System**: Modular Makefiles
*   **Testing**: Unit testing via `assert.h`
*   **Visualization**: Custom CLI-based structure rendering

---
*Created for the GL3 Advanced Algorithms course.*
