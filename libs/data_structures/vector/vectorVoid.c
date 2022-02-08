#include "vectorVoid.h"
#include <stdio.h>

vectorVoid createVectorV(size_t n, size_t baseTypeSize) {
    void *data = (void *) malloc(baseTypeSize * n);
    if (data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else
        return (vectorVoid) {data, 0, n, baseTypeSize};
}

void reserveV(vectorVoid *v, size_t newCapacity) {
    v->capacity = newCapacity;
    v->data = (void *) realloc(v->data, v->baseTypeSize * newCapacity);
    if (v->data == NULL) {
        fprintf(stderr, "bad alloc ");
        exit(1);
    } else if (newCapacity == 0) {
        v->data = NULL;
        v->size = 0;
    } else if (newCapacity < v->size)
        v->size = newCapacity;
}

void shrinkToFitV(vectorVoid *v) {
    reserveV(v, v->size);
}

void clearV(vectorVoid *v) {
    v->size = 0;
}

void deleteVectorV(vectorVoid *v) {
    if (v->data == NULL) {
        free(v->data);
        v->data = NULL;
    }
}

