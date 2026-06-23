# CMakeLists.txt 详解

CMakeLists.txt 是 CMake 的配置文件，告诉 CMake "如何编译项目"。

## 最小模板

```cmake
cmake_minimum_required(VERSION 3.10)  # 最低 CMake 版本要求
project(MyProject C)                   # 项目名称

# 源文件
file(GLOB SOURCES "src/*.c")

# 可执行文件
add_executable(my_program ${SOURCES})

# 编译选项
target_compile_options(my_program PRIVATE -Wall -std=c17)
```

## 逐行解释

### 1. cmake_minimum_required

```cmake
cmake_minimum_required(VERSION 3.10)
```

- 告诉 CMake："请使用 3.10 或更高版本"
- 必须放在文件第一行

### 2. project

```cmake
project(MyProject C)
```

- 定义项目名称
- 指定编程语言是 C

| 参数 | 作用 |
|------|------|
| `MyProject` | 项目名称 |
| `C` | 编程语言 |

### 3. file(GLOB SOURCES)

```cmake
file(GLOB SOURCES "src/*.c")
```

- 自动收集 src 目录下所有 .c 文件
- `GLOB` = 通配符匹配
- `*.c` = 所有 .c 文件

### 4. add_executable

```cmake
add_executable(program_name ${SOURCES})
```

- 创建可执行文件
- `${SOURCES}` = 引用前面定义的变量

### 5. target_compile_options

```cmake
target_compile_options(program PRIVATE -Wall -std=c17)
```

| 选项 | 作用 |
|------|------|
| `-Wall` | 显示所有警告 |
| `-Wextra` | 显示额外警告 |
| `-std=c17` | 使用 C17 标准 |
| `-g` | 包含调试信息 |

## 完整示例

```cmake
# =========================================
# CMakeLists.txt
# C 项目最小配置
# =========================================

# 1. 版本要求
cmake_minimum_required(VERSION 3.10)

# 2. 项目定义
project(CDemo C)

# 3. 设置 C 标准
set(CMAKE_C_STANDARD 17)
set(CMAKE_C_STANDARD_REQUIRED ON)

# 4. 收集源文件
file(GLOB SOURCES "src/*.c")

# 5. 创建可执行文件
add_executable(cdemo ${SOURCES})

# 6. 编译选项
target_compile_options(cdemo PRIVATE -Wall -Wextra)
```

## 常用命令

| 命令 | 作用 |
|------|------|
| `cmake ..` | 生成 Makefile |
| `make` | 编译项目 |
| `make clean` | 清理编译文件 |
| `make rebuild` | 重新编译 |

## 目录结构

```
项目/
├── CMakeLists.txt      # CMake 配置
├── src/
│   ├── main.c
│   ├── func1.c
│   └── func2.c
└── build/              # 编译输出目录
```

## 编译步骤

```bash
# 1. 创建 build 目录
mkdir build

# 2. 进入 build 目录
cd build

# 3. 生成 Makefile
cmake ..

# 4. 编译
make

# 5. 运行
./cdemo
```

## 合并命令

```bash
mkdir build && cd build && cmake .. && make
```

## 子项目配置

如果项目包含多个子项目：

```cmake
# 主 CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(MyProject C)

add_subdirectory(sub_project1)
add_subdirectory(sub_project2)
```

```cmake
# 子项目 CMakeLists.txt
cmake_minimum_required(VERSION 3.10)

file(GLOB SOURCES "src/*.c")
add_executable(sub_program ${SOURCES})
```

## 常见问题

### Q: CMakeLists.txt 放哪里？
A: 放在项目根目录。

### Q: 如何添加头文件目录？
```cmake
target_include_directories(program PRIVATE include)
```

### Q: 如何链接库？
```cmake
target_link_libraries(program m)  # 链接数学库 libm
```

### Q: 如何设置输出目录？
```cmake
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
```

## 快速模板

```cmake
cmake_minimum_required(VERSION 3.10)
project(Demo C)

file(GLOB SOURCES "src/*.c")
add_executable(demo ${SOURCES})
target_compile_options(demo PRIVATE -Wall -std=c17)
```

复制粘贴，改个项目名就能用！
