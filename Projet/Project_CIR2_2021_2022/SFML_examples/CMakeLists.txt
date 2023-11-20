cmake_minimum_required (VERSION 3.6)

project(SFML)

set (CMAKE_CXX_STANDARD 20)

if(MSVC)
    set(SFML_DIR "C:/Program Files/SFML/lib/cmake/SFML")
    set(SFML_STATIC_LIBRARIES TRUE)
    set(CMAKE_CXX_FLAGS_RELEASE "/MT")
    set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
endif()

find_package(SFML 2.6.1 COMPONENTS window system graphics REQUIRED)
link_libraries(sfml-graphics sfml-window)

add_subdirectory(test_SFML)
add_subdirectory(test_SFML1)
add_subdirectory(test_SFML2)
add_subdirectory(test_SFML3)

