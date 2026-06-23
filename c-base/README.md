# C 语言基础

这是 C 语言的入门教程，学完这些就入门了！

## 1. 安装 gcc 编译器

gcc 是 C 语言的编译器，没有它就无法运行 C 代码。

### Windows
1. 下载 MinGW：https://www.mingw-w64.org/
2. 安装时选择 "x86_64" 架构
3. 设置环境变量，把 `C:\MinGW\bin` 添加到 Path
4. 打开 CMD，输入 `gcc --version` 测试

### macOS
```bash
# 使用 Homebrew 安装
brew install gcc
```

### Linux (Ubuntu/Debian)
```bash
sudo apt update
sudo apt install gcc
```

### 验证安装
```bash
gcc --version
```
看到类似这样的输出就成功了：
```
gcc (Ubuntu 11.4.0) 11.4.0
```

## 2. 基础命令

### 编译运行
```bash
# 编译所有 .c 文件
gcc *.c -o program

# 运行程序
./program
```

### gcc 常用选项

| 选项 | 作用 | 示例 |
|------|------|------|
| `-o name` | 指定输出文件名 | `gcc main.c -o main` |
| `-Wall` | 显示所有警告 | `gcc -Wall main.c` |
| `-std=c17` | 使用 C17 标准 | `gcc -std=c17 main.c` |
| `-c` | 只编译不链接 | `gcc -c main.c` |
| `-g` | 包含调试信息 | `gcc -g main.c` |

### 常用编译组合
```bash
# 最简单的编译
gcc main.c -o program

# 显示警告 + C17 标准
gcc -Wall -std=c17 main.c -o program

# 编译多个文件
gcc file1.c file2.c file3.c -o program

# 使用通配符编译所有 .c 文件
gcc *.c -o program
```

### 常用 Linux 命令

| 命令 | 作用 |
|------|------|
| `ls` | 查看当前目录文件 |
| `ls -l` | 查看详细信息 |
| `cd 目录` | 进入目录 |
| `cd ..` | 返回上级目录 |
| `pwd` | 查看当前路径 |
| `rm 文件` | 删除文件 |
| `cat 文件` | 查看文件内容 |

## 3. 快速开始

### 1. 进入代码目录
```bash
cd c-base/src
```

### 2. 编译
```bash
gcc -std=c17 -Wall *.c -o program
```

### 3. 运行
```bash
./program
```

## 4. 包含内容（按学习顺序）

| 文件 | 讲什么 | 简单说明 |
|------|------|---------|
| 01_variables | 变量 | 存数据的地方 |
| 02_constants | 常量 | 不能变的值 |
| 03_printf | printf | 输出函数详解 |
| 04_expressions | 表达式 | 数学计算 |
| 05_statements | 语句 | if 判断、for 循环 |
| 06_functions | 函数 | 打包的代码块 |
| 99_main | 主程序 | 程序入口 |

## 5. 代码示例

### 变量 - 存数据
```c
int age = 25;        // 整数
float height = 1.75; // 小数
char grade = 'A';    // 字符
```

### 常量 - 不能改的值
```c
#define PI 3.14      // 用 #define 定义
const int YEAR = 2024; // 用 const 定义
```

### 表达式 - 做计算
```c
int sum = 10 + 5;    // 加法
int product = 10 * 5; // 乘法
```

### 语句 - 做判断和循环
```c
if (age > 18) {
    printf("成年人\n");
}

for (int i = 1; i <= 5; i++) {
    printf("%d\n", i);
}
```

### 函数 - 包装代码
```c
int add(int a, int b) {
    return a + b;
}

int result = add(10, 20); // 调用函数
```

## 6. 常见错误

| 错误信息 | 原因 | 解决方法 |
|---------|------|---------|
| `command not found: gcc` | 没安装 gcc | 先安装 gcc |
| `; missing` | 缺少分号 | 补上 `;` |
| `undefined reference to 'xxx'` | 函数没定义 | 检查函数名拼写 |
| `warning: implicit declaration` | 没声明函数 | 在文件开头声明函数 |

## 7. 继续学习

学会这些基础后，可以学习：
- 数组：一组数据
- 指针：数据的地址
- 结构体：自定义数据类型
- 文件操作：读写文件

## 8. 参考

- 在线教程：https://www.runoob.com/cprogramming
- 书籍：《C Primer Plus》
