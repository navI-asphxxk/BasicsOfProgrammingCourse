#include "vector.h"
#include <stdio.h>
#include <malloc.h>


vector createVector(size_t n) {
    int *data = (int *) malloc(sizeof(int) * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vector) {data, 0, n};
}

void reserve(vector *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (int *) realloc(sizeof(int) * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
}

void clear(vector *v) {
    v->size = 0;
}

void shrinkToFit(vector *v) {
    reserve(v, v->size);
}

void deleteVector(vector *v) {
    free(v->data);
}
