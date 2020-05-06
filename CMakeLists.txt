cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
project(lab5)
link_libraries(stdc++fs)
add_executable(${PROJECT_NAME} "main.cpp"
                               "mp3manager.cpp" "mp3manager.h"
                               "song.h" "song.cpp"
                               "mp3filemanager.h" "mp3filemanager.cpp")
