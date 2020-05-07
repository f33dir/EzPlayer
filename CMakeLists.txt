cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(taglib)
project(lab5)
add_subdirectory(taglib/taglib taglib/bindings)
link_libraries(stdc++fs)
target_link_libraries( lab5 tag)
add_executable(${PROJECT_NAME} "main.cpp"
                               "mp3manager.cpp" "mp3manager.h"
                               "song.h" "song.cpp"
                               "mp3filemanager.h" "mp3filemanager.cpp")
