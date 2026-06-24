# Java程序员学C语言

## 与Java的关键区别

### 1. 基本类型

| Java | C | 说明 |
|------|---|------|
| `int` | `int` | 一样 |
| `double` | `double` | 一样 |
| `boolean` | 无 | C用 `int`(0/1) 代替 |
| `char` | `char` | 都是1字节，但C的char是整数(ASCII码) |
| `String` | 无 | C用字符数组 `char[]` 代替 |
| `byte` | `char` | 都是1字节 |

**注意：C没有boolean、String、byte、short类型！**

### 2. 字符串

```c
// Java
String str = "Hello";

// C - 没有String类型！
char str[] = "Hello";  // 用字符数组
printf("%s", str);     // 用%s输出
```

### 3. 类和对象

```c
// Java
class Person {
    String name;
    int age;
    void speak() { }
}

// C - 没有类！用结构体
struct Person {
    char name[20];
    int age;
};
// C没有成员函数，只能用函数处理结构体
void speak(struct Person *p) { }
```

### 4. main方法

```c
// Java
public static void main(String[] args) { }

// C - 更简单
int main(void) {
    return 0;
}
```

### 5. 输出语句

```c
// Java
System.out.println("Hello");

// C
printf("Hello\n");
```

### 6. 变量定义

```c
// Java
int a = 10;

// C - 必须先声明类型
int a = 10;    // ✓ 正确
var a = 10;    // ✗ C没有var
```

### 7. 数组

```c
// Java
int[] arr = {1, 2, 3};
int len = arr.length;

// C
int arr[] = {1, 2, 3};
int len = sizeof(arr) / sizeof(arr[0]);  // 要自己算长度
```

### 8. 内存管理

```c
// Java - 自动垃圾回收
Object obj = new Object();  // 不用了自动回收

// C - 手动管理
int *p = (int*)malloc(sizeof(int));  // 手动申请
free(p);                              // 必须手动释放！
```

### 9. 指针（重点！）

```c
// Java - 不用关心指针
int a = 10;
int b = a;  // 复制值

// C - 指针无处不在
int a = 10;
int *p = &a;    // p指向a的地址
*p = 20;         // a变成20
printf("%d", *p); // 输出20
```

### 10. 空值

```c
// Java
String str = null;

// C - 用 NULL（实际上是0）
int *p = NULL;  // 空指针
```

### 11. 布尔值

```c
// Java
if (flag == true) { }

// C - 没有boolean，用整数代替
if (flag == 1) { }
// 或者更简洁
if (flag) { }
```

### 12. 函数重载

```c
// Java - 支持重载
int add(int a, int b) { }
int add(int a, int b, int c) { }

// C - 不支持！函数名必须唯一
int add2(int a, int b) { }
int add3(int a, int b, int c) { }
```

### 13. 访问修饰符

```c
// Java
public/private/protected void method() { }

// C - 没有！全部公开
void method() { }  // 默认都是公开的
```

### 14. 包/命名空间

```c
// Java
package com.example;
import java.util.List;

// C - 用头文件和include
#include <stdio.h>
#include "myheader.h"
```

## 函数专题

### 1. 基本函数定义

```java
// Java
public int add(int a, int b) {
    return a + b;
}
```

```c
// C - 更简洁，不需要public
int add(int a, int b) {
    return a + b;
}
```

### 2. 无返回值的函数

```java
// Java
public void print(String msg) {
    System.out.println(msg);
}
```

```c
// C - 用void表示无返回值
void print(const char *msg) {  // char* 是字符串指针
    printf("%s\n", msg);
}
```

### 3. 无参数的函数

```java
// Java
public void hello() {
    System.out.println("Hello");
}
```

```c
// C - 用void表示无参数（更安全！）
void hello(void) {
    printf("Hello\n");
}

// 省略void也可以，但不推荐
void hello() {  // 不明确是否真的无参数
    printf("Hello\n");
}
```

### 4. main函数

```java
// Java
public static void main(String[] args) {
    // 程序入口
}
```

```c
// C
int main(void) {
    // 程序入口
    return 0;  // 返回0表示正常退出
}

// 或者带命令行参数
int main(int argc, char *argv[]) {
    // argc: 参数个数
    // argv: 参数数组
    return 0;
}
```

### 5. 参数传递：值传递 vs 指针传递

```java
// Java - 都是引用传递（基本类型除外）
public void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;  // 只影响局部，不影响实参！
}
```

```c
// C - 默认是值传递，指针才能修改实参
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;  // 不会影响调用者！
}

// 正确做法：传指针
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// 调用
int x = 10, y = 20;
swap(&x, &y);  // x=20, y=10
```

### 6. 数组作为函数参数

```java
// Java - 数组作为参数
public int sum(int[] arr) {
    int total = 0;
    for (int n : arr) {
        total += n;
    }
    return total;
}
```

```c
// C - 数组退化为指针
int sum(int arr[], int len) {  // int arr[] 等价于 int *arr
    int total = 0;
    for (int i = 0; i < len; i++) {
        total += arr[i];
    }
    return total;
}

// 调用 - 必须传长度！
int nums[] = {1, 2, 3, 4, 5};
int total = sum(nums, 5);  // 传数组和长度
```

### 7. 结构体作为函数参数

```java
// Java - 对象直接传
public void print(Person p) {
    System.out.println(p.name);
}
```

