#ifndef INC_DIGITSTOSTARTWITHSAVE_H
#define INC_DIGITSTOSTARTWITHSAVE_H

#include "../string_.h"

void digitToStartWithSave(WordDescriptor word) {
    char *endStringBuffer = copy(word.begin, word.end, _stringBuffer);
    char *recPosition = copyIf(_stringBuffer, endStringBuffer, word.begin, isdigit);
    copyIf(_stringBuffer, endStringBuffer, recPosition, isalpha);
}

void digitToStartWithSaveForEveryWord(char *s) {
    char *beginSearch = s;
    WordDescriptor word;
    while (getWord(beginSearch, &word)) {
        digitToStartWithSave(word);

        beginSearch = word.end;
    }
}

#endif
