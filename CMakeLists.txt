cmake_minimum_required(VERSION 3.0.0)
project(keshe VERSION 0.3.0)                                             #项目的名称
set(CMAKE_CXX_COMPILER "g++")                              

include_directories(${PROJECT_SOURCE_DIR}/Include)             #添加头文件的搜索路径
aux_source_directory(./src SrcFiles)                       #将源文件列表写在变量SrcFiles中
set(EXECUTABLE_OUTPUT_PATH  ${PROJECT_SOURCE_DIR}/bin)     #设置可执行文件输出路径
add_executable(Test ${SrcFiles}) 