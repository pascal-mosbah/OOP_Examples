cmake_minimum_required(VERSION 3.8)

project(Partiel_2023)

set(CMAKE_CXX_STANDARD 20)

add_executable(Partiel_2023 Partiel_2023.cpp)

find_package(Threads REQUIRED)
add_executable(thread_partiel_2023 thread_partiel_2023.cpp)
target_link_libraries(thread_partiel_2023 PRIVATE Threads::Threads)