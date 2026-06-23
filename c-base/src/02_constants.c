#include <stdio.h>

// 什么是常量？
// 常量就是不能改变的值，就像刻在石头上的字

// 常量定义方式
// #define 叫做"宏定义"，"宏"就是"替代品"的意思
// 编译器会自动把 PI 替换成 3.14159（文本替换）

#define PI 3.14159        // 圆周率
#define MAX_SIZE 100      // 最大尺寸
#define NAME "C语言"       // 字符串常量
#define TRUE 1             // 真
#define FALSE 0             // 假

void demo_constants(void) {
    printf("=== 2. 常量演示 ===\n");
    printf("常量就是不能改变的值\n");
    printf("\n");

    // 第1步：#define 定义常量
    printf("【第1步】#define 定义常量（宏定义）\n");
    printf("  #define PI 3.14159\n");
    printf("  \"宏\"就是\"替代品\"，编译器会把 PI 自动替换成 3.14159\n");
    printf("  PI = %.5f\n", PI);
    printf("  注意：#define 后面没有分号\n");
    printf("\n");

    // 第2步：多个常量
    printf("【第2步】定义多个常量\n");
    printf("  MAX_SIZE = %d\n", MAX_SIZE);
    printf("  NAME = %s\n", NAME);
    printf("  TRUE = %d, FALSE = %d\n", TRUE, FALSE);
    printf("\n");

    // 第3步：const 定义常量
    printf("【第3步】const 定义常量\n");
    printf("  const int YEAR = 2024;\n");
    const int YEAR = 2024;
    printf("  YEAR = %d\n", YEAR);
    printf("  const 表示\"只读\"，值不能修改\n");
    printf("\n");

    // 第4步：const 保护数据
    printf("【第4步】const 保护数据\n");
    const float TAX_RATE = 0.15f;
    printf("  const float TAX_RATE = %.2f;\n", TAX_RATE);
    printf("  税率是 %.2f%%\n", TAX_RATE * 100);
    printf("  如果尝试修改，编译会报错！\n");
    printf("\n");

    // 第5步：枚举常量
    printf("【第5步】枚举常量\n");
    printf("  枚举可以定义一组相关常量\n");
    
    enum week {
        SUNDAY = 0,    // 星期日
        MONDAY = 1,    // 星期一
        TUESDAY = 2,   // 星期二
        WEDNESDAY = 3, // 星期三
        THURSDAY = 4,  // 星期四
        FRIDAY = 5,    // 星期五
        SATURDAY = 6   // 星期六
    };

    printf("  enum week { SUNDAY=0, MONDAY=1, ... };\n");
    printf("  MONDAY = %d\n", MONDAY);
    printf("  FRIDAY = %d\n", FRIDAY);

    enum week today = WEDNESDAY;
    printf("  today = WEDNESDAY = %d\n", today);
    printf("\n");

    // 第6步：常量的特点
    printf("【第6步】常量 vs 变量\n");
    printf("  变量可以改: int age = 25; age = 30; ✓\n");
    printf("  常量不能改: #define PI 3.14; PI = 3.0; ✗\n");
    printf("  PI 永远是 %.5f\n", PI);
    printf("  YEAR 永远是 %d\n", YEAR);
    printf("\n");

    printf("\n");
}
