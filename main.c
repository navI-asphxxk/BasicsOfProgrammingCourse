#include <stdio.h>
#include "libs/algorithms/array/array.h"
#include "libs/data_structures/unordered_array_set/unordered_array_set.h"
#include "libs/data_structures/ordered_array_set/ordered_array_set.h"

//TEST_ORDERED_ARRAY
//test_ordered_array_set_union

void test_ordered_array_set_union1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_union2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_union3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_union4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_union(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6},
                                                6);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_union() {
    test_ordered_array_set_union1();
    test_ordered_array_set_union2();
    test_ordered_array_set_union3();
    test_ordered_array_set_union4();
}

//ordered_array_set_in

void test_ordered_array_set_in1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    int resIndex = ordered_array_set_in(&set1, 2);
    size_t expectedIndex = 1;
    assert(resIndex == expectedIndex);
    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    size_t resIndex = ordered_array_set_in(&set1, 1);
    size_t expectedIndex = 0;
    assert(resIndex == expectedIndex);
    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    size_t resIndex = ordered_array_set_in(&set1, 4);
    size_t expectedIndex = 3;
    assert(resIndex == expectedIndex);
    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    size_t resIndex = ordered_array_set_in(&set1, 10);
    size_t expectedIndex = 4;
    assert(resIndex == expectedIndex);
    ordered_array_set_delete(&set1);
}

void test_ordered_array_set_in() {
    test_ordered_array_set_in1();
    test_ordered_array_set_in2();
    test_ordered_array_set_in3();
    test_ordered_array_set_in4();
}

//test_ordered_array_set_isSubset

void test_ordered_array_set_isSubset1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 1;
    assert(result == expectedRes);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 1;
    assert(result == expectedRes);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 7}, 4);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 0;
    assert(result == expectedRes);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset4() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {6}, 1);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    size_t result = ordered_array_set_isSubset(set1, set2);
    size_t expectedRes = 0;
    assert(result == expectedRes);
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
}

void test_ordered_array_set_isSubset() {
    test_ordered_array_set_isSubset1();
    test_ordered_array_set_isSubset2();
    test_ordered_array_set_isSubset3();
    test_ordered_array_set_isSubset4();
}

//test_ordered_array_set_insert

void test_ordered_array_set_insert1() {
    ordered_array_set set1 = ordered_array_set_create(10);
    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 5);
    ordered_array_set_insert(&set1, 7);
    ordered_array_set_insert(&set1, 4);
    ordered_array_set_insert(&set1, 3);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7}, 4);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_insert2() {
    ordered_array_set set1 = ordered_array_set_create(10);
    ordered_array_set_insert(&set1, -1);
    ordered_array_set_insert(&set1, 3);
    ordered_array_set_insert(&set1, 10);
    ordered_array_set_insert(&set1, 0);
    ordered_array_set_insert(&set1, -6);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {-6, -1, 0, 3, 10}, 5);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_insert() {
    test_ordered_array_set_insert1();
    test_ordered_array_set_insert2();
}

//test_ordered_array_set_delete

void test_ordered_array_set_delete1() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4,
                                                                          5, 5, 10}, 5);
    ordered_array_set_deleteElement(&set1, 5);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 10}, 3);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_delete2() {
    ordered_array_set set1 = ordered_array_set_create_from_array((int[]) {3, 4,
                                                                          5, 7, 10}, 5);
    ordered_array_set_deleteElement(&set1, 6);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 5, 7, 10}, 5);
    assert(ordered_array_set_isEqual(set1, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_delete() {
    test_ordered_array_set_delete1();
    test_ordered_array_set_delete2();
}

//test_ordered_array_set_intersection

void test_ordered_array_set_intersection1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2}, 2);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3}, 2);
    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2}, 1);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_intersection2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {0}, 0);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_intersection3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_intersection4() {
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6, 7}, 5);
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_intersection(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {2, 3, 4}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_intersection() {
    test_ordered_array_set_intersection1();
    test_ordered_array_set_intersection2();
    test_ordered_array_set_intersection3();
    test_ordered_array_set_intersection4();
}

//test_ordered_array_set_difference

void test_ordered_array_set_difference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_difference2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6, 7}, 5);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_difference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {6, 7}, 2);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_difference3() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6, 7}, 5);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_difference(set2, set1);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 5}, 2);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_difference() {
    test_ordered_array_set_difference1();
    test_ordered_array_set_difference2();
    test_ordered_array_set_difference3();
}

