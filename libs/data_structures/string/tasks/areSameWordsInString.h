#ifndef INC_ARESAMEWORDSINSTRING_H
#define INC_ARESAMEWORDSINSTRING_H

#include "../string_.h"

bool areSameWordsInString(char *s) {
    getBagOfWords(&_bag, s);

    for (int i = 0; i < _bag.size; i++)
        for (int j = i + 1; j < _bag.size; j++)
            if (areWordsEqual(_bag.words[i], _bag.words[j]) == 0)
                return true;

    return false;
}

#endif