```c
// C - 推荐传指针，效率更高
struct Person {
    char name[20];
    int age;
};

void print(struct Person *p) {
    printf("%s, %d\n", p->name, p->age);  // 用->访问成员
}

// 调用
struct Person person = {"Tom", 20};
print(&person);  // 传地址
```

### 8. 返回指针

```java
// Java - 返回对象
public String getName() {
    return "Tom";
}
```

```c
// C - 可以返回指针，但要小心！
char* getName(void) {
    return "Tom";  // OK！返回字符串常量
}

int* getArray(void) {
    int arr[] = {1, 2, 3};
    return arr;  // 错误！局部数组会被销毁
}

int* getArray(void) {
    int *arr = malloc(3 * sizeof(int));  // OK！在堆上分配
    arr[0] = 1; arr[1] = 2; arr[2] = 3;
    return arr;  // 调用者需要free()
}
```

### 9. 函数声明与定义

```java
// Java - 可以直接使用，编译器会找到定义
public class Main {
    void hello() { }
    void test() {
        hello();  // 可以在定义前调用
    }
    void hello() { }  // 方法可以后面定义
}
```

```c
// C - 必须先声明再使用（从上到下编译）
void hello(void);  // 声明：告诉编译器这个函数存在

int main(void) {
    hello();  // 使用前已声明，没问题
    return 0;
}

void hello(void) {  // 定义：函数的具体实现
    printf("Hello\n");
}
```

### 10. 头文件与分文件

```java
// Java - 类文件自动组织
package com.example;
public class MathUtils {  // 必须在 MathUtils.java 文件中
    public static int add(int a, int b) { return a + b; }
}
```

```c
// C - 用头文件声明，源文件定义

// math_utils.h - 头文件：声明
#ifndef MATH_UTILS_H
#define MATH_UTILS_H

int add(int a, int b);
int multiply(int a, int b);

#endif

// math_utils.c - 源文件：定义
#include "math_utils.h"

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

// main.c - 主文件：使用
#include <stdio.h>
#include "math_utils.h"

int main(void) {
    printf("%d\n", add(1, 2));       // 输出 3
    printf("%d\n", multiply(3, 4));  // 输出 12
    return 0;
}
```

### 11. 函数指针

```java
// Java - 用接口和Lambda
interface Calculator {
    int calc(int a, int b);
}

Calculator addCalc = (a, b) -> a + b;
int result = addCalc.calc(1, 2);
```

```c
// C - 直接用函数指针
int add(int a, int b) { return a + b; }
int multiply(int a, int b) { return a * b; }

// 定义函数指针类型
typedef int (*Operation)(int, int);

// 使用
Operation op = add;  // op指向add函数
int result = op(1, 2);  // 调用，等价于 add(1,2)

// 回调函数示例
void process(int a, int b, int (*callback)(int, int)) {
    int result = callback(a, b);
    printf("Result: %d\n", result);
}

process(3, 4, add);      // 输出 7
process(3, 4, multiply); // 输出 12
```

### 12. 可变参数

```java
// Java - 可变参数
public int sum(int... nums) {
    int total = 0;
    for (int n : nums) total += n;
    return total;
}
sum(1, 2, 3, 4, 5);
```

```c
// C - 使用stdarg.h
#include <stdarg.h>

int sum(int count, ...) {  // 第一个参数是个数
    va_list args;
    va_start(args, count);
    
    int total = 0;
    for (int i = 0; i < count; i++) {
        total += va_arg(args, int);
    }
    
    va_end(args);
    return total;
}

sum(5, 1, 2, 3, 4, 5);  // 输出 15
```

### 13. 内联函数

```java
// Java - JIT自动优化
public static final int add(int a, int b) {
    return a + b;
}
```

```c
// C - 用inline建议编译器内联
static inline int add(int a, int b) {
    return a + b;
}
```

### 14. 递归函数

```java
// Java - 递归
public int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

```c
// C - 同样的递归写法
int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
```

### 函数要点总结

| 特性 | Java | C |
|------|------|---|
| 返回值类型 | 必须声明 | 必须声明 |
| 无返回值 | void | void |
| 无参数 | `hello()` | `hello(void)` |
| 参数传递 | 引用传递（基本类型值传递） | 值传递，指针才能修改实参 |
| 数组参数 | 传数组本身 | 退化为指针，需额外传长度 |
| 结构体参数 | 传对象 | 传指针更高效 |
| 函数重载 | 支持 | 不支持 |
| 声明顺序 | 不用关心 | 必须先声明后使用 |
| Lambda/回调 | 接口+Lambda | 函数指针 |
| 头文件 | package+import | #include |

## 快速对照表

| Java | C |
|------|---|
| `int x = 10;` | `int x = 10;` |
| `String s = "hi";` | `char s[] = "hi";` |
| `System.out.println()` | `printf()` |
| `new int[5]` | `int arr[5]` 或 `malloc()` |
| `.length` | `sizeof()` |
| `null` | `NULL` |
| `true/false` | `1/0` |
| `boolean` | `int` |
| `class` | `struct` |
| `obj.method()` | `function(&obj)` |

## C语言特有概念（Java没有）

1. **指针** - 地址操作
2. **手动内存管理** - malloc/free
3. **预处理指令** - #define #include
4. **位运算** - & | ^ ~ << >>
5. **volatile** - 硬件编程必备
6. **寄存器变量** - register

## 学习重点

1. 指针必须理解透彻
2. 内存管理要小心
3. 字符串就是字符数组
4. 没有类，用结构体模拟
5. 位运算是单片机核心
