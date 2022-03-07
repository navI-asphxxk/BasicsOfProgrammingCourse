#ifndef MAIN_C_REPLACEEACHDIGITTOSPACES_H
#define MAIN_C_REPLACEEACHDIGITTOSPACES_H

#include "../string_.h"

#define CODE_NULL 48

void replaceEachDigitToSpaces(char *s) {
    char *buffer = _stringBuffer;
    char *endString = getEndOfString(s);
    char *endOfBuffer = copy(s, endString, buffer);
    *endOfBuffer = '\0';

    while (*buffer != '\0') {
        if (isalpha(*buffer))
            *s++ = *buffer;
        else if (isdigit(*buffer)) {
            int countOfSpaces = *buffer - CODE_NULL;
            for (int i = 0; i < countOfSpaces; i++)
                *s++ = " ";
        }
        buffer++;
    }
    *s = '\0';
}

#endif
