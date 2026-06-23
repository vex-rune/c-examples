#include <stdio.h>

// printf 详解
// printf 就像"打印机器"，把数据打印出来

void demo_printf(void) {
    printf("=== 3. printf 输出演示 ===\n");
    printf("printf 是输出函数，把内容打印到屏幕\n");
    printf("\n");

    // 第1步：最基础的 printf
    printf("【第1步】最基础的 printf\n");
    printf("  printf(\"Hello World\\n\");\n");
    printf("  输出结果: ");
    printf("Hello World\n");
    printf("  注意：\\n 表示换行\n");
    printf("\n");

    // 第2步：printf 的基本格式
    printf("【第2步】printf 的基本格式\n");
    printf("  printf(\"格式字符串\", 变量1, 变量2, ...);\n");
    printf("  printf(\"年龄是25\");\n");
    printf("  %%d 是占位符，会被变量值替换\n");
    printf("\n");

    // 第3步：整数替换符
    printf("【第3步】整数替换符\n");
    int num = 100;
    printf("  int num = 100;\n");
    printf("  printf(\"%%d\", num);\n");
    printf("  输出: %d\n", num);
    printf("\n");

    // 第4步：小数替换符
    printf("【第4步】小数替换符 %%f\n");
    float pi = 3.14159f;
    printf("  float pi = 3.14159;\n");
    printf("  printf(\"%%f\", pi);\n");
    printf("  输出: %.6f\n", pi);
    printf("  %.2f 表示保留2位小数: %.2f\n", pi, pi);
    printf("\n");

    // 第5步：字符替换符
    printf("【第5步】字符替换符 %%c\n");
    char grade = 'A';
    printf("  char grade = 'A';\n");
    printf("  printf(\"%%c\", grade);\n");
    printf("  输出: %c\n", grade);
    printf("\n");

    // 第6步：字符串替换符
    printf("【第6步】字符串替换符 %%s\n");
    printf("  printf(\"%%s\", \"Hello\");\n");
    printf("  输出: %s\n", "Hello");
    printf("\n");

    // 第7步：多个占位符
    printf("【第7步】多个占位符\n");
    int a = 10, b = 20;
    printf("  a = %d, b = %d\n", a, b);
    printf("  printf(\"%%d + %%d = %%d\", a, b, a+b);\n");
    printf("  输出: %d + %d = %d\n", a, b, a + b);
    printf("\n");

    // 第8步：特殊字符
    printf("【第8步】特殊字符\n");
    printf("  \\n 换行 - 光标移到下一行\n");
    printf("  \\t 制表 - 相当于按 Tab 键\n");
    printf("  \\\\ 反斜杠 - 输出一个 \\ 符号\n");
    printf("  \\\" 双引号 - 输出一个 \" 符号\n");
    printf("\n");

    // 第9步：对齐
    printf("【第9步】数字对齐\n");
    printf("  %%5d  右对齐，占5位: [%5d]\n", 42);
    printf("  %%-5d 左对齐，占5位: [%-5d]\n", 42);
    printf("  %%05d 补零:          [%05d]\n", 42);
    printf("\n");

    // 第10步：不同进制
    printf("【第10步】不同进制\n");
    int n = 255;
    printf("  n = %d (十进制)\n", n);
    printf("  n = 0x%x (十六进制)\n", n);
    printf("  n = %o (八进制)\n", n);
    printf("\n");

    printf("\n");
}
