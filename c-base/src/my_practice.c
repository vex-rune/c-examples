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
}