//test_ordered_array_set_symmetricDifference

void test_ordered_array_set_symmetricDifference1() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_symmetricDifference2() {
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {2, 3, 4, 6, 7}, 5);
    ordered_array_set set2 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5}, 5);
    ordered_array_set resSet =
            ordered_array_set_symmetricDifference(set1, set2);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 5, 6, 7}, 4);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&set2);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_symmetricDifference() {
    test_ordered_array_set_symmetricDifference1();
    test_ordered_array_set_symmetricDifference2();
}

//test_ordered_array_set_complement

void test_ordered_array_set_complement1() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6}, 6);
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 5}, 3);
    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {3, 4, 6}, 3);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&universumSet);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_complement2() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6}, 6);
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 4, 5, 6}, 6);
    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {}, 0);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&universumSet);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_complement3() {
    ordered_array_set universumSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    ordered_array_set set1 =
            ordered_array_set_create_from_array((int[]) {}, 0);
    ordered_array_set resSet =
            ordered_array_set_complement(set1, universumSet);
    ordered_array_set expectedSet =
            ordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    assert(ordered_array_set_isEqual(resSet, expectedSet));
    ordered_array_set_delete(&set1);
    ordered_array_set_delete(&universumSet);
    ordered_array_set_delete(&resSet);
    ordered_array_set_delete(&expectedSet);
}

void test_ordered_array_set_complement() {
    test_ordered_array_set_complement1();
    test_ordered_array_set_complement2();
    test_ordered_array_set_complement3();
}

void test_ordered_array() {
    test_ordered_array_set_in();
    test_ordered_array_set_isSubset();
    test_ordered_array_set_insert();
    test_ordered_array_set_delete();
    test_ordered_array_set_union();
    test_ordered_array_set_intersection();
    test_ordered_array_set_difference();
    test_ordered_array_set_symmetricDifference();
    test_ordered_array_set_complement();
}


//TEST_UNORDERED_ARRAY
//test_unordered_array_set_union

void test_unordered_array_set_union1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {3, 2}, 2);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {3, 2, 1}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 3, 2}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {4, 3, 2, 6}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 5, 3, 4, 1}, 5);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {4, 6, 3, 1, 5, 2},
                                                  6);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union4() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_union(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_union() {
    test_unordered_array_set_union1();
    test_unordered_array_set_union2();
    test_unordered_array_set_union3();
    test_unordered_array_set_union4();
}

//unordered_array_set_in
void test_unordered_array_set_in1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 1}, 2);
    size_t resIndex = unordered_array_set_in(&set1, 2);
    size_t expectedIndex = 0;
    assert(resIndex == expectedIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    size_t resIndex = unordered_array_set_in(&set1, 1);
    size_t expectedIndex = 0;
    assert(resIndex == expectedIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    size_t resIndex = unordered_array_set_in(&set1, 4);
    size_t expectedIndex = 3;
    assert(resIndex == expectedIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in4() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 7, 10, 4, 5}, 5);
    size_t resIndex = unordered_array_set_in(&set1, 10);
    size_t expectedIndex = 2;
    assert(resIndex == expectedIndex);
    unordered_array_set_delete(set1);
}

void test_unordered_array_set_in() {
    test_unordered_array_set_in1();
    test_unordered_array_set_in2();
    test_unordered_array_set_in3();
    test_unordered_array_set_in4();
}

//test_unordered_array_set_insert
void test_unordered_array_set_insert1() {
    unordered_array_set set1 = unordered_array_set_create(10);
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 5);
    unordered_array_set_insert(&set1, 10);
    unordered_array_set_insert(&set1, 4);
    unordered_array_set_insert(&set1, 3);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {4, 3, 5, 10}, 4);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert2() {
    unordered_array_set set1 = unordered_array_set_create(10);
    unordered_array_set_insert(&set1, -1);
    unordered_array_set_insert(&set1, 3);
    unordered_array_set_insert(&set1, 14);
    unordered_array_set_insert(&set1, 0);
    unordered_array_set_insert(&set1, -8);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {-1, 0, -8, 3, 14}, 5);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_insert() {
    test_unordered_array_set_insert1();
    test_unordered_array_set_insert2();
}

