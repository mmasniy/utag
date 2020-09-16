cmake_minimum_required(VERSION 3.18.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

# add_subdirectory(src)

find_library(TAGLIB taglib)

include_directories(../3dparty/taglib/taglib/)
include_directories(../3dparty/taglib/taglib/toolkit)
include_directories(../build/3dparty/taglib/)

include_directories(src)

add_compile_options(
        -std=c++17
#        -Wdev
        # -Werror
        # -Wall
        # -Wextra
        # -Wpedantic
#        -Wno-unused-parameter
)

set(SOURCE_EXE main.cpp)
add_executable(utag ${SOURCE_EXE})
target_link_libraries(utag tag)