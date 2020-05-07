cmake_minimum_required(VERSION 3.8)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
include_directories(taglib)
include_directories(
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib/toolkit
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib/ape
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib/mpeg
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib/mpeg/id3v1
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/taglib/mpeg/id3v2
  ${CMAKE_CURRENT_SOURCE_DIR}/taglib/bindings/c/
)
project(lab5)
add_subdirectory(taglib/taglib taglib/bindings)
link_libraries(stdc++fs)
target_link_libraries(tag)
add_executable(${PROJECT_NAME} "main.cpp"
                               "mp3manager.cpp" "mp3manager.h"
                               "song.h" "song.cpp"
                               "mp3filemanager.h" "mp3filemanager.cpp")
