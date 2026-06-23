#include <stdio.h>

// 什么是输入输出？
// - printf = 输出到屏幕（从程序向外）
// - scanf = 从键盘输入（从外向程序）
// - getchar = 输入单个字符
// - putchar = 输出单个字符

void demo_io(void) {
    printf("=== 7. 输入输出演示 ===\n");
    printf("输入输出就是程序和用户之间的\"对话\"\n");
    printf("\n");

    // 第1步：scanf 输入整数
    printf("【第1步】scanf 输入整数\n");
    printf("  scanf 会等待你从键盘输入数字\n");
    printf("\n");
    
    int num;
    printf("请输入一个整数: ");
    scanf("%d", &num);
    printf("你输入的数字是: %d\n", num);
    printf("  scanf 把输入的值存到了 num 变量中\n");
    printf("  注意：&num 的 & 是\"取地址\"，告诉scanf存到哪里\n");
    printf("\n");

    // 第2步：scanf 输入两个数字
    printf("【第2步】scanf 输入两个数字并计算\n");
    printf("  程序可以接收两个数字，进行计算后输出\n");
    printf("\n");
    
    int a, b;
    printf("请输入两个整数（用空格分开）: ");
    scanf("%d %d", &a, &b);
    printf("你输入的是: %d 和 %d\n", a, b);
    printf("  %d + %d = %d\n", a, b, a + b);
    printf("  %d - %d = %d\n", a, b, a - b);
    printf("  %d * %d = %d\n", a, b, a * b);
    if (b != 0) {
        printf("  %d / %d = %d\n", a, b, a / b);
    }
    printf("\n");

    // 第3步：getchar 输入字符
    printf("【第3步】getchar 输入字符\n");
    printf("  getchar 读取一个字符\n");
    printf("\n");
    
    printf("请输入一个字符: ");
    getchar();  // 吃掉上一个回车
    char c = getchar();
    printf("你输入的字符是: '%c'\n", c);
    printf("  字符 '%c' 的 ASCII 码是: %d\n", c, c);
    printf("\n");

    // 第4步：putchar 输出字符
    printf("【第4步】putchar 输出字符\n");
    printf("  putchar 直接输出一个字符\n");
    printf("  输出: ");
    putchar(c);
    printf("\n");
    printf("  putchar 输出后没有换行，光标留在后面\n");
    printf("\n");

    // 第5步：综合计算器
    printf("【第5步】简易计算器\n");
    printf("  输入格式: 数字1 运算符 数字2\n");
    printf("  例如: 10 + 5\n");
    printf("       8 * 3\n");
    printf("       20 / 4\n");
    printf("\n");
    
    int x, y;
    char op;
    printf("请输入（格式: 10 + 5）: ");
    scanf("%d %c %d", &x, &op, &y);
    
    printf("计算: %d %c %d = ", x, op, y);
    switch(op) {
        case '+': printf("%d\n", x + y); break;
        case '-': printf("%d\n", x - y); break;
        case '*': printf("%d\n", x * y); break;
        case '/': 
            if (y != 0) printf("%.2f\n", (float)x / y); 
            else printf("除数不能为0！\n");
            break;
        default: printf("不支持的运算符！\n");
    }
    printf("\n");

    printf("\n");
}
