#include <stdio.h>
#include <stdlib.h>

// ============================================
// 二维数组的使用
// ============================================

/**
 * 什么是二维数组？
 * 
 * 一维数组：int arr[3]     ->  一行数据
 *     [10] [20] [30]
 * 
 * 二维数组：int arr[3][4]  ->  3行4列的表格
 *     [10] [20] [30] [40]
 *     [50] [60] [70] [80]
 *     [90] [100][110][120]
 * 
 * 相当于 Java 的：
 * int[][] arr = new int[3][4];
 */

/**
 * 二维数组的内存布局
 * 
 * 二维数组在内存中是连续存储的（按行展开）
 * arr[0][0] arr[0][1] arr[0][2] arr[0][3]
 * arr[1][0] arr[1][1] arr[1][2] arr[1][3]
 * arr[2][0] arr[2][1] arr[2][2] arr[2][3]
 * 
 * 内存地址是连续的：
 * 0x100  0x104  0x108  0x10C
 * 0x110  0x114  0x118  0x11C
 * 0x120  0x124  0x128  0x12C
 */

// 定义一个 3x4 的二维数组（3行4列）
#define ROWS 3
#define COLS 4

/**
 * 声明和初始化二维数组
 */
void demo_declaration(void) {
    printf("=== 1. 二维数组的声明和初始化 ===\n\n");
    
    // ========================================
    // 方式1：声明时初始化（指定所有元素）
    // ========================================
    printf("【方式1】声明时初始化\n");
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    printf("  int matrix[3][4] = {\n");
    printf("      {1, 2, 3, 4},\n");
    printf("      {5, 6, 7, 8},\n");
    printf("      {9, 10, 11, 12}\n");
    printf("  };\n");
    printf("  matrix[1][2] = %d\n", matrix1[1][2]);  // 访问第2行第3列
    printf("\n");
    
    // ========================================
    // 方式2：声明时初始化（省略内层大括号）
    // ========================================
    printf("【方式2】省略内层大括号\n");
    int matrix2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    printf("  int matrix[3][4] = {1,2,3,4,5,6,7,8,9,10,11,12};\n");
    printf("  按行依次填入: %d\n", matrix2[2][3]);  // 访问第3行第4列
    printf("\n");
    
    // ========================================
    // 方式3：省略行数，让编译器自动推断
    // ========================================
    printf("【方式3】省略行数\n");
    int matrix3[][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };  // 自动推断为 2 行
    printf("  int matrix[][4] = {...};  // 2行\n");
    printf("  行数: %lu\n", sizeof(matrix3) / sizeof(matrix3[0]));
    printf("\n");
    
    // ========================================
    // 方式4：只初始化部分元素
    // ========================================
    printf("【方式4】只初始化部分元素\n");
    int matrix4[3][4] = {
        {1, 2},
        {3, 4, 5}
    };  // 未初始化的元素自动为 0
    printf("  int matrix[3][4] = {{1,2}, {3,4,5}};\n");
    printf("  matrix[0][2] = %d (自动补0)\n", matrix4[0][2]);
    printf("  matrix[2][0] = %d (整行自动补0)\n", matrix4[2][0]);
    printf("\n");
    
    // ========================================
    // 方式5：初始化为全0
    // ========================================
    printf("【方式5】初始化为全0\n");
    int matrix5[3][4] = {0};  // 所有元素初始化为0
    printf("  int matrix[3][4] = {0};\n");
    printf("  matrix[0][0] = %d\n", matrix5[0][0]);
    printf("\n");
}

/**
 * 访问二维数组元素
 */
