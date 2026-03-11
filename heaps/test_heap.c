#include "heap.h"
#include <assert.h>
#include <stdio.h>

void test_insert_max() {
    printf("Testing Heap Property... ");
    Heap h = heap_create(10);
    heap_insert(h, 10);
    heap_insert(h, 50);
    heap_insert(h, 20);

    // Max should be at root
    assert(heap_peek(h) == 50);

    heap_insert(h, 100);
    assert(heap_peek(h) == 100);

    heap_free(h);
    printf("PASSED\n");
}

void test_sort() {
    printf("Testing Heapsort... ");
    int arr[] = {3, 1, 4, 1, 5, 9, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, n);

    for (int i = 0; i < n - 1; i++) {
        assert(arr[i] <= arr[i + 1]);
    }
    printf("PASSED\n");
}

int main() {
    printf("--- Running Heap Tests ---\n");
    test_insert_max();
    test_sort();
    printf("--- All Tests Passed! ---\n");
    return 0;
}
