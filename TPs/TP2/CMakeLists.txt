cmake_minimum_required (VERSION 3.5)

project(TP2_3)

set (CMAKE_CXX_STANDARD 20)
if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Werror)
endif()

add_executable (TP2_1 "TP2_1.cpp")

add_executable (TP2_2 "TP2_2.cpp")

add_executable (TP2_3 "TP2_3.cpp")

add_executable (TP2_3_c "TP2_3.c")
