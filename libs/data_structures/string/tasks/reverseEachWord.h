#ifndef INC_REVERSEEACHWORD_H
#define INC_REVERSEEACHWORD_H

#include "../string_.h"

void printWordsInReverseOrder(char *s) {
    getBagOfWords(&_bag, s);
    for (int i = _bag.size - 1; i >= 0; i--)
        printWord(_bag.words[i]);
}

#endif
