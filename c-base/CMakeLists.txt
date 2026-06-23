# c-base 项目
cmake_minimum_required(VERSION 3.10)

# 源文件
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c")

# 可执行文件
add_executable(c_base ${SOURCES})

# 头文件目录
target_include_directories(c_base PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

# 编译选项
target_compile_options(c_base PRIVATE -Wall -Wextra -std=c17)
