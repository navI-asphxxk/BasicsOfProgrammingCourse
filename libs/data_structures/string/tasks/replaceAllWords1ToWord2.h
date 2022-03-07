#ifndef MAIN_C_REPLACEALLWORDS1TOWORD2_H
#define MAIN_C_REPLACEALLWORDS1TOWORD2_H

#include "../string_.h"

void replaceAllWords1ToWord2 (char *source, char *w1, char *w2) {
    size_t w1Size = strlen_(w1);
    size_t w2Size = strlen_(w2);
    WordDescriptor word1 = {w1, w1 + w1Size};
    WordDescriptor word2 = {w2, w2 + w2Size};
    char *readPtr, *writePtr;

    if (w1Size >= w2Size) {
        readPtr = source;
        writePtr = source;
    } else {
        copy(source, getEndOfString(source), _stringBuffer);
        readPtr = _stringBuffer;
        writePtr = source;
    }

    while (*readPtr != '\0') {
        if (*readPtr == *word1.begin) {
            if (areWordsEqual(word1, (WordDescriptor) {readPtr, readPtr + w1Size}) <= 0) {
                copy(word2.begin, word2.end, writePtr);
                readPtr += w1Size;
                writePtr += w2Size;
            } else {
                *writePtr++ = *readPtr++;
            }
        } else
            *writePtr++ = *readPtr++;
    }

    *writePtr = '\0';
}

#endif
