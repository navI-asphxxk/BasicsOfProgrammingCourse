#ifndef INC_GETLASTWORDOFFIRSTSTRINGINSECONDSTRING_H
#define INC_GETLASTWORDOFFIRSTSTRINGINSECONDSTRING_H

#include "../string_.h"

WordDescriptor getLastWordInFirstStringInTheSecondString(char *s1, char *s2) {
    getBagOfWords(&_bag, s1);
    getBagOfWords(&_bag2, s2);
    WordDescriptor word = {NULL, NULL};
    bool isFoundLast = false;

    for (int i = _bag.size - 1; i >= 0 && !isFoundLast; i--)
        for (int j = 0; j < _bag2.size && !isFoundLast; j++)
            if (areWordsEqual(_bag.words[i], _bag2.words[j]) == 0) {
                word = _bag.words[i];
                isFoundLast = true;
            }

    return word;
}

#endif
