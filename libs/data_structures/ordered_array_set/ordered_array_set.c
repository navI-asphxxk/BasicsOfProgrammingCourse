#include "ordered_array_set.h"
#include <malloc.h>

ordered_array_set ordered_array_set_create(size_t capacity) {
    return (ordered_array_set) {
            malloc(sizeof(int) * capacity), 0,
            capacity
    };
}

// освобождает неиспользуемую память, отведенную под
// множество a
static void ordered_array_set_shrinkToFit(ordered_array_set *a) {
    if (a->size != a->capacity) {
        a->data = (int *) realloc(a->data, sizeof(int) * a->size);
        a->capacity = a->size;
    }
}

void ordered_array_set_isAbleAppend(ordered_array_set *set) {
    assert(set->size < set->capacity);
}

int ordered_array_set_in(ordered_array_set *set, int value) {
    return binarySearch_(set->data, set->size, value);
}

ordered_array_set ordered_array_set_create_from_array(const int *a,
                                                      size_t size) {
    ordered_array_set set = ordered_array_set_create(size);
    for (size_t i = 0; i < size; i++)
        ordered_array_set_insert(&set, a[i]);

    return (ordered_array_set) set;
}

bool ordered_array_set_isEqual(ordered_array_set set1,
                               ordered_array_set set2) {
    if (set1.size != set2.size)
        return false;

    for (size_t i = 0; i < set1.size; i++)
        if (set1.data[i] != set2.data[i])
            return false;

    return true;
}

bool ordered_array_set_isSubset(ordered_array_set subset, ordered_array_set set) {
    for (size_t i = 0; i < subset.size; i++)
        if (ordered_array_set_in(&set, subset.data[i]) == set.size)
            return false;

    return true;
}

void ordered_array_set_insert(ordered_array_set *set, int value) {
    ordered_array_set_isAbleAppend(set);
    if (ordered_array_set_in(set, value) == set->size) {
        int positionInsert = binarySearchLessOrEqual_(set->data, set->size,
                                                      value);
        if (positionInsert == -1)
            insert_(set->data, &set->size, 0, value);
        else
            insert_(set->data, &set->size, positionInsert + 1, value);
    }
}

void ordered_array_set_deleteElement(ordered_array_set *set, int value) {
    size_t pos = ordered_array_set_in(set, value);
    if (pos != set->size)
        deleteByPosSaveOrder_(set->data, &set->size, pos);
}

ordered_array_set ordered_array_set_union(ordered_array_set set1,
                                          ordered_array_set set2) {
    ordered_array_set set = ordered_array_set_create(set1.size + set2.size);
    for (size_t i = 0; i < set1.size; i++)
        append_(set.data, &set.size, set1.data[i]);
    for (size_t i = 0; i < set2.size; i++)
        ordered_array_set_insert(&set, set2.data[i]);

    return (ordered_array_set) set;
}

void swap_ordered_sets(ordered_array_set *set1,
                       ordered_array_set *set2) {
    ordered_array_set t = *set1;
    *set1 = *set2;
    *set2 = t;
}

ordered_array_set ordered_array_set_intersection(ordered_array_set
                                                 set1, ordered_array_set set2) {
    if (set1.size > set2.size)
        swap_ordered_sets(&set1, &set2);
    ordered_array_set set3 = ordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) != set2.size)
            append_(set3.data, &set3.size, set1.data[i]);
    }

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_difference(ordered_array_set set1,
                                               ordered_array_set set2) {
    ordered_array_set set3 = ordered_array_set_create(set1.size);
    for (size_t i = 0; i < set1.size; i++) {
        if (ordered_array_set_in(&set2, set1.data[i]) == set2.size)
            append_(set3.data, &set3.size, set1.data[i]);
    }

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_symmetricDifference(
        ordered_array_set set1, ordered_array_set set2) {
    ordered_array_set difference1 =
            ordered_array_set_difference(set1, set2);
    ordered_array_set difference2 =
            ordered_array_set_difference(set2, set1);
    ordered_array_set set3 =
            ordered_array_set_union(
                    difference1,
                    difference2);
    ordered_array_set_delete(&difference1);
    ordered_array_set_delete(&difference2);

    return (ordered_array_set) set3;
}

ordered_array_set ordered_array_set_complement(ordered_array_set
                                               set, ordered_array_set universumSet) {
    return (ordered_array_set)
            ordered_array_set_difference(universumSet, set);
}

void ordered_array_set_print(ordered_array_set set) {
    outputArray_(set.data, set.size);
}

void ordered_array_set_delete(ordered_array_set *set) {
    if (set->data == NULL) {
        free(set->data);
        set->data = NULL;
    }
}

