add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c unordered_array_set/unordered_array_set.h
        ordered_array_set/ordered_array_set.c ordered_array_set/ordered_array_set.h
        vector/vector.c vector/vector.h
        vector/vectorVoid.c vector/vectorVoid.h
        matrix/matrix.c matrix/matrix.h
        string/string_.c string/string_.h
        main.c
        string/tasks/removeNonLetters.h
        string/tasks/removeAdjacentEqualLetters.h
        string/tasks/digitsToStartAndReverseThem.h
        string/tasks/digitsToStartWithSave.h
        string/tasks/replaceEachDigitToSpaces.h
        string/tasks/replaceAllWords1ToWord2.h
        string/tasks/isWordsOrderedLexically.h
        string/tasks/reverseEachWord.h
        string/tasks/countPalidromes.h
        string/tasks/getAlternatingStringFromTwoOthers.h
        string/tasks/reverseWordsInString.h
        string/tasks/printWordBeforeFirstWordWithA.h
        string/tasks/getLastWordOfFirstStringInSecondString.h string/tasks/areSameWordsInString.h string/tasks/areTwoWordsWithSameLetters.h)

target_link_libraries(data_structures algorithms)

cmake_minimum_required(VERSION 3.16)

project(project C)


set(CMAKE_C_STANDARD 11)


# определение точки входа. Будет запущен файл main.c .
# указывается произвольная метка, в данном случае - project
add_executable(project main.c)


# создаём библиотеку
add_library(str string/string_.h string/string_.c
        string/tasks/removeNonLetters.h
        string/tasks/removeAdjacentEqualLetters.h
        string/tasks/digitsToStartAndReverseThem.h
        string/tasks/digitsToStartWithSave.h
        string/tasks/replaceEachDigitToSpaces.h
        string/tasks/replaceAllWords1ToWord2.h
        string/tasks/isWordsOrderedLexically.h
        string/tasks/reverseEachWord.h
        string/tasks/countPalidromes.h
        string/tasks/getAlternatingStringFromTwoOthers.h
        string/tasks/reverseWordsInString.h
        string/tasks/printWordBeforeFirstWordWithA.h
        string/tasks/getLastWordOfFirstStringInSecondString.h)


# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project str)