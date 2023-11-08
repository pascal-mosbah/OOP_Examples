cmake_minimum_required (VERSION 3.9)
project(SFML_Test3)


if(MSVC)
set(CMAKE_CXX_FLAGS_RELEASE "/MT")
set(CMAKE_CXX_FLAGS_DEBUG "/MTd")
	set(SFML_STATIC_LIBRARIES TRUE)
	set(SFML_DIR "${PROJECT_SOURCE_DIR}/../../SFML-2.5.1-static/lib/cmake/SFML")
endif()


find_package(SFML 2.5 COMPONENTS window system graphics REQUIRED)

set(TEST_SRCS "main.cpp" "Plane.cpp")

add_executable (SFML_Test3 ${TEST_SRCS})

find_package (Threads)

target_compile_features(SFML_Test3 PUBLIC cxx_std_17)
target_link_libraries (SFML_Test3 Threads::Threads)

target_link_libraries(SFML_Test3 sfml-graphics sfml-window)



#if(MSVC)
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded<$<CONFIG:Release>:Release>")
#    set_property(TARGET SFML_Test1 PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreadedDebug<$<CONFIG:Debug>:Debug>")
#endif()