//test_unordered_array_set_delete
void test_unordered_array_set_delete1() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {7,
                                                                              10, 5, 3, 4}, 5);
    unordered_array_set_deleteElement(&set1, 7);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {3, 10, 5, 4}, 4);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_delete2() {
    unordered_array_set set1 = unordered_array_set_create_from_array((int[]) {3,
                                                                              4, 7, 5, 10}, 5);
    unordered_array_set_deleteElement(&set1, 6);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {4, 5, 3, 7, 10}, 5);
    assert(unordered_array_set_isEqual(set1, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_delete() {
    test_unordered_array_set_delete1();
    test_unordered_array_set_delete2();
}

//test_unordered_array_set_intersection
void test_unordered_array_set_intersection1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2}, 2);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {3, 2}, 2);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2}, 1);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 3, 2}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {0}, 0);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 6, 4, 3}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {5, 4, 3, 2, 1}, 5);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {4, 3, 2}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection4() {
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {3, 5, 1, 4, 2}, 5);
    unordered_array_set resSet =
            unordered_array_set_intersection(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {3, 2, 4}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_intersection() {
    test_unordered_array_set_intersection1();
    test_unordered_array_set_intersection2();
    test_unordered_array_set_intersection3();
    test_unordered_array_set_intersection4();
}

//test_unordered_array_set_difference
void test_unordered_array_set_difference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {4, 3, 2, 6}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {3, 5, 1, 4, 2}, 5);
    unordered_array_set resSet =
            unordered_array_set_difference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {6}, 1);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference3() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {4, 3, 2, 6}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {3, 5, 1, 4, 2}, 5);
    unordered_array_set resSet =
            unordered_array_set_difference(set2, set1);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {5, 1}, 2);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_difference() {
    test_unordered_array_set_difference1();
    test_unordered_array_set_difference2();
    test_unordered_array_set_difference3();
}

//test_unordered_array_set_symmetricDifference
void test_unordered_array_set_symmetricDifference1() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 2, 3}, 3);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {2, 1, 3}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference2() {
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {2, 3, 4, 6}, 4);
    unordered_array_set set2 =
            unordered_array_set_create_from_array((int[]) {1, 4, 3, 2, 5}, 5);
    unordered_array_set resSet =
            unordered_array_set_symmetricDifference(set1, set2);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {6, 5, 1}, 3);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(set2);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_symmetricDifference() {
    test_unordered_array_set_symmetricDifference1();
    test_unordered_array_set_symmetricDifference2();
}

//test_unordered_array_set_complement
void test_unordered_array_set_complement1() {
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {5, 6, 3, 1, 2}, 5);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {1, 5, 2}, 3);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {6, 3}, 2);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement2() {
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {6, 3, 2, 5, 1}, 5);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {5, 2, 3, 1, 6}, 5);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {}, 0);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement3() {
    unordered_array_set universumSet =
            unordered_array_set_create_from_array((int[]) {1, 2, 3, 5, 6}, 5);
    unordered_array_set set1 =
            unordered_array_set_create_from_array((int[]) {}, 0);
    unordered_array_set resSet =
            unordered_array_set_complement(set1, universumSet);
    unordered_array_set expectedSet =
            unordered_array_set_create_from_array((int[]) {5, 2, 3, 1, 6}, 5);
    assert(unordered_array_set_isEqual(resSet, expectedSet));
    unordered_array_set_delete(set1);
    unordered_array_set_delete(universumSet);
    unordered_array_set_delete(resSet);
    unordered_array_set_delete(expectedSet);
}

void test_unordered_array_set_complement() {
    test_unordered_array_set_complement1();
    test_unordered_array_set_complement2();
    test_unordered_array_set_complement3();
}

void test_unordered_array() {
    test_unordered_array_set_in();
    test_unordered_array_set_insert();
    test_unordered_array_set_delete();
    test_unordered_array_set_union();
    test_unordered_array_set_intersection();
    test_unordered_array_set_difference();
    test_unordered_array_set_symmetricDifference();
    test_unordered_array_set_complement();
}

int main() {
    test_unordered_array();

    test_ordered_array();

    return 0;
}
