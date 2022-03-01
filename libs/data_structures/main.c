#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeExtraSpaces.h"

// TESTS

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

int main() {



    return 0;
}
