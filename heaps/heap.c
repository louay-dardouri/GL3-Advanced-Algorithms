#include "heap.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>

/* --- Private Helpers --- */

static void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

static void shift_up(Heap h, int idx) {
    while (idx > 0) {
        int p_idx = (idx - 1) / 2;
        if (h->data[idx] > h->data[p_idx]) {
            swap(&h->data[idx], &h->data[p_idx]);
            idx = p_idx;
        } else {
            break;
        }
    }
}

static void shift_down(Heap h, int idx) {
    int max_idx = idx;
    int l_idx = idx * 2 + 1;
    int r_idx = idx * 2 + 2;

    if (h->size > l_idx && h->data[l_idx] > h->data[max_idx]) {
        max_idx = l_idx;
    }

    if (h->size > r_idx && h->data[r_idx] > h->data[max_idx]) {
        max_idx = r_idx;
    }

    if (idx != max_idx) {
        swap(&h->data[max_idx], &h->data[idx]);
        shift_down(h, max_idx);
    }
}

/* --- Public Functions --- */

Heap heap_create(int capacity) {
    Heap h = (Heap)malloc(sizeof(heap_t));
    if (!h) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    h->data = (int *)malloc(capacity * sizeof(int));
    if (!h->data) {
        fprintf(stderr, "Error: Memory allocation failed\n");
        exit(1);
    }

    h->size = 0;
    h->capacity = capacity;

    return h;
}

void heap_insert(Heap h, int key) {
    if (h->size == h->capacity) {
        // TODO: fully implement dynamic array for this
        fprintf(stderr, "Error: Maximum Capacity reached, (dynamic size not "
                        "yet implemented)\n");
        exit(1);
    }

    h->data[h->size++] = key;
    shift_up(h, h->size - 1);
}

int heap_peek(Heap h) {
    return h->data[0];
}

int heap_extract_max(Heap h) {
    if (h->size <= 0) {
        fprintf(stderr, "Error: Empty heap\n");
        exit(1);
    }
    int root = h->data[0];
    swap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    shift_down(h, 0);
    return root;
}

void heap_build(Heap h, int *arr, int n) {
    h->capacity = n;
    h->data = arr;
    h->size = n;

    for (int i = (h->size / 2) - 1; i >= 0; i--) {
        shift_down(h, i);
    }
}

void heap_sort(int *arr, int n) {
    heap_t h;
    h.capacity = n;
    h.data = arr;
    h.size = 0;

    heap_build(&h, arr, n);

    for (int i = 0; i < n; i++) {
        heap_extract_max(&h);
    }
}

void heap_free(heap_t *h) {
    free(h->data);
    free(h);
}

// A simple horizontal visualizer for the heap array as a tree
void heap_print_internal(heap_t *h, int idx, int level) {
    if (idx >= h->size)
        return;

    heap_print_internal(h, 2 * idx + 2, level + 1);

    for (int i = 0; i < level; i++)
        printf("    ");
    printf("%d\n", h->data[idx]);

    heap_print_internal(h, 2 * idx + 1, level + 1);
}

void heap_print(heap_t *h) {
    printf("--- Heap Structure ---\n");
    heap_print_internal(h, 0, 0);
    printf("----------------------\n");
}
