cmake_minimum_required (VERSION 3.9)
project(SFML_Test3)

set(TEST_SRCS "main.cpp" "Plane.cpp")

find_package (Threads)

add_executable(SFML_Test3 ${TEST_SRCS})
target_link_libraries (SFML_Test3 Threads::Threads)


#if(MSVC)
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded<$<CONFIG:Release>:Release>")
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
#endif()
