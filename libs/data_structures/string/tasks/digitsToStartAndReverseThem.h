#ifndef INC_DIGITSTOSTARTANDREVERSETHEM_H
#define INC_DIGITSTOSTARTANDREVERSETHEM_H

#include "../string_.h"

void digitToStartWithReverse(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end,
                                 _stringBuffer);
    char *recPosition = copyIfReverse(endStringBuffer - 1,
                                      _stringBuffer - 1,
                                      word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithReverse(word);
        beginSearch = word.end;
    }
}

#endif
