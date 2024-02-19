cmake_minimum_required(VERSION 3.28)

project(
  main01
  VERSION 1.0
  LANGUAGES CXX)

set(SOURCES 
src/files.cpp
src/main.cpp
)  

set(INCLUDES
    include 
)



add_executable(main01 ${SOURCES})


target_include_directories(main01 PRIVATE ${INCLUDES})

set_source_files_properties(${SOURCES} PROPERTIES LANGUAGE CXX)

file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
