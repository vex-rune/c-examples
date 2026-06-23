#include <stdio.h>

// 指针与函数 - 传址调用

// 交换两个数的值
void swap(int *a, int *b) {
    printf("  swap: *a=%d, *b=%d\n", *a, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("  swap后: *a=%d, *b=%d\n", *a, *b);
}

// 求最大值
int* find_max(int *arr, int len) {
    int *pmax = arr;
    for (int i = 1; i < len; i++) {
        if (arr[i] > *pmax) {
            pmax = &arr[i];
        }
    }
    return pmax;
}

void demo_pointer_function(void) {
    printf("=== 3. 指针与函数 ===\n");
    printf("\n");

    // 第1步：值传递 vs 地址传递
    printf("【第1步】值传递 vs 地址传递\n");
    printf("  Java: 传递引用，修改会影响原对象\n");
    printf("  C: 传递值或地址，需要区分\n");
    printf("\n");

    // 第2步：通过指针修改外部变量
    printf("【第2步】通过指针修改外部变量\n");
    int x = 10, y = 20;
    printf("  调用前: x=%d, y=%d\n", x, y);
    swap(&x, &y);
    printf("  调用后: x=%d, y=%d\n", x, y);
    printf("  注意: swap函数通过指针修改了x和y的值！\n");
    printf("\n");

    // 第3步：返回指针
    printf("【第3步】返回指针\n");
    int nums[] = {3, 7, 2, 9, 5};
    int *pmax = find_max(nums, 5);
    printf("  数组: 3 7 2 9 5\n");
    printf("  最大值: %d, 地址: %p\n", *pmax, pmax);
    printf("  指针可以指向数组元素并返回\n");
    printf("\n");

    // 第4步：函数指针
    printf("【第4步】函数指针\n");
    int (*pfunc)(int, int) = NULL;  // 声明函数指针
    printf("  int (*pfunc)(int, int) // 指向返回int、两个int参数的函数\n");
    printf("\n");

    // 第5步：指针数组
    printf("【第5步】指针数组\n");
    char *names[] = {"Alice", "Bob", "Charlie"};
    printf("  char *names[] = {\"Alice\", \"Bob\", \"Charlie\"};\n");
    for (int i = 0; i < 3; i++) {
        printf("  names[%d] = %s\n", i, names[i]);
    }
    printf("  指针数组：每个元素都是指针\n");
    printf("\n");

    // 第6步：const修饰指针
    printf("【第6步】const修饰指针\n");
    int value = 100;
    const int *pc = &value;  // 不能通过pc修改value
    // *pc = 200;  // 错误！不能修改
    printf("  const int *pc = &value;\n");
    printf("  不能通过 *pc 修改 value\n");
    printf("  但可以 pc = &value 改变指向\n");
    printf("\n");
}
