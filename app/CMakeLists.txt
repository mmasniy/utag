#cmake_minimum_required(VERSION 3.15)
#
#project(utag)
##set(CMAKE_AUTOUIC ON)
#set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_EXTENSIONS OFF)
#set(CMAKE_CXX_STANDARD_REQUIRED YES)
## add_subdirectory(src)
#find_library(TAGLIB taglib)
#find_package(Qt5Core REQUIRED)
#find_package(Qt5Widgets REQUIRED)
#find_package(Qt5Quick REQUIRED)
#set(CMAKE_AUTOMOC ON)
#set(CMAKE_AUTORCC ON)
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set(Qt5Core_DIR "~/.brew/Cellar/qt/5.15.1/lib/cmake/Qt5Core")
#set(Qt5_DIR "~/.brew/Cellar/qt/5.15.1/lib/cmake/Qt5")
#set(CMAKE_PREFIX_PATH "~/.brew/Cellar/qt/5.15.1/lib/cmake/Qt5Core")
#
#include_directories(../3dparty/taglib/taglib/)
#include_directories(../3dparty/taglib/taglib/mpeg/)
#include_directories(../3dparty/taglib/taglib/mpeg/id3v2/)
#include_directories(../3dparty/taglib/taglib/frames/)
#include_directories(../3dparty/taglib/taglib/toolkit)
#include_directories(../build/3dparty/taglib/)
#include_directories(../cmake-build-debug/3dparty/taglib/)
#include_directories(src)
#include_directories(${Qt5_DIR})
#
#add_compile_options(
#    -std=c++17
#    #        -Wdev
#    -Werror
#    -Wall
#    -Wextra
#    -Wpedantic
#    #        -Wno-unused-parameter
#)
#
#set(SOURCE_EXE main.cpp)
#add_executable(utag ${SOURCE_EXE})
#
#target_link_libraries(utag tag)
#
#target_link_libraries(utag Qt5::Core)
#target_link_libraries(utag Qt5::Widgets)
#target_link_libraries(utag Qt5::Quick)
#target_include_directories(utag PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src/")

set(SOURCE_EXE main.cpp)

add_compile_options(
    -Wall
    -Wextra
    -Werror
    -Wpedantic
)

message("## Looking for Qt...")
find_package(Qt5 REQUIRED Core Qml Widgets)
if (${Qt5_FOUND})
    message("## Found Qt " ${Qt5_VERSION})
else()
    message("## Couldn't find Qt")
endif()

# MACRO to add all directories in result
MACRO(SUBDIRLIST result firstdir curdir)
    file(GLOB ENDF6_SRC_TOP RELATIVE
        ${curdir} ${curdir}/*)
    file(GLOB_RECURSE ENDF6_SRC_NESTED ${curdir}/*)
    set(children ${ENDF6_SRC_TOP} ${ENDF6_SRC_NESTED})

    SET(dirlist "${firstdir}")
    FOREACH(child ${children})
        IF(IS_DIRECTORY ${curdir}/${child})
            LIST(APPEND dirlist ${curdir}/${child})
        ENDIF()
    ENDFOREACH()
    SET(${result} ${dirlist})
ENDMACRO()

function(include_all_files)
    SUBDIRLIST(SUBDIRS ${CMAKE_CURRENT_SOURCE_DIR}/../3dparty/taglib/taglib/ ${CMAKE_CURRENT_SOURCE_DIR}/../3dparty/taglib/taglib)

    FOREACH(subdir ${SUBDIRS})
        include_directories(${subdir})
    ENDFOREACH()
    include_directories(src)
endfunction()

include_directories(../build/3dparty/taglib/)
include_directories(../cmake-build-debug/3dparty/taglib/)

include_all_files()
add_subdirectory(src)

add_executable(${PROJECT_NAME} ${SOURCE_EXE})
target_link_libraries(${PROJECT_NAME} src_lib tag Qt5::Core Qt5::Qml Qt5::Widgets)
