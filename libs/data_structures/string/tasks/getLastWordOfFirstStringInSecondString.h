#ifndef INC_GETLASTWORDOFFIRSTSTRINGINSECONDSTRING_H
#define INC_GETLASTWORDOFFIRSTSTRINGINSECONDSTRING_H

#include "../string_.h"

WordDescriptor getLastWordInFirstStringInTheSecondString(char *s1, char *s2) {
    BagOfWords bag1, bag2;
    getBagOfWords(&bag1, s1);
    getBagOfWords(&bag2, s2);
    WordDescriptor word = {NULL, NULL};
    bool isFoundLast = false;

    for (int i = bag1.size - 1; i >= 0 && !isFoundLast; i--)
        for (int j = 0; j < bag2.size && !isFoundLast; j++)
            if (areWordsEqual(bag1.words[i], bag2.words[j]) == 0) {
                word = bag1.words[i];
                isFoundLast = true;
            }

    return word;
}

#endif
