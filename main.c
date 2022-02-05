#include <stdio.h>
#include <stdint.h>
#include "libs/data_structures/vector/vector.h"

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}

int main() {
    //vector v = createVector(SIZE_MAX);
    test_popBack_notEmptyVector();

    return 0;
}