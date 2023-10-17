cmake_minimum_required (VERSION 3.5)

project(various_const)

set (CMAKE_CXX_STANDARD 20)

set(SRCS 
	"various_const.cpp" 
	)
add_executable (various_const ${SRCS})
add_executable (various_const1 "various_const1.cpp")

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-std=c++20 -Wall -Werror)
endif()
