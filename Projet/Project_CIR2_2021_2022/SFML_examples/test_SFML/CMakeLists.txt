cmake_minimum_required (VERSION 3.9)
project(SFML_Test)

if(MSVC)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
    set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/../../SFML-2.5.1-static/lib/cmake/SFML")
endif()

find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)

set(TEST_SRCS "main.cpp" "Car.cpp")

add_executable (SFML_Test ${TEST_SRCS})
target_link_libraries(SFML_Test sfml-graphics sfml-window)
