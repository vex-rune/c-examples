#include <stdio.h>

// 指针基础 - 理解地址和指针

void demo_pointer_basic(void) {
    printf("=== 1. 指针基础 ===\n");
    printf("\n");

    // 第1步：变量和地址
    printf("【第1步】变量和地址\n");
    int num = 100;
    printf("  int num = 100;\n");
    printf("  num 的值: %d\n", num);
    printf("  num 的地址: %p\n", &num);
    printf("  & 是取地址符\n");
    printf("\n");

    // 第2步：指针变量
    printf("【第2步】指针变量\n");
    int *ptr;        // 声明指针变量
    ptr = &num;      // 指针指向num的地址
    printf("  int *ptr = &num;\n");
    printf("  ptr 的值（存的地址）: %p\n", ptr);
    printf("  ptr 指向的地址的内容: %d\n", *ptr);
    printf("  * 是取值符，通过地址找到值\n");
    printf("\n");

    // 第3步：通过指针修改变量
    printf("【第3步】通过指针修改变量\n");
    printf("  修改前: num = %d\n", num);
    *ptr = 200;  // 通过指针修改num的值
    printf("  *ptr = 200; // 通过指针修改\n");
    printf("  修改后: num = %d\n", num);
    printf("  注意: *ptr 和 num 是同一个东西！\n");
    printf("\n");

    // 第4步：指针大小
    printf("【第4步】指针大小\n");
    printf("  指针存储的是地址\n");
    printf("  sizeof(int*): %zu 字节\n", sizeof(int*));
    printf("  sizeof(char*): %zu 字节\n", sizeof(char*));
    printf("  所有指针大小相同（都是地址）\n");
    printf("\n");

    // 第5步：指针类型
    printf("【第5步】指针类型\n");
    int i = 10;
    float f = 3.14f;
    
    int *pi = &i;
    printf("  int *pi = &i;\n");
    printf("  int *pi 的地址: %p\n", pi);
    printf("  int *pi 指向的地址的内容: %d\n", *pi);
    float *pf = &f;
    printf("  float *pf = &f;\n");
    printf("  float *pf 的地址: %p\n", pf);
    printf("  float *pf 指向的地址的内容: %.1f\n", *pf);
    
    printf("  int *pi 指向 int\n");
    printf("  float *pf 指向 float\n");
    printf("  指针类型决定取值时读多少字节\n");
    printf("\n");

    // 第6步：NULL指针
    printf("【第6步】NULL指针（空指针）\n");
    int *pnull = NULL;
    printf("  int *pnull = NULL;\n");
    printf("  NULL 就是 0，表示不指向任何地址\n");
    printf("  使用指针前要检查是否为NULL\n");
    if (pnull == NULL) {
        printf("  pnull == NULL，没有指向有效地址\n");
    }
    printf("\n");
}
