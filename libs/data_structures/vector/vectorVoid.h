#ifndef INC_VECTORVOID_H
#define INC_VECTORVOID_H

#include <limits.h>
#include <malloc.h>
#include <stdint.h>
#include <memory.h>
#include <assert.h>
#include <stdbool.h>

typedef struct vectorVoid {
    void *data;
    size_t size;
    size_t capacity;
    size_t baseTypeSize;
} vectorVoid;

// возвращает структуру-дескриптор вектор из n значений,
// элементы которой имеют тип baseTypeSize
// Если ОС не смогла выделить необходимый фрагмент памяти, то
// вывод соответствующего сообщения
vectorVoid createVectorV(size_t n, size_t baseTypeSize);

// изменяет количество памяти, выделенное под хранение
// newCapacity элементов вектора v
// Если ОС не смогла выделить необходимый фрагмент памяти,
// вывод соответствующего сообщения
// Если в качестве newCapacity указано значение 0,
// в v->data записывает NULL
// Если значение newCapacity стало меньше v->size,
// тогда значение v->size равняется newCapacity.
void reserveV(vectorVoid *v, size_t newCapacity);

// освобождает память, выделенную под
// неиспользуемые элементы вектора v
void shrinkToFitV(vectorVoid *v);

// удаляет элементы вектора v, без освобождения память
void clearV(vectorVoid *v);

// освобождает память, выделенную вектору v
void deleteVectorV(vectorVoid *v);

#endif
