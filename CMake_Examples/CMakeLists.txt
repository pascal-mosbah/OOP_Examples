cmake_minimum_required (VERSION 3.9)

project(Test_CMake)

set (CMAKE_CXX_STANDARD 20)

if(NOT MSVC)
    link_libraries(m)
endif()

if(MSVC)
    add_compile_options(/W4 /WX /DEBUG)
else()
    add_compile_options(-Wall -Werror -g)
endif()

include_directories(include)
add_executable (test_function "src/main.cpp"  "src/myfunction.cpp")


set(SRC "src/main.cpp"  "src/myfunction.cpp")
add_executable (test_function1 ${SRC})
target_include_directories(test_function1 PUBLIC include)

add_subdirectory(project1)
add_subdirectory(project2)
