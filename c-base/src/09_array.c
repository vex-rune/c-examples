#include <stdio.h>

// C语言数组进阶指南

void demo_array(void) {
    printf("=== 9. 数组进阶演示 ===\n");
    printf("数组是一组相同类型的数据\n");
    printf("\n");

    // 第1步：数组基本使用
    printf("【第1步】数组基本使用\n");
    int arr[5] = {10, 20, 30, 40, 50};
    printf("  int arr[5] = {10, 20, 30, 40, 50};\n");
    printf("  arr[0] = %d\n", arr[0]);
    printf("  arr[1] = %d\n", arr[1]);
    printf("  arr[4] = %d\n", arr[4]);
    printf("\n");

    // 第2步：数组遍历
    printf("【第2步】数组遍历\n");
    printf("  遍历数组 arr:\n");
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d\n", i, arr[i]);
    }
    printf("\n");

    // 第3步：数组求和
    printf("【第3步】数组求和\n");
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += arr[i];
    }
    printf("  数组总和: %d\n", sum);
    printf("  数组平均: %.1f\n", (float)sum / 5);
    printf("\n");

    // 第4步：数组复制
    printf("【第4步】数组复制\n");
    int source[5] = {1, 2, 3, 4, 5};
    int dest[5];
    printf("  source: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", source[i]);
    }
    printf("\n");
    
    // 复制数组
    for (int i = 0; i < 5; i++) {
        dest[i] = source[i];
    }
    
    printf("  dest:   ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");
    printf("\n");

    // 第5步：数组反转
    printf("【第5步】数组反转\n");
    int original[5] = {1, 2, 3, 4, 5};
    int reversed[5];
    printf("  原始数组: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", original[i]);
    }
    printf("\n");
    
    // 反转
    for (int i = 0; i < 5; i++) {
        reversed[i] = original[4 - i];
    }
    
    printf("  反转数组: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", reversed[i]);
    }
    printf("\n");
    printf("\n");

    // 第6步：二维数组
    printf("【第6步】二维数组\n");
    int matrix[2][3] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    printf("  int matrix[2][3] = {{1,2,3}, {4,5,6}};\n");
    printf("  2行3列的矩阵:\n");
    for (int row = 0; row < 2; row++) {
        printf("  第%d行: ", row + 1);
        for (int col = 0; col < 3; col++) {
            printf("%d ", matrix[row][col]);
        }
        printf("\n");
    }
    printf("\n");

    // 第7步：二维数组访问
    printf("【第7步】二维数组元素访问\n");
    printf("  matrix[0][0] = %d\n", matrix[0][0]);
    printf("  matrix[0][2] = %d\n", matrix[0][2]);
    printf("  matrix[1][1] = %d\n", matrix[1][1]);
    printf("\n");

    // 第8步：字符数组（字符串）
    printf("【第8步】字符数组（字符串）\n");
    char str[] = "Hello";
    printf("  char str[] = \"Hello\";\n");
    printf("  str[0] = '%c'\n", str[0]);
    printf("  str[1] = '%c'\n", str[1]);
    printf("  printf(\"%%s\", str): %s\n", str);
    printf("\n");

    printf("\n");
}
