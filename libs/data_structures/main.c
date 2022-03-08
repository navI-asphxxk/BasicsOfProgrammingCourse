#include <stdio.h>
#include "string/string_.h"
#include "string/tasks/removeNonLetters.h"
#include "string/tasks/removeAdjacentEqualLetters.h"
#include "string/tasks/digitsToStartAndReverseThem.h"
#include "string/tasks/digitsToStartWithSave.h"
#include "string/tasks/replaceEachDigitToSpaces.h"
#include "string/tasks/replaceAllWords1ToWord2.h"
#include "string/tasks/reverseEachWord.h"
#include "string/tasks/countPalidromes.h"
#include "string/tasks/getAlternatingStringFromTwoOthers.h"
#include "string/tasks/reverseWordsInString.h"
#include "string/tasks/printWordBeforeFirstWordWithA.h"
#include "string/tasks/getLastWordOfFirstStringInSecondString.h"

int main() {
    test_removeNonLetters();
    testAll_getWordBeforeFirstWordWithA();
    test_getLastWordInFirstStringInTheSecondString();

    return 0;
}
