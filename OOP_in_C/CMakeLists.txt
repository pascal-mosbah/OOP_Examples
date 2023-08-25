cmake_minimum_required (VERSION 3.9)

project(Shape)

set(SRCS "shape.c" "shape_bis.c" "main.c" "shape_third.c")
add_executable (Shape ${SRCS})