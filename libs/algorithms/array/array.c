#include "array.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

void inputArray_(int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        scanf("%d", &a[i]);
}

void outputArray_(const int *const a, const size_t n) {
    for (size_t i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void append_(int *const a, size_t *const n, const int value) {
    a[*n] = value;
    (*n)++;
}

void insert_(int *a, size_t *n, size_t pos, int value) {
    assert (pos <= *n);
    if (*n != 0) {
        size_t lowBound = (pos == 0) ? SIZE_MAX : pos;
        (*n)++;
        for (size_t i = *n; i != lowBound; i--)
            a[i] = a[i - 1];
        a[pos] = value;
    } else {
        (*n)++;
        a[pos] = value;
    }
}

void deleteByPosSaveOrder_(int *a, size_t *n, const size_t pos) {
    for (size_t i = pos; i < *n; i++)
        a[i] = a[i + 1];
    (*n)--;
}

void deleteByPosUnsaveOrder_(int *a, size_t *n, size_t pos) {
    a[pos] = a[*n - 1];
    (*n)--;
}

size_t linearSearch_(const int *a, const size_t n, int x) {
    for (size_t i = 0; i < n; i++)
        if (a[i] == x)
            return i;
    return n;
}

int any_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (predicate(a[i]))
            return 1;
    return 0;
}

int all_(const int *a, size_t n, int (*predicate )(int)) {
    for (size_t i = 0; i < n; i++)
        if (!predicate(a[i]))
            return 0;
    return 1;
}

int countIf_(const int *const a, const size_t n, int (*predicate )(int)) {
    int count = 0;
    for (size_t i = 0; i < n; i++)
        count += predicate(a[i]);
    return count;
}

void deleteIf_(int *const a, size_t *const n, int (*deletePredicate)(int)) {
    size_t iRead = 0;
    while (iRead < *n && !deletePredicate(a[iRead]))
        iRead++;
    size_t iWrite = iRead;
    while (iRead < *n) {
        if (!deletePredicate(a[iRead])) {
            a[iWrite] = a[iRead];
            iWrite++;
        }
        iRead++;
    }
    *n = iWrite;
}

void forEach_(const int *source, int *dest, const size_t n, const int (*predicate)(int)) {
    for (size_t i = 0; i < n; i++)
        dest[i] = predicate(source[i]);
}

int binarySearch_(const int *a, int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle + 1;
        else if (a[middle] > x)
            right = middle - 1;
        else
            return middle;
    }
    return n;
}

int binarySearchMoreOrEqual_(const int *a, size_t n, int x) {
    if (a[0] >= x)
        return 0;
    int left = 0;
    int right = n;
    while (right - left > 1) {
        int middle = left + (right - left) / 2;
        if (a[middle] < x)
            left = middle;
        else
            right = middle;
    }
    return right;
}

int binarySearchLessOrEqual_(const int *a, const int n, const int x) {
    int left = -1;
    int right = n;
    while (right - left > 1) {
        int middle = (left + right) / 2;
        if (a[middle] <= x)
            left = middle;
        else
            right = middle;
    }

    return left;
}

int getSum_(const int *a, const int n) {
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];

    return sum;
}

int isOrdered(const int *a, const size_t n) {
    for (size_t i = 1; i < n; i++) {
        if (a[i] < a[i - 1])
            return 0;
    }

    return 1;
}

