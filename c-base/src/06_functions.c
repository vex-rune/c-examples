#include <stdio.h>

// 什么是函数？
// 函数就是"工具箱"，打包好的代码，可以重复使用

// 定义一个加法函数
int add(int a, int b) {
    printf("  [add 函数内部] 收到 a=%d, b=%d\n", a, b);
    int result = a + b;
    printf("  [add 函数内部] 计算 %d + %d = %d\n", a, b, result);
    printf("  [add 函数内部] 返回 %d\n", result);
    return result;
}

// 定义一个乘法函数
int multiply(int a, int b) {
    printf("  [multiply 函数内部] 收到 a=%d, b=%d\n", a, b);
    int result = a * b;
    printf("  [multiply 函数内部] 计算 %d * %d = %d\n", a, b, result);
    return result;
}

void demo_functions(void) {
    printf("=== 6. 函数演示 ===\n");
    printf("函数就是\"工具箱\"，可以重复使用的代码\n");
    printf("\n");

    // 第1步：调用函数
    printf("【第1步】调用函数\n");
    printf("  调用 add(10, 20):\n");
    int result1 = add(10, 20);
    printf("  main 函数收到结果: %d\n", result1);
    printf("\n");

    // 第2步：多次调用
    printf("【第2步】多次调用\n");
    printf("  调用 multiply(5, 6):\n");
    int result2 = multiply(5, 6);
    printf("  main 函数收到结果: %d\n", result2);
    printf("\n");

    // 第3步：函数组合使用
    printf("【第3步】函数组合使用\n");
    int r1 = add(10, 20);
    int r2 = multiply(3, 4);
    printf("  add(10, 20) = %d\n", r1);
    printf("  multiply(3, 4) = %d\n", r2);
    printf("  add(r1, r2) = add(%d, %d) = %d\n", r1, r2, add(r1, r2));
    printf("\n");

    // 第4步：变量作用域
    printf("【第4步】变量的作用域\n");
    int num = 10;
    printf("  在 main 函数中: num = %d\n", num);
    printf("  进入代码块...\n");
    {
        int num = 20;  // 这是另一个局部变量
        printf("  → 在代码块中: num = %d（隐藏了外面的 num）\n", num);
    }
    printf("  离开代码块，回到 main: num = %d（还是原来的）\n", num);
    printf("  结论：代码块里的 num 是\"局部\"的，不影响外面\n");
    printf("\n");

    // 第5步：函数参数传递
    printf("【第5步】函数参数传递\n");
    int x = 5, y = 3;
    printf("  main 中: x = %d, y = %d\n", x, y);
    printf("  调用 add(x, y):\n");
    printf("  x 和 y 的值被复制一份传给函数\n");
    printf("  函数内部收到的是副本，改变副本不影响原值\n");
    add(x, y);
    printf("  调用完后: x = %d, y = %d（没变）\n", x, y);
    printf("\n");

    // 第6步：无返回值函数
    printf("【第6步】void 函数（无返回值）\n");
    printf("  void 表示\"空\"，不返回任何值\n");
    printf("  用于执行操作，不需要返回结果的情况\n");
    printf("  printf 就是一个 void 函数\n");
    printf("\n");

    printf("\n");
}
