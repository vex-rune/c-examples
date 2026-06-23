cmake_minimum_required(VERSION 3.10)
project(CExamples C)

# 设置 C 标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 编译选项
add_compile_options(-Wall -Wextra)

# 启用子项目
add_subdirectory(c-base)
add_subdirectory(c-pointer)
