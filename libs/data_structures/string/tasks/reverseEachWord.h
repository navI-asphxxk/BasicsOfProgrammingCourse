#ifndef INC_REVERSEEACHWORD_H
#define INC_REVERSEEACHWORD_H

#include "../string_.h"

void reverseEachWord(char *s) {
    BagOfWords bag;
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&bag, _stringBuffer);
    char *begin = s;

    for (int i = 0; i < bag.size; i++) {
        begin = *copyReverse(bag.words[i].end - 1, bag.words[i].begin - 1, begin);
        *begin++ = ' ';
    }
    if (begin != s)
        begin--;

    *begin = '\0';
}

#endif
