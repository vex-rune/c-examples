/**
 * main.c - C 语言文件操作演示
 * 
 * C 语言使用 FILE* 进行文件操作
 * 相当于 Java 的 FileInputStream/FileOutputStream
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    printf("========================================\n");
    printf("      C 语言文件操作演示\n");
    printf("========================================\n\n");

    // // stdin 标准输入
    // printf("  stdin 标准输入：\n");
    // char input[256];
    // fgets(input, sizeof(input), stdin);
    // printf("  你输入的内容是：%s", input);

    // stdout 标准输出
    printf("  stdout 标准输出：\n");
    printf("  你好，世界！\n");

    // stderr 标准错误输出
    printf("  stderr 标准错误输出：\n");
    fprintf(stderr, "  这是一个错误信息！\n");


    // getchar 标准输入
    // printf("  getchar 标准输入：\n");
    // int c = getchar();
    // printf("  你输入的字符是：%c\n", c);

    // putchar 标准输出
    printf("  putchar 标准输出：\n");
    putchar('A');
    printf("  输出的字符是：%c\n", 'A');

    // scanf 标准输入
    // printf("  scanf 标准输入：\n");
    // int a;
    // scanf("%d", &a);
    // printf("  你输入的整数是：%d\n", a);
    
    // printf
    printf("  printf 标准输出：\n");
    printf("  你好，世界！\n");


    // 读取模式 
    // w= 写入模式, a= 追加模式, wb= 二进制写入模式, rb= 二进制读取模式 ab= 二进制追加模式   
    // r+ 读写模式, w+ 写入模式，a+ 追加模式, r+b 二进制读写模式, w+b 二进制写入模式 a+b 二进制追加模式
    // 写文件 
    // 1. 创建文件 参数说明“w”表示写入模式，w表示从头写入，如果文件存在则覆盖写入
    printf("  写文件 w：output.txt\n");
    FILE *fp = fopen("output.txt", "w");
    if (fp == NULL) {
        printf("  文件打开失败！\n");
        return 1;
    }
    
    // 2. 写入文件
    printf("  写入文件 w：output.txt\n");
    fprintf(fp, "  这是一个测试文件！\n");// 写入文件
    fclose(fp);// 关闭文件, 一定不能丢


    // 其他的方法，fputc 写入单个字符， fputs 写入字符串， fprintf 写入格式化字符串

    // 写入文件 a
     printf("  写入文件 a：output.txt\n");
     fp = fopen("output.txt", "a");
     if (fp == NULL) {
        printf("  文件打开失败！\n");
        return 1;
     }

     // fprintf 写入文件
     for (int i = 0; i < 3; i++) {
        fprintf(fp, "  这是一个追加文件！%d\n" , i);// 写入文件
     }
     fclose(fp);// 关闭文件


    // 读取文件
    printf("  读取文件 ：output.txt\n");
    // 1. 创建文件 参数说明“r”表示读取模式
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("  文件打开失败！\n");
        return 1;
    }
    
    // 2. 读取文件
    printf("  读取文件：output.txt\n");
    char line[256];
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("  读取到的内容是：%s", line);
    }
    fclose(fp);// 关闭文件


    fp = fopen("output.txt", "r");
    // fgetc 读取单个字符
    int fgetc_buffer;
    while ((fgetc_buffer = fgetc(fp)) != EOF) {
        printf("  fgetc 读取到的字符是：%c\n", fgetc_buffer);   
    }
    fclose(fp);// 关闭文件


    fp = fopen("output.txt", "r");
    // fgets 读取字符串
    char fgets_buffer[10];
    while ((fgets(fgets_buffer, sizeof(fgets_buffer), fp)) != NULL) {
        printf("  fgets 读取到的字符串是：%s\n", fgets_buffer);
    }
    fclose(fp);  // 关闭文件

    // fscanf - 格式化读取（类似 scanf）
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("  打开文件失败！\n");
        return 1;
    }
    int fscanf_buffer;
    printf("fscanf - 格式化读取:\n");
    // 注意: fscanf 返回成功读取的项目数(1)，不是 EOF
    printf("  读取整数：%d\n", fscanf(fp, "%d", &fscanf_buffer));
    while (fscanf(fp, "%d", &fscanf_buffer) == 1) {  // 成功读取到整数
        printf("  fscanf 读取到的整数是: %d\n", fscanf_buffer);
    }
    fclose(fp);  // 关闭文件


    printf("========================================\n");
    printf("          程序执行完毕\n");
    printf("========================================\n");

    return 0;
}
