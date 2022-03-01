add_library(data_structures
        bitset/bitset.c
        unordered_array_set/unordered_array_set.c unordered_array_set/unordered_array_set.h
        ordered_array_set/ordered_array_set.c ordered_array_set/ordered_array_set.h
        vector/vector.c vector/vector.h
        vector/vectorVoid.c vector/vectorVoid.h
        matrix/matrix.c matrix/matrix.h
        string/string_.c string/string_.h)

target_link_libraries(data_structures algorithms)

cmake_minimum_required(VERSION 3.16)

project(project C)


set(CMAKE_C_STANDARD 11)


# определение точки входа. Будет запущен файл main.c .
# указывается произвольная метка, в данном случае - project
add_executable(project main.c)


# создаём библиотеку
add_library(str string/string.h string/string_.c
        # string / tasks / digitToStartTransform . h

        # string / tasks / reverseWords . h

        # string / tasks / replaceDigitsBySpaces . h

        # ...

        # < файл с решением задачи >

        # ...

        # string / tasks / hasPairOfWordsWithEqualLetterSet . h

        # string / tasks / printWordsNonEqualLastWord . h

        )


# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project str)