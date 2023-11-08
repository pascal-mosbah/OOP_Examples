cmake_minimum_required (VERSION 3.5)

project(Thread)

set (CMAKE_CXX_STANDARD 17)
if (MSVC)
    add_compile_options(/W4 /WX)
    SET(INTEL "C:/Program Files (x86)/Intel/oneAPI")
else()
    add_compile_options(-Wall)
    find_package(TBB REQUIRED) 
    link_libraries(TBB::tbb)
    SET(INTEL "/opt/intel/oneapi")
endif()

SET(INTEL_COMPILER_LIB "${INTEL}/compiler/latest/windows/compiler/lib/intel64")
SET(MKL_DIR "${INTEL}/mkl/latest/lib/cmake/mkl")

find_package(MKL CONFIG REQUIRED)

find_package(OpenMP)
link_libraries(OpenMP::OpenMP_CXX)

add_executable (thread1 "thread1.cpp")

target_compile_options(thread1 PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_COMPILE_OPTIONS>)
target_include_directories(thread1 PUBLIC $<TARGET_PROPERTY:MKL::MKL,INTERFACE_INCLUDE_DIRECTORIES>)
target_link_libraries(thread1 PUBLIC $<LINK_ONLY:MKL::MKL>)
