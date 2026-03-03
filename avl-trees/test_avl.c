#include "avl.h"
#include <assert.h>
#include <stdio.h>

void test_basic_insertion() {
    printf("Running test_basic_insertion... ");
    Avl root = NULL;
    root = avl_insert(root, 10);
    root = avl_insert(root, 20);
    root = avl_insert(root, 30); // Should trigger a Left Rotation

    // In a balanced AVL, 20 should be the root
    assert(root != NULL);
    assert(root->key == 20);
    assert(root->left->key == 10);
    assert(root->right->key == 30);

    avl_free(root);
    printf("PASSED\n");
}

void test_deletion() {
    printf("Running test_deletion... ");
    Avl root = NULL;
    root = avl_insert(root, 10);
    root = avl_insert(root, 5);
    root = avl_insert(root, 15);

    root = avl_delete(root, 10); // Delete root with 2 children

    assert(root->key == 15 || root->key == 5);
    avl_free(root);
    printf("PASSED\n");
}

int main() {
    printf("=== Starting AVL Unit Tests ===\n");
    test_basic_insertion();
    test_deletion();
    printf("=== All Tests Passed! ===\n");
    return 0;
}
