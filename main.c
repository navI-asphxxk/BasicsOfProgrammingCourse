#include <stdio.h>
#include "libs/data_structures/vector/vector.h"


// TEST PUSHBACK

void test_pushBack_emptyVector() {
    vector v1 = createVector(0);
    vector v2 = createVector(1);
    pushBack(&v1, 1);
    pushBack(&v2, 1);
    vector expectedRes1 = {(int[]) {1}, 1, 1};
    vector expectedRes2 = {(int[]) {1}, 1, 1};
    assert(vector_isEqual(&v1, &expectedRes1));
    assert(vector_isEqual(&v2, &expectedRes2));
    deleteVector(&v1);
    deleteVector(&v2);
    deleteVector(&expectedRes1);
    deleteVector(&expectedRes2);
}

void test_pushBack_fullVector() {
    vector v = createVector(0);
    pushBack(&v, 3);
    pushBack(&v, 2);
    pushBack(&v, 1);
    vector expectedRes = {(int[]) {3, 2, 1}, 3, 4};
    assert(vector_isEqual(&v, &expectedRes));
    deleteVector(&v);
    deleteVector(&expectedRes);
}

void test_pushBack_vector() {
    vector v = createVector(0);
    pushBack(&v, 1);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 4);
    vector expectedRes = {(int[]) {1, 2, 3, 4}, 4, 4};
    assert(vector_isEqual(&v, &expectedRes));
    deleteVector(&v);
    deleteVector(&expectedRes);
}

void test_pushBack() {
    test_pushBack_fullVector();
    test_pushBack_emptyVector();
    test_pushBack_vector();
}


//TEST GET VECTOR VALUE

void test_getVectorValue_firstElement() {
    vector v = {(int[]) {1, 2, 3}, 3, 3};
    assert(getVectorValue(&v, 0) == 1);
    deleteVector(&v);
}

void test_getVectorValue_lastElement() {
    vector v = {(int[]) {1, 2, 3}, 3, 3};
    assert(getVectorValue(&v, 2) == 3);
    deleteVector(&v);
}

void test_getVectorValue_any() {
    vector v = {(int[]) {1, 2, 3}, 3, 3};
    assert(getVectorValue(&v, 1) == 2);
    deleteVector(&v);
}

void test_getVectorValue() {
    test_getVectorValue_any();
    test_getVectorValue_firstElement();
    test_getVectorValue_lastElement();
}


//TEST POPBACK

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);
    assert (v.size == 1);

    popBack(&v);
    assert (v.size == 0);
    assert (v.capacity == 1);
}


//TEST AT VECTOR

void test_atVector_notEmptyVector() {
    vector v = {(int[]) {1, 2, 3}, 3, 3};
    assert(atVector(&v, 0) == v.data);
    assert(atVector(&v, 1) == &v.data[1]);
    assert(atVector(&v, 2) == &v.data[2]);
    deleteVector(&v);
}

void test_atVector_requestToLastElement() {
    vector v1 = {(int[]) {1}, 1, 1};
    vector v2 = {(int[]) {1, 1, 2, 2}, 4, 6};
    assert(atVector(&v1, 0) == v1.data);
    assert(atVector(&v2, 3) == &v2.data[3]);
    deleteVector(&v1);
    deleteVector(&v2);
}

void test_atVector() {
    test_atVector_requestToLastElement();
    test_atVector_notEmptyVector();
}


// TEST BACK

void test_back_inVector() {
    vector v = {(int[]) {1, 2, 3, 4}, 4, 4};
    assert(back(&v) == &v.data[3]);
    deleteVector(&v);
}

void test_back_oneElementInVector() {
    vector v = {(int[]) {0}, 1, 1};
    assert(back(&v) == v.data);
    deleteVector(&v);
}

void test_back() {
    test_back_oneElementInVector();
    test_back_inVector();
}


//TEST FRONT

void test_front_inVector() {
    vector v = {(int[]) {1, 2, 3}, 3, 3};
    assert(front(&v) == v.data);
    deleteVector(&v);
}

void test_front_oneElementInVector() {
    vector v = {(int[]) {0}, 1, 1};
    assert(back(&v) == v.data);
    deleteVector(&v);
}

void test_front() {
    test_front_inVector();
    test_front_oneElementInVector();
}


// TEST
void test() {
    test_pushBack();
    test_getVectorValue();
    test_popBack_notEmptyVector();
    test_atVector();
    test_back();
    test_front();
}


int main() {
    //vector v = createVector(SIZE_MAX);
    test();

    return 0;
}