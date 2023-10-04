cmake_minimum_required (VERSION 3.9)

project(project1)

include_directories(include)
add_executable (project1 "src/main.cpp"  "src/myfunction.cpp")
