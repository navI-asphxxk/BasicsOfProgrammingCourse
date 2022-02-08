#include <stdio.h>
#include "libs/data_structures/vector/vectorVoid.h"

int main() {
    vectorVoid v = {malloc(2 * sizeof(int)), 1, 2, sizeof(int)};

    return 0;
}