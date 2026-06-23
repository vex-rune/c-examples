#include <stdio.h>

// 指针与数组 - 核心概念

void demo_pointer_array(void) {
    printf("=== 2. 指针与数组 ===\n");
    printf("\n");

    // 第1步：数组名就是指针
    printf("【第1步】数组名就是指针\n");
    int arr[] = {10, 20, 30, 40, 50};
    printf("  int arr[] = {10, 20, 30, 40, 50};\n");
    printf("  arr == &arr[0]: %p == %p\n", arr, &arr[0]);
    printf("  数组名 arr 就是首元素的地址！\n");
    printf("\n");

    // 第2步：通过指针访问数组
    printf("【第2步】通过指针访问数组\n");
    int *p = arr;  // p指向arr[0]
    printf("  int *p = arr; // p指向arr[0]\n");
    printf("  *p     = %d  (等价于 arr[0])\n", *p);
    printf("  *(p+1) = %d  (等价于 arr[1])\n", *(p+1));
    printf("  *(p+2) = %d  (等价于 arr[2])\n", *(p+2));
    printf("  p[i]   = %d  (等价于 arr[i])\n", p[2]);
    printf("\n");

    // 第3步：指针运算
    printf("【第3步】指针运算\n");
    p = arr;
    printf("  p = arr, p = %p\n", p);
    p = p + 1;
    printf("  p = p + 1, p = %p\n", p);
    printf("  指针+1 跳过一个元素（int跳4字节）\n");
    printf("  *p = %d (arr[1])\n", *p);
    printf("\n");

    // 第4步：遍历数组的两种方式
    printf("【第4步】遍历数组的两种方式\n");
    printf("  方式1: 下标法\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");
    
    printf("  方式2: 指针法\n");
    int *pend = arr + 5;
    for (int *pp = arr; pp < pend; pp++) {
        printf("  *pp = %d\n", *pp);
    }
    printf("\n");

    // 第5步：指针与字符串
    printf("【第5步】指针与字符串\n");
    char str[] = "Hello";
    char *ps = str;
    printf("  char str[] = \"Hello\";\n");
    printf("  char *ps = str;\n");
    printf("  字符串: %s\n", ps);
    printf("  逐字符: ");
    while (*ps != '\0') {
        printf("%c", *ps);
        ps++;
    }
    printf("\n");
    printf("  \\0 是字符串结束标志\n");
    printf("\n");

    // 第6步：数组作为函数参数
    printf("【第6步】数组作为函数参数\n");
    printf("  函数参数中的 int arr[] 和 int *arr 等价\n");
    printf("  void func(int arr[], int len)\n");
    printf("  void func(int *arr, int len)\n");
    printf("  传递的是首地址，不是整个数组\n");
    printf("\n");
}
