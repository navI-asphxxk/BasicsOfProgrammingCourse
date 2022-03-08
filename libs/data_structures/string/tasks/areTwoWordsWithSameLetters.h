#ifndef INC_ARETWOWORDSWITHSAMELETTERS_H
#define INC_ARETWOWORDSWITHSAMELETTERS_H

#include "../string_.h"

int cmp_char(const void *a, const void *b) {
    char arg1 = *(const char *) a;
    char arg2 = *(const char *) b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

bool areWordsFromSameLetters(char *s) {
    *copy(s, getEndOfString(s), _stringBuffer) = '\0';
    getBagOfWords(&_bag, _stringBuffer);

    for (int i = 0; i < _bag.size; i++)
        qsort(_bag.words[i].begin, _bag.words[i].end - _bag.words[i].begin,
              sizeof(char), cmp_char);

    return areSameWordsInString(_stringBuffer);
}

#endif
