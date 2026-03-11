#ifndef HEAP_H
#define HEAP_H

typedef struct {
    int *data;
    int size;
    int capacity;
} heap_t;

typedef heap_t *Heap;

/* Public API */
heap_t *heap_create(int capacity);
void heap_insert(Heap h, int key);
int heap_extract_max(Heap h);
int heap_peek(Heap h);
void heap_free(Heap h);
void heap_build(Heap h, int *arr, int n);
void heap_sort(int *arr, int n);

/* Visualization */
void heap_print(Heap h);

#endif
