#ifndef INC_REVERSEWORDSINSTRING_H
#define INC_REVERSEWORDSINSTRING_H

#include "../string_.h"

void reverseWordsInString(char *s) {
    char *end = copy(s, getEndOfString(s), _stringBuffer);
    char *beginCopy = s;
    char *beginSearch = end - 1;
    WordDescriptor w;

    while (getWordReverse(beginSearch, _stringBuffer - 1, &w)) {
        beginCopy = copy(w.begin, w.end, beginCopy);
        *beginCopy++ = ' ';
        beginSearch -= w.end - w.begin + 1;
        beginSearch = findNonSpaceReverse(beginSearch, _stringBuffer - 1);
    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

#endif
