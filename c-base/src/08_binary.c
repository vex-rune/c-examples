#include <stdio.h>

// 二进制是单片机的基础，必须掌握

void demo_binary(void) {
    printf("=== 8. 二进制演示 ===\n");
    printf("\n");

    // 第1步：十进制和二进制对照
    printf("【第1步】十进制 vs 二进制\n");
    printf("  十进制: 0  1  2  3  4  5  6  7  8  9 10 11 12 ...\n");
    printf("  二进制: 0  1 10 11 100 101 110 111 1000 ...\n");
    printf("  printf 输出: %d %d %d %d %d\n", 0, 1, 2, 3, 4);
    printf("\n");

    // 第2步：十六进制（单片机常用）
    printf("【第2步】十六进制（单片机常用）\n");
    printf("  十六进制: 0x00 0x01 0x0F 0x10 0xFF\n");
    printf("  printf 输出十六进制: 0x%X\n", 255);
    printf("  printf 输出十六进制: 0x%02X\n", 10);
    printf("  printf 输出十六进制: 0x%04X\n", 255);
    printf("\n");

    // 第3步：8位二进制
    printf("【第3步】8位二进制（1字节）\n");
    printf("  内存中每个位:  7  6  5  4  3  2  1  0\n");
    printf("  示例数据:     1  0  1  0  1  1  0  1\n");
    int num = 0b10101101;  // C语言可以直接写二进制
    printf("  int num = 0b10101101; printf: %d\n", num);
    printf("\n");

    // 第4步：位权
    printf("【第4步】位权计算\n");
    printf("  从右到左权值: 1  2  4  8 16 32 64 128\n");
    printf("  10101011 = 1×128 + 0×64 + 1×32 + 0×16 + 1×8 + 0×4 + 1×2 + 1×1\n");
    printf("           = 128 + 0 + 32 + 0 + 8 + 0 + 2 + 1 = 171\n");
    printf("  printf: %d\n", 171);
    printf("\n");

    // 第5步：位运算
    printf("【第5步】位运算（单片机核心）\n");
    
    unsigned char a = 0b11001100;
    unsigned char b = 0b10101010;
    
    printf("  a = 0b11001100 = %d\n", a);
    printf("  b = 0b10101010 = %d\n", b);
    printf("\n");
    
    printf("  a & b (与): %d\n", a & b);
    printf("  a | b (或): %d\n", a | b);
    printf("  a ^ b (异或): %d\n", a ^ b);
    printf("  ~a   (取反): %d\n", (char)~a);
    printf("  a << 1 (左移1位): %d\n", a << 1);
    printf("  a >> 1 (右移1位): %d\n", a >> 1);
    printf("\n");

    printf("\n");
}
