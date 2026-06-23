#include <stdio.h>
#include <stdlib.h>

// C语言内存管理指南

void demo_memory(void) {
    printf("=== 10. 内存管理演示 ===\n");
    printf("C语言需要手动管理内存，不像Java有垃圾回收\n");
    printf("\n");

    // 第1步：malloc 申请内存
    printf("【第1步】malloc 申请内存\n");
    int *ptr = (int*)malloc(sizeof(int));
    printf("  int *ptr = malloc(sizeof(int));\n");
    printf("  申请了 %zu 字节内存\n", sizeof(int));
    if (ptr != NULL) {
        *ptr = 100;
        printf("  *ptr = %d\n", *ptr);
    }
    printf("\n");

    // 第2步：free 释放内存
    printf("【第2步】free 释放内存\n");
    printf("  free(ptr);  // 必须释放！\n");
    free(ptr);
    ptr = NULL;  // 释放后置空，避免野指针
    printf("  释放后 ptr = NULL\n");
    printf("\n");

    // 第3步：申请数组内存
    printf("【第3步】申请数组内存\n");
    int *arr = (int*)malloc(5 * sizeof(int));
    printf("  int *arr = malloc(5 * sizeof(int));\n");
    printf("  申请了 %zu 字节\n", 5 * sizeof(int));
    
    // 初始化数组
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }
    printf("  arr: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);
    arr = NULL;
    printf("  free(arr) 释放内存\n");
    printf("\n");

    // 第4步：calloc（申请并初始化为0）
    printf("【第4步】calloc 申请并清零\n");
    int *arr2 = (int*)calloc(5, sizeof(int));
    printf("  int *arr2 = calloc(5, sizeof(int));\n");
    printf("  calloc 自动初始化为0\n");
    printf("  arr2: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr2[i]);
    }
    printf("\n");
    free(arr2);
    arr2 = NULL;
    printf("\n");

    // 第5步：realloc 调整大小
    printf("【第5步】realloc 调整内存大小\n");
    int *ptr2 = (int*)malloc(3 * sizeof(int));
    ptr2[0] = 10; ptr2[1] = 20; ptr2[2] = 30;
    printf("  原数组: ");
    for (int i = 0; i < 3; i++) printf("%d ", ptr2[i]);
    printf("\n");
    
    ptr2 = (int*)realloc(ptr2, 5 * sizeof(int));
    printf("  realloc 后: ");
    ptr2[3] = 40; ptr2[4] = 50;
    for (int i = 0; i < 5; i++) printf("%d ", ptr2[i]);
    printf("\n");
    free(ptr2);
    ptr2 = NULL;
    printf("\n");

    // 第6步：内存泄漏示例
    printf("【第6步】内存泄漏\n");
    printf("  malloc 后不 free，会导致内存泄漏\n");
    printf("  泄漏: malloc 后丢失指针，无法释放\n");
    printf("  正确: malloc -> 使用 -> free\n");
    printf("\n");

    // 第7步：野指针
    printf("【第7步】野指针（危险！）\n");
    int *wild = (int*)malloc(sizeof(int));
    *wild = 100;
    printf("  wild = %d\n", *wild);
    free(wild);
    printf("  free(wild) 后\n");
    printf("  wild = %p (地址还在，但内存已释放)\n", (void*)wild);
    wild = NULL;  // 必须置空！
    printf("  wild = NULL (安全)\n");
    printf("  野指针危害: 访问已释放的内存！\n");
    printf("\n");

    printf("\n");
}
