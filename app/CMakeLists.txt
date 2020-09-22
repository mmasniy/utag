cmake_minimum_required(VERSION 3.16.5)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED YES)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)

find_library(TAGLIB taglib)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

include_directories(../3dparty/taglib/taglib/)
include_directories(../3dparty/taglib/taglib/mpeg/)
include_directories(../3dparty/taglib/taglib/mpeg/id3v2/)
include_directories(../3dparty/taglib/taglib/frames/)
include_directories(../3dparty/taglib/taglib/toolkit)
include_directories(../build/3dparty/taglib/)
include_directories(../cmake-build-debug/3dparty/taglib/)


set(SOURCES main.cpp src/mainwindow.cpp src/MainTable.cpp src/Application.cpp src/FileTag.cpp)
set(HEADERS src/mainwindow.h src/Application.h src/FileTag.h src/MainTable.h)
set(UI src/mainwindow.ui)

add_executable(utag ${SOURCES} ${HEADERS} ${UI})

#add_subdirectory(src)
include_directories(./src)

target_link_libraries(utag tag Qt5::Core Qt5::Widgets)

