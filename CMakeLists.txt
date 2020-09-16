cmake_minimum_required(VERSION 3.18.2)

project(utag LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

add_subdirectory(app)
add_subdirectory(3dparty)
