add_library(time_measuring
        sorts/sorts.c sorts/sorts.h
        main.c
        ../algorithms/array/array.h ../algorithms/array/array.c
        ../algorithms/algorithm.h ../algorithms/algorithm.c)

target_link_libraries(time_measuring algorithms)

cmake_minimum_required(VERSION 3.16)

project(project1 C)


set(CMAKE_C_STANDARD 11)


# определение точки входа. Будет запущен файл main.c .
# указывается произвольная метка, в данном случае - project
add_executable(project1 main.c
        sorts/sorts.h sorts/sorts.c
        ../algorithms/array/array.h ../algorithms/array/array.c
        ../algorithms/algorithm.h ../algorithms/algorithm.c)


# создаём библиотеку
add_library(str1 sorts/sorts.h sorts/sorts.c)


# описываем, что для запуска project потребуется сборка tasks
target_link_libraries(project1 str1)