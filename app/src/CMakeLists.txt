cmake_minimum_required(VERSION 3.17.3)

set(NAME app)

file(GLOB SOURCE *.cpp)

add_library(${NAME} STATIC ${SOURCE})
