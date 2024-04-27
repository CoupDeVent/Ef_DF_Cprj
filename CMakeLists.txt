cmake_minimum_required(VERSION 3.28)
project(Projet_de_programmation_C C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(Projet_de_programmation_C
        cdataframe.h
        column.h
        main.c
        column.c
        cdataframe.c
)
