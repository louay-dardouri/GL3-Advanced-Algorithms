#include "avl.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* --- Private Helper Functions --- */
static int height(Avl root);
static int max(int a, int b);
static int balance(Avl root);
static Avl min_value_node(Avl node);
static void print_avl_internal(Avl root, char *prefix, int is_left);
static Avl rebalance(Avl root);
static Avl right_rotate(Avl x);
static Avl left_rotate(Avl x);

/* --- Public Function Definitions --- */

Avl create_node(int key) {
    Avl new_node = (Avl)malloc(sizeof(avl_node_t));
    if (!new_node) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }
    new_node->key = key;
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->height = 1;
    return new_node;
}

Avl avl_insert(Avl root, int key) {
    if (root == NULL) {
        return create_node(key);
    }

    if (key < root->key) {
        root->left = avl_insert(root->left, key);
    } else if (key > root->key) {
        root->right = avl_insert(root->right, key);
    } else {
        return root;
    }

    return rebalance(root);
}

Avl avl_search(Avl root, int key) {
    if (root == NULL || root->key == key)
        return root;

    if (key > root->key)
        return avl_search(root->right, key);
    return avl_search(root->left, key);
}

void avl_free(Avl root) {
    if (root != NULL) {
        avl_free(root->left);
        avl_free(root->right);
        free(root);
    }
}

Avl avl_delete(Avl root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key > root->key) {
        root->right = avl_delete(root->right, key);
    } else if (key < root->key) {
        root->left = avl_delete(root->left, key);
    } else {
        // this is the node to be deleted

        // Node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {

            Avl tmp = root->right ? root->right : root->left;

            // no child
            if (tmp == NULL) {
                tmp = root;
                root = NULL;
            } else { // one child
                *root = *tmp;
            }
            free(tmp);
        } else {
            /* Node with 2 children
             * find the inorder successor (smallest key in right subtree)
             * and swap it with root then delete it from the right subtree
             */
            Avl tmp = min_value_node(root->right);
            root->key = tmp->key;

            root->right = avl_delete(root->right, tmp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    return rebalance(root);
}

void pretty_print(Avl root) {
    if (root == NULL) {
        printf("Empty Tree\n");
        return;
    }
    printf("%d (h:%d, bf:%d)\n", root->key, root->height, balance(root));

    char prefix[256] = "";
    print_avl_internal(root->left, prefix, 1);
    print_avl_internal(root->right, prefix, 0);
}

/* --- Private Function Definitions --- */
static int height(Avl root) {
    return root ? root->height : 0;
}

static int max(int a, int b) {
    return (a > b) ? a : b;
}

static int balance(Avl root) {
    return root ? height(root->left) - height(root->right) : 0;
}

/* Utility function to find the node with the minimum key in the subtree rooted
 * at node. This is used during deletion to find the in-order successor.
 */
static Avl min_value_node(Avl root) {
    Avl curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }
    return curr;
}

static Avl left_rotate(Avl y) {
    if (y == NULL || y->right == NULL) {
        return y;
    }

    Avl new_root = y->right;
    y->right = new_root->left;
    new_root->left = y;

    y->height = 1 + max(height(y->left), height(y->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}

/* Utility function to rebalance the AVL tree after insertion or deletion.
 * It checks the balance factor of the node and performs the necessary
 * rotations to maintain the AVL property.
 */
static Avl rebalance(Avl root) {
    root->height = 1 + max(height(root->left), height(root->right));

    int bf = balance(root);

    // Left heavy
    if (bf > 1) {

        // If child is right heavy, do a double rotation
        if (balance(root->left) < 0) {
            root->left = left_rotate(root->left);
        }
        return right_rotate(root);
    }

    // Right heavy
    if (bf < -1) {

        // If child is left heavy, do a double rotation
        if (balance(root->right) > 0) {
            root->right = right_rotate(root->right);
        }
        return left_rotate(root);
    }

    return root;
}

/**
 * Internal helper to print the tree with branches.
 * @param root   Current node
 * @param prefix String containing the "pipes" from previous levels
 * @param is_left Boolean (1 if this node is a left child, 0 otherwise)
 */
static void print_avl_internal(Avl root, char *prefix, int is_left) {
    if (root == NULL)
        return;

    printf("%s", prefix);
    printf(is_left ? "├── " : "└── ");
    printf("%d (h:%d, bf:%d)\n", root->key, root->height, balance(root));

    // Prepare the prefix for the next level
    char new_prefix[256];
    // size_t len = strlen(prefix);
    strcpy(new_prefix, prefix);

    // If we are a left child, our siblings/descendants need a vertical line
    // If we are a right child (the last child), we just need spaces
    strcat(new_prefix, is_left ? "│   " : "    ");

    // Recurse: In this style, we show Left then Right
    print_avl_internal(root->left, new_prefix, 1);
    print_avl_internal(root->right, new_prefix, 0);
}

static Avl right_rotate(Avl y) {
    if (y == NULL || y->left == NULL) {
        return y;
    }

    Avl new_root = y->left;
    y->left = new_root->right;
    new_root->right = y;

    y->height = 1 + max(height(y->left), height(y->right));
    new_root->height = 1 + max(height(new_root->left), height(new_root->right));

    return new_root;
}
