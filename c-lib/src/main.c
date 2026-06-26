/**
 * main.c - C 标准库函数演示
 */

#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// 定义圆周率常量（部分编译器不自带 M_PI）
#define PI 3.14159265358979323846

int main(void) {
    printf("========================================\n");
    printf("      C 语言基础函数库演示\n");
    printf("========================================\n\n");

    // ====================== 1. strcpy / strncpy 拷贝 ======================
    // strcpy = string copy（字符串拷贝）
    // strncpy = string copy with n limit（限制长度的字符串拷贝）
    
    char src[] = "hello c string";
    char dest1[32];
    char dest2[10];

    printf("【1】strcpy / strncpy (string copy)\n\n");
    
    // strcpy: 整串拷贝，包含'\0'，无长度限制，有溢出风险
    strcpy(dest1, src);  // string copy
    printf("strcpy（整串拷贝，无长度限制）: %s\n", dest1);

    // strncpy: 最多拷贝n字节，需要手动补结束符
    strncpy(dest2, src, sizeof(dest2) - 1);  // string copy with n limit
    dest2[sizeof(dest2)-1] = '\0';
    printf("strncpy（最多拷贝n字节）: %s\n\n", dest2);


    // ====================== 2. strcat / strncat 拼接 ======================
    // strcat = string concatenation（字符串拼接）
    // strncat = string concatenation with n limit（限制长度的字符串拼接）
    
    char cat_buf[64] = "prefix_";
    const char *append = "_suffix_123456789";

    printf("【2】strcat / strncat (string concatenation)\n\n");
    
    // strcat: 直接拼接，无长度限制
    strcat(cat_buf, "test");  // string concatenation
    printf("strcat（直接拼接）: %s\n", cat_buf);

    // strncat: 限制拼接长度，自动补'\0'
    strncat(cat_buf, append, sizeof(cat_buf)-strlen(cat_buf)-1);  // string concatenation with n limit
    printf("strncat（限制拼接长度）: %s\n\n", cat_buf);


    // ====================== 3. strcmp / strncmp 字符串比较 ======================
    // strcmp = string compare（字符串比较）
    // strncmp = string compare with n limit（限制长度的字符串比较）
    
    const char *s1 = "apple";
    const char *s2 = "app";
    const char *s3 = "apple";

    printf("【3】strcmp / strncmp (string compare)\n\n");
    
    // strcmp: 比较两个字符串
    // 返回值: 0=相等, <0=s1<s2, >0=s1>s2
    int ret_cmp = strcmp(s1, s3);  // string compare
    printf("strcmp(\"apple\", \"apple\") = %d\n", ret_cmp);

    // strncmp: 只比较前n个字符
    int ret_ncmp = strncmp(s1, s2, 3);  // string compare with n limit
    printf("strncmp(\"apple\", \"app\", 3) = %d (前3字符相等)\n\n", ret_ncmp);


    // ====================== 4. strcoll / strxfrm 本地化排序 ======================
    // strcoll = string collation（根据本地化规则比较字符串）
    // strxfrm = string transform（转换字符串用于比较）
    
    setlocale(LC_ALL, "zh_CN.UTF-8");
    const char *cn1 = "张三";
    const char *cn2 = "李四";
    char buf1[64], buf2[64];

    printf("【4】strcoll / strxfrm (string collation for locale)\n\n");
    
    // strxfrm: 转换字符串，便于后续比较
    size_t len1 = strxfrm(buf1, cn1, sizeof(buf1));  // string transform
    size_t len2 = strxfrm(buf2, cn2, sizeof(buf2));

    // 检查缓冲区是否足够
    if (len1 >= sizeof(buf1) || len2 >= sizeof(buf2))
    {
        printf("缓冲区不足，转换截断\n");
        return 1;
    }

    // 转换后用strcmp比较，效果等同于strcoll
    int ret = strcmp(buf1, buf2);  // string compare
    if (ret < 0)
        printf("strcoll: %s 排在前面\n", cn1);
    else
        printf("strcoll: %s 排在后面\n", cn2);


    // ====================== 5. 时间函数 ======================
    // time = 获取当前时间戳
    // ctime = convert time to string（时间转字符串）
    // localtime = local time（本地时间）
    // strftime = string format time（格式化时间输出）
    // gmtime = Greenwich Mean Time（UTC时间）
    // difftime = difference of time（时间差）
    // clock = CPU clock ticks（CPU时钟计数）
    
    printf("\n【5】时间函数 (time functions)\n\n");
    
    // time: 获取当前时间戳（秒）
    time_t now_ts = time(NULL);  // time
    printf("time(NULL) 当前时间戳(秒): %lld\n\n", (long long)now_ts);

    // ctime: 直接转为默认格式字符串
    printf("ctime() 默认格式: %s\n", ctime(&now_ts));  // convert time to string

    // localtime: 转为本地时间结构体 struct tm
    struct tm *local_t = localtime(&now_ts);  // local time
    printf("localtime() 本地时间:\n");
    printf("  年: %d  月: %d  日: %d\n", 
           local_t->tm_year + 1900,  // tm_year从1900开始
           local_t->tm_mon + 1,       // tm_mon从0开始
           local_t->tm_mday);
    printf("  时: %d  分: %d  秒: %d  星期: %d\n",
           local_t->tm_hour,
           local_t->tm_min,
           local_t->tm_sec,
           local_t->tm_wday);  // 0=周日
    printf("\n");

    // strftime: 自定义格式化输出
    char time_buf[64];
    // %Y=年 %m=月 %d=日 %H=24小时 %M=分 %S=秒 %A=星期全称
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S %A", local_t);  // string format time
    printf("strftime() 自定义格式: %s\n\n", time_buf);

    // gmtime: UTC零时区时间
    struct tm *utc_t = gmtime(&now_ts);  // Greenwich Mean Time
    strftime(time_buf, sizeof(time_buf), "%Y-%m-%d %H:%M:%S UTC", utc_t);
    printf("gmtime() UTC时间: %s\n\n", time_buf);

    // difftime: 计算两个时间点的差值（秒）
    time_t t1 = time(NULL); // null表示当前时间戳
    for (int i = 0; i < 99999999; i++);  // 模拟耗时
    time_t t2 = time(NULL); // null表示当前时间戳
    double cost_sec = difftime(t2, t1);  // difference of time 
    printf("difftime() 循环耗时: %.2lf 秒\n\n", cost_sec);

    // clock: 获取CPU时钟计数，适合测小段代码执行时间 clock_t
    clock_t start_cpu = clock();  // clock_t 类型，返回当前CPU时钟计数
    for (int i = 0; i < 99999999; i++);
    clock_t end_cpu = clock();  // clock_t 类型，返回当前CPU时钟计数
    // CLOCKS_PER_SEC = 每秒时钟节拍数
    double cpu_ms = (double)(end_cpu - start_cpu) / CLOCKS_PER_SEC * 1000;
    printf("clock() CPU执行耗时: %.2lf 毫秒\n", cpu_ms);

    ///////////////////////////////////////////////////////

    printf("【6】数学函数 (math functions)\n\n");
    
    double a = -3.6;

    // 1. 绝对值
    printf("fabs(-3.6) 浮点数绝对值 = %.2f\n", fabs(a));
    printf("abs(-5)    整数绝对值 = %d\n\n", abs(-5));

    // 2. 取整函数
    printf("ceil(-3.6) 向上取整 = %.2f\n", ceil(a));   // -3
    printf("floor(-3.6)向下取整 = %.2f\n", floor(a)); // -4
    printf("round(-3.6)四舍五入 = %.2f\n\n", round(a));// -4

    // 3. 幂、开方
    printf("pow(2,3) 2^3 = %.0f\n", pow(2, 3));
    printf("sqrt(16) 平方根 = %.0f\n", sqrt(16));
    printf("cbrt(8)  立方根 = %.0f\n\n", cbrt(8));

    // 4. 指数、对数
    printf("exp(1) e^1 ≈ %.4f\n", exp(1));
    printf("log(E) 自然对数ln(7.389) = %.2f\n", log(exp(2)));
    printf("log10(100) lg100 = %.0f\n\n", log10(100));

    // 5. 三角函数（参数是弧度，不是角度）
    double rad = PI / 2;
    printf("sin(π/2) = %.0f\n", sin(rad));
    printf("cos(π)   = %.0f\n", cos(PI));
    printf("tan(π/4) = %.0f\n\n", tan(PI/4));

    // 角度转弧度 / 弧度转角度
    double deg = 60;
    double r = deg * PI / 180;
    printf("60度 sin值 = %.2f\n", sin(r));

    // 反三角函数（返回弧度）
    printf("asin(1) = %.2f 弧度\n\n", asin(1));

    // 6. 取余、最大值最小值
    printf("fmod(7,2) 浮点数取余 7%%2 = %.1f\n", fmod(7.0, 2.0));
    printf("fmax(3.2, 9.5) 最大值=%.1f\n", fmax(3.2,9.5));
    printf("fmin(3.2, 9.5) 最小值=%.1f\n\n", fmin(3.2,9.5));

    // 7. 常量 PI
    printf("PI 圆周率 = %.10f\n", PI);
    
    printf("\n========================================\n");
    printf("          程序执行完毕\n");
    printf("========================================\n");

    return 0;
}
