cmake_minimum_required (VERSION 3.9)

project(project2)

include_directories(include)
add_executable (project2 "src/main.cpp"  "src/myfunction.cpp")
