#ifndef INC_REMOVEADJACENTEQUALLETTERS_H
#define INC_REMOVEADJACENTEQUALLETTERS_H

void removeAdjacentEqualLetters(char *s) {
    char *begin = s;
    char *destination = begin;
    char last = *begin;
    while (*begin != '\0') {
        if (*begin != last) {
            *destination = last;
            destination++;
        }
        last = *begin++;
    }
    if (last != '\0')
        *destination++ = last;

    *destination = '\0';
}

#endif
