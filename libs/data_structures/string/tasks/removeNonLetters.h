#ifndef INC_REMOVENONLETTERS_H
#define INC_REMOVENONLETTERS_H

#include "../string_.h"

void removeNonLetters(char *s) {
    char *endSource = getEndOfString(s);
    char *destination = copyIf(s, endSource, s, isgraph);
    *destination = '\0';
}

void test_removeNonLetters_emptyString() {
    char s[] = "";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters_noWhitespaceCharacters() {
    char s[] = "qwerty";
    removeNonLetters(s);

    ASSERT_STRING("qwerty", s);
}

void test_removeNonLetters_withWhitespaceCharacters1() {
    char s[] = "qwe";
    removeNonLetters(s);

    ASSERT_STRING("qwerty", s);
}

void test_removeNonLetters_withWhitespaceCharacters2() {
    char s[] = "q \tw \te \n ";
    removeNonLetters(s);

    ASSERT_STRING("qwe", s);
}

void test_removeNonLetters_onlyWhitespaceCharacters() {
    char s[] = "\t \t    \n";
    removeNonLetters(s);

    ASSERT_STRING("", s);
}

void test_removeNonLetters() {
    test_removeNonLetters_noWhitespaceCharacters();
    test_removeNonLetters_withWhitespaceCharacters1();
    test_removeNonLetters_withWhitespaceCharacters2();
    test_removeNonLetters_emptyString();
    test_removeNonLetters_onlyWhitespaceCharacters();
}

#endif
