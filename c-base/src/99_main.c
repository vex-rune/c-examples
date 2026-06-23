#include <stdio.h>

// ========================================
// 函数声明
// ========================================
// 语法：返回值类型 函数名(参数类型);
// 
// 作用：告诉编译器"有这个函数"，避免"找不到函数"的错误
// 
// 为什么需要？
// - main.c 在最前面，但实际函数定义在其他文件
// - 编译器从前往后读，需要提前知道这些函数存在
// 
// 类比：像书的目录，告诉读者"后面有这些章节"
// ========================================

// void demo_variables(void);
//    ↑     ↑              ↑
//  返回   函数名         参数列表（void表示无参数）
//  类型

void demo_variables(void);    // 声明：这是一个返回void的函数
void demo_constants(void);    // 声明：这是一个返回void的函数
void demo_operators(void);   // 声明：这是一个返回void的函数
void demo_statements(void);   // 声明：这是一个返回void的函数
void demo_functions(void);    // 声明：这是一个返回void的函数
void demo_printf(void);      // 声明：这是一个返回void的函数
void demo_io(void);          // 声明：这是一个返回void的函数
void demo_binary(void);      // 声明：这是一个返回void的函数
void demo_array(void);      // 声明：这是一个返回void的函数
void demo_memory(void);     // 声明：这是一个返回void的函数

// 主函数 - 程序入口
int main(void) {
    printf("========================================\n");
    printf("      C 语言基础学习示例程序\n");
    printf("========================================\n\n");

    // 依次运行各个演示（按文件顺序）
    demo_variables();    // 01_变量
    demo_constants();    // 02_常量
    demo_operators();   // 03_运算符
    demo_printf();      // 04_printf
    demo_statements();   // 05_语句
    demo_functions();    // 06_函数
    demo_io();          // 07_io 输入输出
    demo_binary();      // 08_binary 二进制
    demo_array();      // 09_数组
    demo_memory();     // 10_内存管理

    printf("========================================\n");
    printf("          程序执行完毕\n");
    printf("========================================\n");

    return 0;
}
