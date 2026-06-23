#include <stdio.h>

// C语言运算符完全指南

void demo_operators(void) {
    printf("=== 3. 运算符演示 ===\n");
    printf("\n");

    // 第1步：算术运算符
    printf("【第1步】算术运算符 (+ - * / %%)\n");
    int a = 10, b = 3;
    printf("  a = %d, b = %d\n", a, b);
    printf("  a + b = %d\n", a + b);
    printf("  a - b = %d\n", a - b);
    printf("  a * b = %d\n", a * b);
    printf("  a / b = %d\n", a / b);
    printf("  a %% b = %d\n", a % b);
    printf("\n");

    // 第2步：自增自减
    printf("【第2步】自增自减 (++ --)\n");
    int i = 5;
    printf("  i = %d\n", i);
    printf("  i++ 后置: %d, i变为: %d\n", i++, i);
    printf("  ++i 前置: %d, i变为: %d\n", ++i, i);
    printf("  i-- 后置: %d, i变为: %d\n", i--, i);
    printf("  --i 前置: %d, i变为: %d\n", --i, i);
    printf("\n");

    // 第3步：赋值运算符
    printf("【第3步】赋值运算符 (= += -= *= /= %%=)\n");
    int x = 10;
    printf("  x = %d\n", x);
    x += 5;  printf("  x += 5  后: %d\n", x);
    x -= 3;  printf("  x -= 3  后: %d\n", x);
    x *= 2;  printf("  x *= 2  后: %d\n", x);
    x /= 4;  printf("  x /= 4  后: %d\n", x);
    x %= 3;  printf("  x %%= 3 后: %d\n", x);
    printf("\n");

    // 第4步：比较运算符
    printf("【第4步】比较运算符 (== != > < >= <=)\n");
    printf("  10 == 5: %d\n", 10 == 5);
    printf("  10 != 5: %d\n", 10 != 5);
    printf("  10 > 5:  %d\n", 10 > 5);
    printf("  10 < 5:  %d\n", 10 < 5);
    printf("  10 >= 10: %d\n", 10 >= 10);
    printf("  10 <= 5: %d\n", 10 <= 5);
    printf("\n");

    // 第5步：逻辑运算符
    printf("【第5步】逻辑运算符 (&& || !)\n");
    printf("  1 && 1: %d\n", 1 && 1);
    printf("  1 && 0: %d\n", 1 && 0);
    printf("  1 || 0: %d\n", 1 || 0);
    printf("  0 || 0: %d\n", 0 || 0);
    printf("  !1: %d\n", !1);
    printf("  !0: %d\n", !0);
    printf("\n");

    // 第6步：位运算符
    printf("【第6步】位运算符 (& | ^ ~ << >>)\n");
    unsigned char m = 204, n = 170;
    printf("  m = %d, n = %d\n", m, n);
    printf("  m & n (与): %d\n", m & n);
    printf("  m | n (或): %d\n", m | n);
    printf("  m ^ n (异或): %d\n", m ^ n);
    printf("  ~m (取反): %d\n", ~m);
    printf("  m << 1 (左移): %d\n", m << 1);
    printf("  m >> 1 (右移): %d\n", m >> 1);
    printf("\n");

    // 第7步：条件运算符
    printf("【第7步】条件运算符 (? :)\n");
    int p = 10, q = 20;
    int max = (p > q) ? p : q;
    printf("  (p > q) ? p : q\n");
    printf("  结果: max = %d\n", max);
    printf("\n");

    // 第8步：sizeof
    printf("【第8步】sizeof 运算符\n");
    printf("  sizeof(int): %zu\n", sizeof(int));
    printf("  sizeof(char): %zu\n", sizeof(char));
    printf("  sizeof(float): %zu\n", sizeof(float));
    printf("  sizeof(double): %zu\n", sizeof(double));
    printf("\n");

    // 第9步：运算符分类
    printf("【第9步】运算符分类\n");
    printf("  一元(1个操作数): ! ~ - ++ -- sizeof\n");
    printf("  二元(2个操作数): + - * / %% == != && || & |\n");
    printf("  三元(3个操作数): ? :\n");
    printf("\n");
}
