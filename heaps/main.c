#include "heap.h"
#include <stdio.h>

int main() {
    printf("=== Heap Manual Insertion Demo ===\n");
    Heap h = heap_create(10);
    heap_insert(h, 10);
    heap_insert(h, 20);
    heap_insert(h, 5);
    heap_insert(h, 30);
    heap_insert(h, 15);

    heap_print(h);
    printf("Extracted Max: %d\n", heap_extract_max(h));
    heap_print(h);
    heap_free(h);

    printf("\n=== Heapsort Demo ===\n");
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    heap_sort(arr, n);

    printf("Sorted array:   ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
