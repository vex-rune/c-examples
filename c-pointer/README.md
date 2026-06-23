# C语言指针专题

指针是C语言的核心，也是单片机开发的关键。

## 快速开始

```bash
cd c-pointer/src
gcc -std=c17 -Wall *.c -o program
./program
```

## 内容列表

| 文件 | 内容 | 说明 |
|------|------|------|
| 01_pointer_basic | 指针基础 | 地址、指针、*和& |
| 02_pointer_array | 指针与数组 | 数组名就是指针 |
| 03_pointer_function | 指针与函数 | 传址调用、函数指针 |
| 04_pointer_struct | 指针与结构体 | ->运算符、结构体指针 |
| 05_pointer_51 | 单片机应用 | volatile、寄存器操作 |

## 核心概念

### 三个符号

```c
int num = 100;
int *ptr = &num;

&num   // 取地址，ptr = 0x1000
*ptr   // 取值，*ptr = 100
ptr    // 地址，ptr = 0x1000
```

### 指针与数组

```c
int arr[] = {1, 2, 3};
int *p = arr;    // p指向arr[0]

p[0]   == arr[0]  // 1
*(p+1) == arr[1]  // 2
```

### 指针与函数

```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

swap(&x, &y);  // 传地址
```

## Java对比

| Java | C |
|------|---|
| 无需关心指针 | 必须理解指针 |
| 引用自动管理 | 手动管理地址 |
| `obj.method()` | `func(&obj)` |
| `null` | `NULL` |

## 单片机重点

```c
// volatile 防止优化
volatile unsigned char *P1 = (volatile unsigned char*)0x90;
*P1 = 0x01;  // P1.0输出1

// 位操作
*P1 |= 0x01;   // 置1
*P1 &= ~0x01;   // 清0
*P1 ^= 0x01;   // 取反
```
