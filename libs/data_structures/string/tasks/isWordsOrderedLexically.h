#ifndef MAIN_C_ISWORDSORDEREDLEXICALLY_H
#define MAIN_C_ISWORDSORDEREDLEXICALLY_H

#include "../string_.h"

bool isWordsOrderedLexically (char *s) {
    char *beginSearch = s;
    WordDescriptor currentWord;
    if (!getWord(beginSearch, &currentWord))
        return true;

    WordDescriptor previousWord = currentWord;
    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, previousWord) < 0)
            return false;

        beginSearch = currentWord.end;
        previousWord = currentWord;
    }

    return true;
}

}

#endif