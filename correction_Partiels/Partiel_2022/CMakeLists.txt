cmake_minimum_required (VERSION 3.9)

project(Partiel_2022)

set(SRCS "Partiel_2022.cpp")
add_executable (Partiel_2022 ${SRCS})
target_compile_features(Partiel_2022 PUBLIC cxx_std_20)
#add_compile_options("-g -Wall")
