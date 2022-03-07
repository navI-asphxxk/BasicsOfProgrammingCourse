#ifndef INC_COUNTPALIDROMES_H
#define INC_COUNTPALIDROMES_H

#include "../string_.h"

int countPalindromes(char *s) {
    char *endSearch = getEndOfString(s);
    char *beginSearch = findNonSpace(s);
    int countPalindromes = 0;
    char *commaPos = find(beginSearch, endSearch, ',');
    bool isLastComma = *commaPos == '\0' && endSearch != beginSearch;

    while (*commaPos != '\0' || isLastComma) {
        beginSearch = findNonSpace(beginSearch);
        countPalindromes += isPalindrome(beginSearch, commaPos);
        beginSearch = commaPos + 1;
        if (isLastComma)
            break;

        commaPos = find(beginSearch, endSearch, ',');
        isLastComma = *commaPos == '\0';
    }

    return countPalindromes;
}

#endif
