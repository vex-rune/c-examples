#include <stdio.h>
#include <stdlib.h>

// 二级指针 - 指向指针的指针

void demo_pointer_pointer(void) {
    printf("=== 6. 二级指针 ===\n");
    printf("二级指针：指向指针的指针\n");
    printf("\n");

    // ========================================
    // 第1部分：理解指针的指针
    // ========================================
    printf("【第1步】一级指针\n");
    int num = 100;
    int *p1 = &num;  // p1 是 int*，指向 int

    printf("  int num = 100;\n");
    printf("  int *p1 = &num;\n");
    printf("  p1 的值（地址）: %p\n", (void*)p1);
    printf("  *p1 的值: %d\n", *p1);
    printf("  p1 指向 num\n");
    printf("\n");

    // 第2步：二级指针
    printf("【第2步】二级指针\n");
    int **p2 = &p1;  // p2 是 int**，指向 int*

    printf("  int **p2 = &p1;\n");
    printf("  p2 的值（地址）: %p\n", (void*)p2);
    printf("  *p2 的值（就是p1的值）: %p\n", (void*)*p2);
    printf("  **p2 的值: %d\n", **p2);
    printf("  p2 指向 p1，p1 指向 num\n");
    printf("\n");

    // 第3步：通过二级指针修改值
    printf("【第3步】通过二级指针修改值\n");
    printf("  修改前: num = %d\n", num);
    **p2 = 200;  // 通过二级指针修改 num
    printf("  **p2 = 200;\n");
    printf("  修改后: num = %d\n", num);
    printf("\n");

    // ========================================
    // 第4部分：图解内存关系
    // ========================================
    printf("【第4步】内存关系图\n");
    printf("  num   = 200   (地址: %p)\n", (void*)&num);
    printf("   ↑\n");
    printf("  p1    = %p  (指向 num)\n", (void*)p1);
    printf("   ↑\n");
    printf("  p2    = %p  (指向 p1)\n", (void*)p2);
    printf("  \n");
    printf("  p2 -> p1 -> num\n");
    printf("  **p2 == num\n");
    printf("\n");

    // ========================================
    // 第5部分：指针数组与二级指针
    // ========================================
    printf("【第5步】指针数组与二级指针\n");
    int a = 10, b = 20, c = 30;
    int *arr[] = {&a, &b, &c};  // 指针数组
    int **pp = arr;  // 二级指针指向指针数组

    printf("  int a=10, b=20, c=30;\n");
    printf("  int *arr[] = {&a, &b, &c};\n");
    printf("  int **pp = arr;\n");
    printf("  \n");
    printf("  pp[0] 指向 a: %d\n", *pp[0]);
    printf("  pp[1] 指向 b: %d\n", *pp[1]);
    printf("  pp[2] 指向 c: %d\n", *pp[2]);
    printf("\n");

    // ========================================
    // 第6部分：二级指针在函数中的应用
    // ========================================
    printf("【第6步】二级指针在函数参数中\n");
    printf("  如果函数要修改指针本身，需要传二级指针\n");
    printf("  \n");
    printf("  void func(int **pp) {\n");
    printf("      *pp = &another_var;  // 修改指针的值\n");
    printf("  }\n");
    printf("  \n");
    printf("  Java: 直接传对象引用即可\n");
    printf("  C:    需要用二级指针模拟\n");
    printf("\n");

    // ========================================
    // 第7部分：malloc与二级指针
    // ========================================
    printf("【第7步】malloc与二级指针\n");
    int **pptr = (int**)malloc(sizeof(int*));  // 分配指针的指针
    *pptr = (int*)malloc(sizeof(int));          // 分配 int 的指针

    **pptr = 999;
    printf("  int **pptr = malloc(sizeof(int*));\n");
    printf("  *pptr = malloc(sizeof(int));\n");
    printf("  **pptr = 999;\n");
    printf("  结果: **pptr = %d\n", **pptr);

    free(*pptr);
    free(pptr);
    printf("  使用后要释放两层内存！\n");
    printf("\n");
}
