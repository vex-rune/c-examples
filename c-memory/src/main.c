/**
 * main.c - C 语言内存空间管理演示
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    printf("========================================\n");
    printf("      C 语言内存空间管理\n");
    printf("========================================\n\n");


    // ========================================
    // 1. void* 无类型指针
    // ========================================
    printf("【1】void* 无类型指针\n\n");

    void *p = NULL;
    printf("  void *p = NULL\n");
    printf("  p = %p\n\n", p);

    int a = 10;
    void *p_void = &a;  // void* 可以指向任何类型
    printf("  int a = 10\n");
    printf("  void *p_void = &a\n");
    printf("  p_void = %p\n\n", p_void);

    // void* 不能直接解引用，需要强制转换
    // printf("%d", *p_void);  // 错误！不能直接解引用
    int a_value = *((int *)p_void);  // 强制转换为 int*
    printf("  *((int *)p_void) = %d\n\n", a_value);


    // ========================================
    // 2. malloc 动态分配内存
    // ========================================
    printf("【2】malloc 动态分配内存\n\n");

    // malloc 返回 void*，需要强制转换
    int *p_int = (int *)malloc(sizeof(int));  // 分配一个 int 大小的内存
    if (p_int == NULL) {
        printf("  malloc 失败！\n");
        return 1;
    }
    printf("  int *p_int = (int *)malloc(sizeof(int))\n");
    printf("  p_int = %p\n", (void*)p_int);
    printf("  sizeof(int) = %zu 字节\n\n", sizeof(int));

    *p_int = 123;
    printf("  *p_int = %d\n\n", *p_int);

    // 数组
    int array_size = 5;
    int *p_int_array = (int *)malloc(sizeof(int) * array_size);

    if (p_int_array == NULL) {
        printf("  malloc 失败！\n");
        free(p_int);  // 先释放之前的
        return 1;
    }

    for (int i = 0; i < array_size; i++) {
        p_int_array[i] = (int)(i * 3.14);
        printf("  p_int_array[%d] = %d\n", i, p_int_array[i]);
    }

    printf("  p_int_array 大小 = %zu 字节\n\n", sizeof(int) * array_size);
    printf("  p_int_array 指向的内存地址 = %p\n", p_int_array);

    // 释放数组内存
    free(p_int_array);

    // ========================================
    // 3. struct 与 malloc
    // ========================================
    printf("【3】struct 与 malloc\n\n");

    struct Student {
        int id;
        char name[20];
    };

    struct Student *p_student = (struct Student *)malloc(sizeof(struct Student));
    if (p_student == NULL) {
        printf("  malloc 失败！\n");
        free(p_int);  // 先释放之前的
        return 1;
    }
    printf("  struct Student *p_student = (struct Student *)malloc(sizeof(struct Student))\n");
    printf("  p_student = %p\n", (void*)p_student);
    printf("  sizeof(struct Student) = %zu 字节\n\n", sizeof(struct Student));

    p_student->id = 1001;
    strcpy(p_student->name, "张三");
    printf("  p_student->id = %d\n", p_student->id);
    printf("  p_student->name = %s\n\n", p_student->name);


    // calloc() 分配内存并初始化为 0
    int *p_int_calloc = (int *)calloc(1, sizeof(int));
    // 分配 1 个 int 大小的内存，初始化为 0
    printf("  p_int_calloc = %p\n", (void*)p_int_calloc);

    if (p_int_calloc == NULL) {
        printf("  calloc 失败！\n");
        free(p_int);  // 先释放之前的
        return 1;
    }
    printf("  int *p_int_calloc = (int *)calloc(1, sizeof(int))\n");
    printf("  p_int_calloc = %p\n", (void*)p_int_calloc);
    printf("  sizeof(int) = %zu 字节\n\n", sizeof(int));

    *p_int_calloc = 1000;
    printf("  *p_int_calloc = %d\n\n", *p_int_calloc);


    // realloc() 重新分配内存
    int *p_int_realloc = NULL;
    p_int_realloc = (int *)realloc(p_int_calloc, 2 * sizeof(int));
    // 重新分配 2 个 int 大小的内存，初始化为 0
    printf("  p_int_calloc = %p\n", (void*)p_int_calloc);
    printf("  sizeof(int) * %zu = %zu 字节\n\n", 2, sizeof(p_int_calloc) * 2);
    printf("  p_int_realloc = %p\n", (void*)p_int_realloc);
    printf("  sizeof(int) * %zu = %zu 字节\n\n", 2, sizeof(p_int_realloc) * 2);

    if (p_int_realloc == NULL) {
        printf("  realloc 失败！\n");
        free(p_int_realloc);  // 先释放之前的
        return 1;
    }
    printf("  int *p_int_realloc = (int *)realloc(p_int_realloc, 2 * sizeof(int))\n");
    printf("  p_int_realloc = %p\n", (void*)p_int_realloc);
    printf("  sizeof(int) * %zu = %zu 字节\n\n", 2, sizeof(int) * 2);

    *p_int_realloc = 2000;
    printf("  *p_int_realloc = %d\n\n", *p_int_realloc);

    // 释放 2 个 int 大小的内存
    free(p_int_realloc); 


    // ========================================
    // 4. 释放内存
    // ========================================
    printf("【4】释放内存\n\n");

    printf("  free(p_int)\n");
    free(p_int);
    p_int = NULL;  // 避免野指针

    printf("  free(p_student)\n");
    free(p_student);
    p_student = NULL;  // 避免野指针

    printf("  内存已释放，指针设为 NULL\n\n");

    printf("========================================\n");
    printf("          程序执行完毕\n");
    printf("========================================\n");

    return 0;
}
