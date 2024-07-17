cmake_minimum_required(VERSION 3.5)
project(PerfLearn)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pg")

aux_source_directory(src sourceFiles)

add_executable(${PROJECT_NAME} ${sourceFiles})


