#include "avl.h"
#include <stdio.h>

int main() {
    Avl tree = NULL;
    int keys[] = {10, 20, 30,
                  40, 50, 25}; // This will trigger several rotations
    int n = sizeof(keys) / sizeof(keys[0]);

    printf("Inserting nodes...\n");
    for (int i = 0; i < n; i++) {
        tree = avl_insert(tree, keys[i]);
    }

    printf("Final Tree Structure:\n");
    pretty_print(tree);

    printf("\nDeleting 30...\n");
    tree = avl_delete(tree, 30);
    pretty_print(tree);

    avl_free(tree);
    return 0;
}
