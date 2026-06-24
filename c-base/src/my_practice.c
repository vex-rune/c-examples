#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h> // 可变参数函数

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

// 递归函数
int recursiveFunction(int n)
{
    if (n == 0)
    {
        printf("n = 0\n");
        return 0;
    }
    else
    {
        printf("n = %d\n", n);
        int result = n + recursiveFunction(n - 1);
        printf("n + recursiveFunction(n - 1) = %d, result = %d\n", n, result);
        return result;
    }
}

// 递归求积
int recursiveProduct(int n)
{
    if (n == 0)
    {
        printf("n = 0\n");
        return 0;
    }
    else
    {
        printf("n = %d\n", n);
        int result = n * recursiveProduct(n - 1);
        printf("n * recursiveProduct(n - 1) = %d, result = %d\n", n, result);
        return result;
    }
}


// 递归数组求和
int recursiveSum(int *arr, int size)
{
    if (size == 0)
    {
        printf("size = 0\n");
        return 0;
    }   
    else
    {
        int result = arr[size - 1] + recursiveSum(arr, size - 1);
        printf("arr[size - 1] + recursiveSum(arr, size - 1) = %d, result = %d\n", arr[size - 1], result);
        return result;
    }
}

// 可变参数函数
int recursiveSumall(int n, ...)
{
    va_list args;
    int sum = 0;
    va_start(args, n); // va_start： 初始化可变参数列表 ，n 是第一个固定参数
    for (int i = 0; i < n; i++)
    {
        sum += va_arg(args, int);// va_arg： 获取可变参数列表中的下一个参数 ，并将其转换为 int 类型
    }
    va_end(args); // va_end： 结束可变参数列表 ，释放内存
    return sum;
}

// 定义回调函数
int callbackFunction(int *a, int *b, int(*f)(int, int))
{
    return f(*a, *b);
}

// 加
int addd(int a, int b)
{
    return a + b;
}
// 减
int subb(int a, int b)
{
    return a - b;
}
// 乘
int mull(int a, int b)
{
    return a * b;
}
// 除
int divdd(int a, int b)
{
    return a / b;
}

// 运算数据声明
struct Operation{
    int a[8];
};

// 加法运算
int addOperation(struct Operation op)
{
    // 数组求和
    int sum = op.a[0];
    for (int i = 1; i < sizeof(op.a) / sizeof(op.a[0]); i++)
    {
        sum += op.a[i];
    }
    return sum;
}
// 减法运算
int subOperation(struct Operation op)
{
    return op.a[0] - op.a[1];
}
// 乘法运算
int mulOperation(struct Operation op)
{
    // 数组求积
    int product = op.a[0];
    for (int i = 1; i < sizeof(op.a) / sizeof(op.a[0]); i++)
    {
        product *= op.a[i];
    }
    return product;
}
// 除法运算
int divOperation(struct Operation op)
{
    return op.a[0] / op.a[1];
}

// 函数中的变量局部变量
int  localVariable(){
    int a = 10;
    a++;
    return a;
}

// 函数中的变量静态变量
int staticVariable()
{
    static int a = 100;
    a++;
    return a;
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

    // 递归函数
    printf("递归函数: %d\n", recursiveFunction(5));

    // 递归数组求和
    int arr[] = {1, 2, 3, 4, 5, 6};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("递归数组求和: %d\n", recursiveSum(arr, size));

    // 递归求积
    printf("递归求积: %d\n", recursiveProduct(5));

    // 无限递归函数 会栈溢出
    // infiniteRecursiveFunction();

    // 可变参数函数
    printf("可变参数函数: %d\n", recursiveSumall(6, 1, 2, 3, 4, 5, 6));
    printf("可变参数函数: %d\n", recursiveSumall(5, 1, 2, 3, 4));

    // 函数指针
    int (*sumFunc)(int, int) = getSum; // 函数指针指向 getSum 函数
    printf("函数指针: %d\n", sumFunc(7788, 9527)); // 调用 getSum 函数

    // getSum == &getSum; 是等价的


    // 回调函数： 可以统一规划多个函数的调用，只要入参一致
    int (*adddFunc)(int, int) = addd;
    int (*subbFunc)(int, int) = subb;
    int (*mullFunc)(int, int) = mull;
    int (*divddFunc)(int, int) = divdd;

    printf("回调函数 adddFunc: %d\n", callbackFunction(&a, &b, adddFunc));
    printf("回调函数 subbFunc: %d\n", callbackFunction(&a, &b, subbFunc));
    printf("回调函数 mullFunc: %d\n", callbackFunction(&a, &b, mullFunc));
    printf("回调函数 divddFunc: %d\n", callbackFunction(&a, &b, divddFunc));

    // 对象入参
    struct Operation op ;
    // 赋值
    op.a[0] = 10;
    op.a[1] = 2;
    op.a[2] = 30;
    op.a[3] = 4;
    op.a[4] = 50;
    op.a[5] = 6;
    op.a[6] = 70;
    op.a[7] = 8;
    printf("addOperation 对象入参: %d\n", addOperation(op));
    printf("subOperation 对象入参: %d\n", subOperation(op));
    printf("mulOperation 对象入参: %d\n", mulOperation(op));
    printf("divOperation 对象入参: %d\n", divOperation(op));

    // 函数中的变量
     printf("函数中的变量局部变量1: %d\n", localVariable());
     printf("函数中的变量局部变量2: %d\n", localVariable());
     printf("函数中的变量静态变量1: %d\n", staticVariable());
     printf("函数中的变量静态变量2: %d\n", staticVariable());

     // 其他变量修饰符
     // 注册变量： 存储在寄存器中，访问速度快
     register int ra = 100; // 注册变量： 存储在寄存器中，访问速度快
     printf("register int ra = %d\n", ra);

     // extern
     // extern int ea1 = 1000;  // 外部变量： 在其他文件中定义，当前文件中使用
     // printf("extern int ea1 = %d\n", ea1);

     // const
     const int ca = 1000; // 常量变量： 不能被修改
     printf("const int ca = %d\n", ca);


}