void demo_access(void) {
    printf("=== 2. 访问二维数组元素 ===\n\n");
    
    int matrix[ROWS][COLS];
    
    // 给二维数组赋值（模拟一个3x4的乘法表）
    printf("【赋值】给二维数组赋值\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            matrix[i][j] = (i + 1) * (j + 1);  // (行+1) * (列+1)
        }
    }
    
    // 打印二维数组
    printf("  二维数组内容:\n");
    printf("  -----------\n");
    printf("         ");
    for (int j = 0; j < COLS; j++) {
        printf("  [%d]  ", j);
    }
    printf("\n");
    printf("         ");
    for (int j = 0; j < COLS; j++) {
        printf("------");
    }
    printf("\n");
    
    for (int i = 0; i < ROWS; i++) {
        printf("  [%d] |", i);
        for (int j = 0; j < COLS; j++) {
            printf("  %2d  ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // 访问指定元素
    printf("【访问】访问指定元素\n");
    printf("  matrix[0][0] = %d  (第1行第1列)\n", matrix[0][0]);
    printf("  matrix[1][2] = %d  (第2行第3列)\n", matrix[1][2]);
    printf("  matrix[2][3] = %d  (第3行第4列)\n", matrix[2][3]);
    printf("\n");
    
    // Java 对比
    printf("【Java 对比】\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  int[][] matrix = new int[3][4];\n");
    printf("  matrix[1][2] = 6;\n");
    printf("  int value = matrix[1][2];\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  int matrix[3][4];\n");
    printf("  matrix[1][2] = 6;\n");
    printf("  int value = matrix[1][2];\n");
    printf("\n");
}

/**
 * 二维数组与指针
 */
void demo_pointer(void) {
    printf("=== 3. 二维数组与指针 ===\n\n");
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // ========================================
    // 3.1 二维数组的名字
    // ========================================
    printf("【3.1】二维数组的名字\n");
    printf("  int matrix[3][4];\n");
    printf("\n");
    printf("  matrix         = %p  (二维数组首地址)\n", (void*)matrix);
    printf("  matrix[0]      = %p  (第1行首地址)\n", (void*)matrix[0]);
    printf("  matrix[0][0]   = %d  (第1行第1列的值)\n", matrix[0][0]);
    printf("\n");
    
    // ========================================
    // 3.2 指针的类型
    // ========================================
    printf("【3.2】指针的类型\n");
    printf("  一维数组: int arr[5]    ->  int* ptr\n");
    printf("  二维数组: int mat[3][4] ->  int (*ptr)[4]\n");
    printf("                            ^^^^^^^^\n");
    printf("                            指向 4 个 int 的数组\n");
    printf("\n");
    
    // 正确声明指向二维数组的指针
    int (*ptr)[COLS] = matrix;  // ptr 指向每一行（一行有4个int）
    
    printf("  int (*ptr)[4] = matrix;\n");
    printf("  ptr       = %p  (指向第1行)\n", (void*)ptr);
    printf("  ptr + 1   = %p  (指向第2行)\n", (void*)(ptr + 1));
    printf("  ptr + 2   = %p  (指向第3行)\n", (void*)(ptr + 2));
    printf("\n");
    
    // ========================================
    // 3.3 访问方式对比
    // ========================================
    printf("【3.3】访问方式对比\n");
    printf("  matrix[1][2] = %d\n", matrix[1][2]);
    printf("  *(ptr[1] + 2) = %d\n", *(ptr[1] + 2));
    printf("  *(*(ptr + 1) + 2) = %d  (最底层写法)\n", *(*(ptr + 1) + 2));
    printf("\n");
    
    // ========================================
    // 3.4 常见错误
    // ========================================
    printf("【3.4】常见错误\n");
    printf("  错误写法:\n");
    printf("  -----------\n");
    printf("  int *p = matrix;     // 错误！类型不匹配\n");
    printf("  // matrix 是 int[3][4]，&matrix 是 int(*)[3][4]\n");
    printf("  // p 是 int*，类型不匹配\n");
    printf("\n");
    printf("  正确写法:\n");
    printf("  -----------\n");
    printf("  int (*p)[4] = matrix;  // 正确！p指向4个int的数组\n");
    printf("\n");
    
    // ========================================
    // 3.5 sizeof 的大小
    // ========================================
    printf("【3.5】sizeof 的大小\n");
    printf("  int matrix[3][4];\n");
    printf("  sizeof(matrix)    = %zu 字节 (整个数组: 3×4×4)\n", sizeof(matrix));
    printf("  sizeof(matrix[0]) = %zu 字节 (一行: 4×4)\n", sizeof(matrix[0]));
    printf("  sizeof(matrix[0][0]) = %zu 字节 (一个元素)\n", sizeof(matrix[0][0]));
    printf("\n");
}

/**
 * 遍历二维数组
 */
void demo_traverse(void) {
    printf("=== 4. 遍历二维数组 ===\n\n");
    
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // ========================================
    // 方式1：双层 for 循环（最常用）
    // ========================================
    printf("【方式1】双层 for 循环\n");
    printf("  for (int i = 0; i < 3; i++) {\n");
    printf("      for (int j = 0; j < 4; j++) {\n");
    printf("          printf(\"%%d \", matrix[i][j]);\n");
    printf("      }\n");
    printf("  }\n");
    printf("  输出: ");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n       ");
    }
    printf("\b\b\n\n");
    
    // ========================================
    // 方式2：使用指针遍历（内存连续）
    // ========================================
    printf("【方式2】使用指针遍历\n");
    printf("  二维数组在内存中是连续存储的\n");
    printf("  int *p = &matrix[0][0];\n");
    printf("  输出: ");
    int *p = &matrix[0][0];
    for (int i = 0; i < ROWS * COLS; i++) {
        printf("%2d ", *(p + i));
    }
    printf("\n");
    printf("  内存布局: [1][2][3][4][5][6][7][8][9][10][11][12]\n");
    printf("            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("            按行展开，连续存储\n");
    printf("\n");
    
    // ========================================
    // 方式3：使用指向行的指针
    // ========================================
    printf("【方式3】使用指向行的指针\n");
    printf("  int (*ptr)[4] = matrix;\n");
    printf("  for (int i = 0; i < 3; i++) {\n");
    printf("      for (int j = 0; j < 4; j++) {\n");
    printf("          printf(\"%%d \", *(*(ptr+i)+j));\n");
    printf("      }\n");
    printf("  }\n");
    printf("  输出: ");
    int (*ptr)[COLS] = matrix;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", *(*(ptr + i) + j));
        }
    }
    printf("\n\n");
    
    // Java 对比
    printf("【Java 对比】\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  int[][] matrix = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};\n");
    printf("  for (int i = 0; i < matrix.length; i++) {\n");
    printf("      for (int j = 0; j < matrix[i].length; j++) {\n");
    printf("          System.out.print(matrix[i][j] + \" \");\n");
    printf("      }\n");
    printf("  }\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  int matrix[3][4] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}};\n");
    printf("  for (int i = 0; i < 3; i++) {\n");
    printf("      for (int j = 0; j < 4; j++) {\n");
    printf("          printf(\"%%d \", matrix[i][j]);\n");
    printf("      }\n");
    printf("  }\n");
    printf("\n");
}

