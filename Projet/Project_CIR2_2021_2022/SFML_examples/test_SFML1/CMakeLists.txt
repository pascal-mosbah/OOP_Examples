cmake_minimum_required (VERSION 3.9)
project(SFML_Test1)


if(MSVC)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/../../SFML-2.5.1-static/lib/cmake/SFML")
endif()


find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)

set(TEST_SRCS "main.cpp" "Follower.cpp" "Leader.cpp")

add_executable (SFML_Test1 ${TEST_SRCS})
target_link_libraries(SFML_Test1 sfml-graphics sfml-window)



#if(MSVC)
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded<$<CONFIG:Release>:Release>")
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
#endif()
