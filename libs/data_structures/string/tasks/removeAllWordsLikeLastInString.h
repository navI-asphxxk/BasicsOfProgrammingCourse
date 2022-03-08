#ifndef INC_REMOVEALLWORDSLIKELASTINSTRING_H
#define INC_REMOVEALLWORDSLIKELASTINSTRING_H

#include "../string_.h"

void removeAllWordsLikeLastInString(char *s) {
    WordDescriptor lastWord;
    bool isLast = getWordReverse(getEndOfString(s), s - 1, &lastWord);
    if (!isLast)
        return;

    char *beginSearch = s;
    char *beginCopy = s;
    WordDescriptor currentWord;

    while (getWord(beginSearch, &currentWord)) {
        if (areWordsEqual(currentWord, lastWord) != 0) {
            beginCopy = copy(currentWord.begin, currentWord.end, beginCopy);
            *beginCopy++ = ' ';
        }
        beginSearch = currentWord.end;
    }
    if (beginCopy != s)
        beginCopy--;

    *beginCopy = '\0';
}

#endif