/**
 * 二维数组作为函数参数
 */
void demo_function_param(void) {
    printf("=== 5. 二维数组作为函数参数 ===\n\n");
    
    int matrix[ROWS][COLS] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // ========================================
    // 5.1 传递二维数组
    // ========================================
    printf("【5.1】传递二维数组\n");
    printf("  C 中二维数组作为参数：\n");
    printf("  -----------------------\n");
    printf("  void printMatrix(int mat[][4], int rows) { ... }\n");
    printf("  或\n");
    printf("  void printMatrix(int (*mat)[4], int rows) { ... }\n");
    printf("\n");
    printf("  注意：第二维的大小必须指定！\n");
    printf("  因为 C 需要知道每一行有多少个元素才能正确寻址\n");
    printf("\n");
    
    // 打印矩阵的函数
    for (int i = 0; i < ROWS; i++) {
        printf("  第%d行: ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%2d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // ========================================
    // 5.2 为什么第二维必须指定？
    // ========================================
    printf("【5.2】为什么第二维必须指定？\n");
    printf("  假设 matrix[3][4]，要访问 matrix[1][2]：\n");
    printf("\n");
    printf("  地址 = 首地址 + 行号 × 每行字节数 + 列号 × 元素字节数\n");
    printf("       = base     + 1      × (4×4)    + 2      × 4\n");
    printf("       = base     + 16              + 8\n");
    printf("       = base     + 24\n");
    printf("\n");
    printf("  如果不指定列数，就不知道 \"每行字节数\" 是多少\n");
    printf("  无法计算出正确的内存地址！\n");
    printf("\n");
    
    // ========================================
    // 5.3 第一维可以省略
    // ========================================
    printf("【5.3】第一维可以省略\n");
    printf("  void func(int mat[][4])    // 正确：可以省略第一维\n");
    printf("  void func(int mat[3][4])   // 也可以：3 会被忽略\n");
    printf("  void func(int mat[][])     // 错误：第二维不能省略\n");
    printf("\n");
}

/**
 * 动态分配二维数组
 */
void demo_dynamic(void) {
    printf("=== 6. 动态分配二维数组 ===\n\n");
    
    int rows = 3, cols = 4;
    
    // ========================================
    // 方式1：分配连续内存（推荐）
    // ========================================
    printf("【方式1】分配连续内存（推荐）\n");
    printf("  int *data = malloc(rows * cols * sizeof(int));\n");
    printf("  优点：内存连续，访问效率高\n");
    
    int *data = (int*)malloc(rows * cols * sizeof(int));
    if (data == NULL) {
        printf("  内存分配失败！\n");
        return;
    }
    
    // 赋值
    for (int i = 0; i < rows * cols; i++) {
        data[i] = (i / cols + 1) * (i % cols + 1);
    }
    
    // 访问（使用宏或函数模拟 matrix[i][j]）
    printf("  data[%d][%d] = %d\n", 1, 2, data[1 * cols + 2]);  // matrix[1][2]
    
    // 释放
    // free(data);
    printf("  free(data)\n\n");
    
    // ========================================
    // 方式2：分配指针数组
    // ========================================
    printf("【方式2】分配指针数组\n");
    printf("  int **matrix = malloc(rows * sizeof(int*));\n");
    printf("  for (int i = 0; i < rows; i++)\n");
    printf("      matrix[i] = malloc(cols * sizeof(int));\n");
    printf("  优点：每行可以独立分配和释放\n");
    
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    
    // 赋值
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (i + 1) * (j + 1);
        }
    }
    
    // 访问
    printf("  matrix[%d][%d] = %d\n", 1, 2, matrix[1][2]);
    
    // 释放（先释放每行，再释放指针数组）
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    printf("  for (i) free(matrix[i]);\n");
    printf("  free(matrix)\n\n");
    
    // ========================================
    // 方式3：分配指针数组（行内存连续）
    // ========================================
    printf("【方式3】指针数组 + 连续数据区（最优）\n");
    printf("  int **matrix = malloc(rows * sizeof(int*));\n");
    printf("  int *data = malloc(rows * cols * sizeof(int));\n");
    printf("  for (i) matrix[i] = data + i * cols;\n");
    
    int **matrix2 = (int**)malloc(rows * sizeof(int*));
    int *data2 = (int*)malloc(rows * cols * sizeof(int));
    for (int i = 0; i < rows; i++) {
        matrix2[i] = data2 + i * cols;
    }
    
    // 赋值
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix2[i][j] = (i + 1) * (j + 1);
        }
    }
    
    // 访问
    printf("  matrix2[%d][%d] = %d\n", 1, 2, matrix2[1][2]);
    
    // 释放
    free(data2);
    free(matrix2);
    printf("  free(data2); free(matrix2);  // 只释放2块内存\n\n");
    
    // Java 对比
    printf("【Java 对比】\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  int[][] matrix = new int[3][4];  // 自动分配\n");
    printf("  // Java 会自动管理内存\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  int **matrix = malloc(sizeof(int*) * rows);\n");
    printf("  for (i) matrix[i] = malloc(sizeof(int) * cols);\n");
    printf("  // 必须手动 free 每行和 matrix\n");
    printf("\n");
}

/**
 * 主演示函数
 */
void demo_2d_array(void) {
    printf("############################################\n");
    printf("#                                          #\n");
    printf("#         8. 二维数组的使用                 #\n");
    printf("#                                          #\n");
    printf("############################################\n\n");
    
    demo_declaration();
    demo_access();
    demo_pointer();
    demo_traverse();
    demo_function_param();
    demo_dynamic();
}
