cmake_minimum_required (VERSION 3.5)

project(Constructor_and_operator_overloading)

set(SRCS
	"main.cpp")

add_executable (example ${SRCS})

if (MSVC)
    add_compile_options(/W4 /WX /DEBUG)
else()
    add_compile_options(-Wall -Werror -g)
endif()
