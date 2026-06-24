#include <stdio.h>
#include <stdlib.h>

// 函数制定长宽, 打印一个三角形
void printTriangle(int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < i; j++)
        {
            printf("*");
        }
        printf("\n");
    }
}
// 根据半径打印字符圆
void printCircle(int radius)
{
    int r = radius;
    // 遍历y轴上下范围
    for (int y = -r; y <= r; y++)
    {
        // 遍历x轴左右范围
        for (int x = -r; x <= r; x++)
        {
            // 满足圆方程则打印*，否则空格
            if (x*x + y*y <= r*r)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

// 返回值
int getSum(int a, int b)
{
    return a + b;
}

// 提前结束函数
void exitFunction(void)
{
    if (1 == 1)
    {
        printf("提前结束函数\n");
        return;
    }else{
        printf("继续执行函数\n");
    }

}

// 通过指针传参
void passParameter(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

struct Point{
    int x;
    int y;
};

// 通过指针传参交换结构体
void passPoint(struct Point *a, struct Point *b)
{
    struct Point temp = *a;
    *a = *b;
    *b = temp;
}

// 统计字符串中, 数字的数量并求和
int getDigitSum(char *str)
{
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            printf("> 找到数字: %c\n", str[i]);
            sum += str[i] - '0';
            printf("> 当前和: %d\n", sum);
        }
    }
    return sum;
}


void my_practice(void)
{
    // ========================================
    // 函数练习
    // ========================================
    printf("打印一个三角形\n");
    printTriangle(5, 5);
    printf("打印一个圆\n");
    printCircle(10);
    printf("返回值: %d\n", getSum(1, 2));
    exitFunction();

    // 指针传参
    int a = 10;
    int b = 20;
    printf("a = %d, b = %d\n", a, b);
    passParameter(&a, &b);
    printf("a = %d, b = %d\n", a, b);

    // 包装类型
    struct Point p1 = {1, 2};
    struct Point p2 = {3, 4};
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    passPoint(&p1, &p2);
    printf("p1 = (%d, %d)\n", p1.x, p1.y);
    printf("p2 = (%d, %d)\n", p2.x, p2.y);

    // 统计字符串中, 数字的数量并求和
    char str[] = "S09MM8SDGR4ASDF2S4T56W7";
    printf("字符串中, 数字的数量并求和: %d\n", getDigitSum(str));
}


