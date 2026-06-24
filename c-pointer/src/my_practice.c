#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 指针练习 - 数组与指针

void my_practice(void)
{
    // ========================================
    // 第1部分：指针基础
    // ========================================
    int arr[5] = {1, 2, 3, 4, 5};
    int *p = arr;

    printf("=== 指针基础 ===\n");
    printf("  数组 arr 的地址: %p\n", arr);
    printf("  数组 arr 第一个元素的地址: %p\n", p);
    printf("  数组 arr 第一个元素的值: %d\n", *p);

    // 指针加减
    p++;
    printf("  指针 p+1 指向的地址: %p\n", p);
    printf("  指针 p+1 指向的值: %d\n", *p);

    p--;
    printf("  指针 p-1 指向的地址: %p\n", p);
    printf("  指针 p-1 指向的值: %d\n", *p);

    // ========================================
    // 第2部分：计算数组长度
    // ========================================
    long arrLong[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t arr_len = sizeof(arrLong) / sizeof(arrLong[0]);
    int len = sizeof(arrLong);

    printf("\n=== 计算数组长度 ===\n");
    printf("  sizeof(arrLong): %zu 数组字节\n", sizeof(arrLong));
    printf("  sizeof(arrLong[0]): %zu 元素字节\n", sizeof(arrLong[0]));
    printf("  数组长度 = 总字节数 / 元素字节数 = %d / %zu = %zu\n", 
           len, sizeof(arrLong[0]), arr_len);

    // ========================================
    // 第3部分：指针遍历数组
    // ========================================
    long *plong = arrLong;  // 用 long* 指针指向 long 数组

    printf("\n=== 指针遍历数组 ===\n");
    for (int i = 0; i < arr_len; i++) {
        printf("  arrLong[%d]: 地址=%p, 值=%ld\n", 
               i, (void*)(plong + i), *(plong + i));
    }

    // ========================================
    // 第4部分：字符串与指针
    // ========================================
    char str[10] = "hello";

    printf("\n=== 字符串与指针 ===\n");
    printf("  字符串 str 的地址: %p\n", str);
    printf("  第一个字符的地址: %p\n", str);
    printf("  第一个字符的值: %c\n", *str);
    printf("  字符串长度: %zu 字节\n", sizeof(str));

    printf("\n");


    // ========================================
    // 第5部分：同类指针的加减
    // ========================================
    int *p1 = arr;
    int *p2 = p1 + 2;

    printf("  指针 p1 的地址: %p\n", p1);
    printf("  指针 p2 的地址: %p\n", p2);
    printf("  指针 p2 指向的值: %d\n", *p2);
    printf("\n");

    int *a1 = &arr[0];
    int *a2 = &arr[2];
    printf("  a1 指向的地址: %p\n", (void*)a1);
    printf("  a2 指向的地址: %p\n", (void*)a2);
    printf("  a2与a1 间隔的元素个数 = %td\n", a2 - a1);

    printf("\n");

    // ========================================
    // * 声明变量
    // * 指针指向的地址
    // & 取量的地址
    // ========================================
    int x = 10; // 整数变量
    int *px = &x; // int *px 是一个指向整数变量的指针变量， &x 是取出 x 的地址， x 的地址是 px 的值， *px 是 px 指向的值
    // x 是一个整数变量，px 是一个指向整数变量的指针变量
    printf("  x 的值: %d\n", x);
    // x 的地址是 px 的值
    printf("  x 的地址: %p\n", px);
    // px 的地址是 px 的值
    printf("  px 的地址: %p\n", &px);
    printf("  px 指向的地址: %p\n", px);
    printf("  px 指针指向的值: %d\n", *px); // *px 指向 x 的地址
    printf("  *px 的值（x的值）: %d\n", *px);
    printf("\n");

    // ========================================
    // 第6部分：野指针（演示用，实际应避免）
    // ========================================
    int *p_1 = NULL; // 野指针演示（故意不初始化，地址随机）
    printf("  p_1 的地址: %p (随机地址，因为没有初始化)\n", p_1);
    printf("\n");

    // ========================================
    // 第7部分：越界访问
    // ========================================
    int *p_2 = &arr[5]; // 越界访问，指向数组外部的地址
    printf("  p_2 的地址: %p\n", p_2);
    printf("  p_2 指针指向的值: %d\n", *p_2); // 越界访问，会出来奇怪的值9
    printf("\n");


    // ========================================
    // 第8部分：指针 NULL
    // ========================================
    int *p_3 = NULL; // 指针 NULL，指向任何地址， 会随机指向一个地址
    printf("  p_3 的地址: %p\n", p_3);
    printf("\n");

    // ========================================
    // 第9部分：二级指针
    // ========================================
    int n = 10;
    int *p_n = &n;
    int **pp_n = &p_n;

    printf("  n 的地址: %p\n", &n);
    printf("  p_n 的地址: %p\n", p_n);
    printf("  pp_n 的地址: %p\n", pp_n);
    printf("\n");

    // 使用malloc创建一个二级数组， 创建一个表格
    int row, col;
    row = 4;
    col = 5;

    // 初始化row的值
    int **table = malloc(row * sizeof(int*));
    for (int i = 0; i < row; i++) {
        table[i] = malloc(col * sizeof(int));

        // 初始化col的值
        for (int j = 0; j < col; j++) {
            table[i][j] = i * col + j;
        }
    }

    //  打印出表格
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }



    // ========================================
    // 字符串
    // ========================================

    char str2[20] = "hello， 雷鸣";

    printf("  字符串 str2: %s\n", str2);

    // 指针
    char *p_str2 = str2;
    printf("  字符串 str2 的地址: %p\n", p_str2);

    // 第二种生命方式
    char *p_str2_2 = "hello， 雷鸣";
    printf("  字符串 p_str2_2 的地址: %p\n", p_str2_2);

    // 数组名是一个常量，不能被修改值
    char str3[20] = "hello， 雷鸣";
    str3[0] = 'H';
    printf("  字符串 str3: %s\n", str3);
    // str3 = "hello， 雷鸣"; 编译不通过
    printf("  字符串 str3: %s\n", str3);
    // 字符串长度
    printf("  字符串 str3 的长度: %ld 字符\n", sizeof(str3));

    // 指针变量可以重复赋值
    char *p_str3 = "今天天气真好阿阿阿阿";
    printf("  字符串 p_str3: %s\n", p_str3);
    // 字符串长度
    printf("  字符串 p_str3 字符串的长度 : %ld 字符\n", strlen(p_str3));

    // 字符串指针不能改
    char *p_str3_2 = p_str3;
    // p_str3_2[2] = 'K'; 编译不报错, 修改回报错  段错误                  （核心已转储） ./program
    // *(p_str3_2 + 2) = 'K'; 编译不通过 段错误                  （核心已转储） ./program
        
    printf("\n");


    // ========================================
    // 字符串数组
    // 类型           内存是否连续  说明 
    // char str[][N]  ✅ 连续     整个数组在内存中是连续的一块区域 
    // char *str[]    ❌ 不一定    指针数组本身连续，但指向的字符串可能分散在各处
    // ========================================
    // 方式1 , 因为每个字符串长度不同，[10] 多余的没有用到的空间是浪费了
    char weekdays[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    printf("  字符串数组 weekdays: %s\n", weekdays[0]);

    // 循环打印字符串数组
    for (int i = 0; i < 7; i++) {
        printf("  字符串数组 weekdays[%d]: %s\n", i, weekdays[i]);
        printf("  字符串数组 weekdays[%d]: 的地址: %p\n", i, &weekdays[i][0]);
        printf("  字符串数组 weekdays[%d]: 的地址长度: %ld 字符\n", i, sizeof(weekdays[i]));
        printf("  字符串数组 weekdays[%d]: 的实际使用长度: %ld 字符\n", i, strlen(weekdays[i]));
        // 遍历打印10个字节的内容
        for (int j = 0; j < 10; j++) {
            printf("[%c]", weekdays[i][j]);
        }
        printf("\n");
    }

    // 方式2: 使用字符串指针表示
    char *month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("  字符串数组 month: %p\n", month[0]);
    int month_size = sizeof(month) / sizeof(month[0]); // 计算数组的长度
    printf("  字符串数组 month 的长度: %d\n", month_size);

    // 循环打印字符串数组
    for (int i = 0; i < month_size; i++) {
        for (int j = 0; j < strlen(month[i]); j++) {
            printf("[%c]", month[i][j]);
        }
            printf(" ");
    }
        printf("\n");


    // ========================================
    // 指向固定长度数组的指针变量
    // ========================================
    int a3[3] = {1, 2, 3};
    int *p_a3 = a3; 
    // 有警告: my_practice.c:197:11: warning: unused variable ‘p_str3_2’ [-Wunused-variable]
    // 因为: 分配了内存存指针，但全程没用，判定为未使用变量，抛出 -Wunused-variable 警告
    // 破解方法1: 用一下，printf("%d", *p_a3);
    // 破解方法2: 告诉编译器故意不用（临时调试用）`int *p_a3 __attribute__((unused)) = a3; ` 还可以这样!!!!

    // 真正指向长度为3的int数组的指针（数组指针）
    int (*arr_ptr)[3] = &a3;
    printf("a3   = %p\n", a3);
    printf("&a3  = %p\n", &a3);
    printf("arr_ptr = %p\n", arr_ptr);

    // arr_ptr++; // 地址直接 +12 字节
    // p_a3++;// 地址只 +4 字节（单个int）

    // *arr_ptr 等价于 a3，是数组首元素地址
    printf("  数组指针 arr_ptr 1 值: %d\n", (*arr_ptr)[0]); // 1
    printf("  数组指针 arr_ptr 1 值: %d\n", (*arr_ptr)[1]); // 2
    printf("  数组指针 arr_ptr 1 值: %d\n", *(*arr_ptr + 2)); // 3

    int a4[3][2] = {
        {3, 2},
        {6, 4},
        {5, 9}
    };
    int (*arr_ptr_2)[2] = a4;

    printf("  数组指针 arr_ptr_2 1 值: %d\n", (*arr_ptr_2)[0]); // 1
    printf("  数组指针 arr_ptr_2 2 值: %d\n", (*arr_ptr_2)[1]); // 2
    printf("  数组指针 arr_ptr_2 3 值: %p\n", (*arr_ptr_2 + 2)); // 3
    printf("  数组指针 arr_ptr_2 3 值: %d\n", *(*arr_ptr_2 + 2)); // 3
    printf("  数组指针 arr_ptr_2 1 值: %p\n", arr_ptr_2[1]); // 6, 4, 5, 9
    printf("  数组指针 arr_ptr_2 1 值: %d\n", *arr_ptr_2[1]); // 6, 4, 5, 9
    printf("  数组指针 arr_ptr_2 1 值: %p\n", &arr_ptr_2[1][1]); // 6, 4, 5, 9
    printf("  数组指针 arr_ptr_2 1 值: %d\n", arr_ptr_2[1][1]); // 6, 4, 5, 9

    // 遍历arr_ptr_2
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("[%p->%d]", &arr_ptr_2[i][j], arr_ptr_2[i][j]);
        }
        printf("\n");
    }

    // 测试题
    int w[3][4] = {
        {0, 1},
        {2, 4},
        {7, 8}
    };
    int (*p_w_1)[4] = w;
    int (*p_w_2)[4] = w;

    printf("  *w[1] = %d\n", *w[1]);
    printf("  *w[1]+1 = %d\n", *w[1]+1);
    p_w_1++;
    printf("  p_w_1++; *(p_w_1)= %p\n", *(p_w_1));
    printf("  p_w_1++; *(p_w_1+1)= %p\n", *(p_w_1+1));
    printf("  w[2]= %p\n", w[2]);
    printf("  w[2][2]= %d\n", w[2][2]);
    printf("  p_w_2[1]= %p\n", p_w_2[1]);
    printf("  p_w_2[1][1]= %d\n", p_w_2[1][1]);


}