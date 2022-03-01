#ifndef INC_REMOVENONLETTERS_H
#define INC_REMOVENONLETTERS_H

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

#endif
