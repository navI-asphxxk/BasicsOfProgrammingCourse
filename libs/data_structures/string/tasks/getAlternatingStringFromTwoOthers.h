#ifndef INC_GETALTERNATINGSTRINGFROMTWOOTHERS_H
#define INC_GETALTERNATINGSTRINGFROMTWOOTHERS_H

#include "../string_.h"

void getAlternatingStringFromTwoOthers0(char *s, char *s1, char *s2) {
    char *beginCopy = s;
    char *beginSearch1 = s1, *beginSearch2 = s2;
    WordDescriptor word1, word2;
    bool isW1Found, isW2Found;

    while ((isW1Found = getWord(beginSearch1, &word1)),
            (isW2Found = getWord(beginSearch2, &word2)),
            isW1Found || isW2Found) {

        if (isW1Found) {
            beginCopy = copy(word1.begin, word1.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch1 = word1.end;
        }
        if (isW2Found) {
            beginCopy = copy(word2.begin, word2.end, beginCopy);
            *beginCopy++ = ' ';
            beginSearch2 = word2.end;
        }
    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

#endif
