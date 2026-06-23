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
