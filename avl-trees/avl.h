#ifndef AVL_H
#define AVL_H

typedef struct avl_node {
    int key;
    int height; // balacne can be calculated using height of subtrees
                // BF = height(left) - height(right)
    struct avl_node *left;
    struct avl_node *right;
} avl_node_t;

typedef avl_node_t *Avl;

/* Creates a new AVL tree node with the given key and returns a pointer to it.
 */
Avl avl_create_node(int key);

/*
 * Utility function to print the tree structure in a pretty way
 */
void pretty_print(Avl root);

/*
 * Inserts a key into the AVL tree and returns the new root after balancing.
 * If the key already exists, it does not insert and returns the original root.
 */
Avl avl_insert(Avl root, int key);

/* Deletes a key from the AVL tree and returns the new root after balancing.
 * If the key does not exist, it does not delete and returns the original root.
 */
Avl avl_delete(Avl root, int key);

/* Searches for a key in the AVL tree and returns a pointer to the node
 * containing the key. If the key is not found, it returns NULL.
 */
Avl avl_search(Avl root, int key);

/* Frees all nodes in the AVL tree to prevent memory leaks.
 */
void avl_free(Avl root);

#endif
