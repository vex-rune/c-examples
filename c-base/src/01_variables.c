#include <stdio.h>

// 什么是变量？
// 变量就像一个盒子，用来存放数据
// 盒子有名字（变量名），有类型（int、float等），有值

void demo_variables(void) {
    printf("=== 1. 变量演示 ===\n");
    printf("变量就是存放数据的\"盒子\"\n");
    printf("\n");

    // 第1步：声明一个整数变量
    printf("【第1步】声明整数变量\n");
    int age;
    printf("  int age;  // 声明了变量，还没赋值\n");
    printf("  变量声明后没有初始值，是\"未定义\"的\n");
    printf("\n");

    // 第2步：给变量赋值
    printf("【第2步】给变量赋值\n");
    age = 25;
    printf("  把 25 放进 age 这个盒子里\n");
    printf("  现在 age = %d\n", age);
    printf("\n");

    // 第3步：声明并赋值
    printf("【第3步】声明并赋值（推荐写法）\n");
    int height = 175;
    printf("  int height = 175;\n");
    printf("  同时完成声明和赋值\n");
    printf("  现在 height = %d cm\n", height);
    printf("\n");

    // 第4步：整数家族
    printf("【第4步】整数类型\n");
    
    printf("  short（短整数）: ");
    short short_num = 32767;
    printf("short_num = %d，范围: -32768 ~ 32767\n", short_num);

    printf("  int（整数）: ");
    int int_num = 100;
    printf("int_num = %d，范围: -21亿 ~ 21亿\n", int_num);

    printf("  long（长整数）: ");
    long long_num = 2147483647L;
    printf("long_num = %ld\n", long_num);

    printf("  long long（超长整数）: ");
    long long very_long = 9223372036854775807LL;
    printf("very_long = %lld\n", very_long);
    printf("\n");

    // 第5步：小数家族
    printf("【第5步】小数类型\n");
    
    printf("  float（单精度）: ");
    float float_num = 3.14f;
    printf("float_num = %.2f，精度约6-7位\n", float_num);

    printf("  double（双精度）: ");
    double double_num = 3.14159265358979;
    printf("double_num = %.14f，精度约15-16位\n", double_num);
    printf("  double 比 float 更精确！\n");
    printf("\n");

    // 第6步：字符
    printf("【第6步】字符类型\n");
    
    printf("  char（字符）: ");
    char char_num = 'A';
    printf("char_num = %c\n", char_num);
    printf("  注意：字符用单引号 ''\n");
    printf("  char 其实也是整数，'A' = %d\n", char_num);
    printf("\n");

    // 第7步：无符号类型
    printf("【第7步】无符号类型（只能存正数）\n");
    printf("  unsigned 表示\"无符号\"，只能存正数和0\n");
    printf("  unsigned int 范围: 0 ~ 42亿\n");
    
    unsigned int positive = 100;
    printf("  unsigned int positive = %u\n", positive);
    printf("  %%u 用于输出 unsigned 类型\n");

    unsigned char byte = 255;
    printf("  unsigned char byte = %d\n", byte);
    printf("  unsigned char 范围: 0 ~ 255\n");
    printf("\n");
    printf("\n");

    // 第8步：修改变量
    printf("【第8步】修改变量的值\n");
    printf("  age 原来是: %d\n", age);
    age = 26;
    printf("  age 修改后: %d\n", age);
    printf("  age 又修改为: %d\n", age = 30);
    printf("  变量可以多次修改，最后的值是: %d\n", age);
    printf("\n");

    // 第9步：多个变量
    printf("【第9步】同时声明多个变量\n");
    int a = 1, b = 2, c = 3;
    printf("  int a = 1, b = 2, c = 3;\n");
    printf("  a = %d, b = %d, c = %d\n", a, b, c);
    printf("\n");

    // 第10步：变量运算
    printf("【第10步】变量参与运算\n");
    int x = 10, y = 20;
    printf("  x = %d, y = %d\n", x, y);
    int sum = x + y;
    printf("  x + y = %d + %d = %d\n", x, y, sum);
    printf("\n");

    printf("\n");
}
