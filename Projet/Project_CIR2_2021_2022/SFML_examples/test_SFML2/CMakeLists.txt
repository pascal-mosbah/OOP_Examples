cmake_minimum_required (VERSION 3.9)

project(SFML_Test2)

if(MSVC)
	set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")    
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/../../SFML-2.5.1-static/lib/cmake/SFML")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++17")
endif()

find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)

set(TEST_SRCS "main.cpp")

add_executable (SFML_Test2 ${TEST_SRCS})
target_link_libraries(SFML_Test2 sfml-graphics sfml-window)
