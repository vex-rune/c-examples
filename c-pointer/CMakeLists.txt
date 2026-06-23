# c-pointer 项目
cmake_minimum_required(VERSION 3.10)
project(CPointer C)

# 源文件
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# 可执行文件
add_executable(c_pointer ${SOURCES})

# 头文件目录
target_include_directories(c_pointer PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 编译选项
target_compile_options(c_pointer PRIVATE -Wall -Wextra -std=c17)
