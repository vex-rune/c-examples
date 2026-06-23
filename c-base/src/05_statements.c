#include <stdio.h>

// C语言流程控制完全指南

void demo_statements(void) {
    printf("=== 5. 流程控制演示 ===\n");
    printf("流程控制决定程序执行的顺序\n");
    printf("\n");

    // 第1步：if 语句
    printf("【第1步】if 语句（条件判断）\n");
    int score = 85;
    printf("  score = %d\n", score);
    if (score >= 60) {
        printf("  条件 score >= 60 为真，执行这里\n");
        printf("  结果: 及格！\n");
    }
    printf("\n");

    // 第2步：if-else 语句
    printf("【第2步】if-else 语句（二选一）\n");
    int age = 20;
    printf("  age = %d\n", age);
    if (age >= 18) {
        printf("  age >= 18 为真: 成年人\n");
    } else {
        printf("  age >= 18 为假: 未成年\n");
    }
    printf("\n");

    // 第3步：if-else if-else 语句
    printf("【第3步】if-else if-else（多选一）\n");
    int grade = 85;
    printf("  grade = %d\n", grade);
    if (grade >= 90) {
        printf("  等级: A\n");
    } else if (grade >= 80) {
        printf("  等级: B\n");
    } else if (grade >= 70) {
        printf("  等级: C\n");
    } else if (grade >= 60) {
        printf("  等级: D\n");
    } else {
        printf("  等级: F\n");
    }
    printf("\n");

    // 第4步：switch 语句
    printf("【第4步】switch 语句（值匹配）\n");
    int day = 3;
    printf("  day = %d\n", day);
    switch (day) {
        case 1: printf("  星期一\n"); break;
        case 2: printf("  星期二\n"); break;
        case 3: printf("  星期三\n"); break;
        case 4: printf("  星期四\n"); break;
        case 5: printf("  星期五\n"); break;
        default: printf("  周末\n");
    }
    printf("\n");

    // 第5步：for 循环
    printf("【第5步】for 循环（计数循环）\n");
    printf("  for (i=1; i<=5; i++)\n");
    for (int i = 1; i <= 5; i++) {
        printf("  i = %d\n", i);
    }
    printf("  循环结束\n");
    printf("\n");

    // 第6步：while 循环
    printf("【第6步】while 循环（条件循环）\n");
    int count = 1;
    printf("  count = %d\n", count);
    while (count <= 3) {
        printf("  count = %d\n", count);
        count++;
    }
    printf("  循环结束\n");
    printf("\n");

    // 第7步：do-while 循环
    printf("【第7步】do-while（至少执行一次）\n");
    int n = 1;
    printf("  n = %d\n", n);
    do {
        printf("  执行一次: n = %d\n", n);
        n++;
    } while (n <= 3);
    printf("\n");

    // 第8步：break 语句
    printf("【第8步】break（跳出循环）\n");
    printf("  for (i=1; i<=10; i++)\n");
    for (int i = 1; i <= 10; i++) {
        if (i == 4) {
            printf("  i = %d 时，break 跳出\n", i);
            break;
        }
        printf("  i = %d\n", i);
    }
    printf("\n");

    // 第9步：continue 语句
    printf("【第9步】continue（跳过本次）\n");
    printf("  跳过偶数，只打印奇数:\n");
    for (int i = 1; i <= 5; i++) {
        if (i % 2 == 0) {
            printf("  跳过 i = %d\n", i);
            continue;
        }
        printf("  打印 i = %d\n", i);
    }
    printf("\n");

    // 第10步：goto 语句
    printf("【第10步】goto 语句（跳转）\n");
    printf("  goto 可以跳转到标记的位置\n");
    int i = 1;
loop_start:
    printf("  i = %d\n", i);
    i++;
    if (i <= 3) {
        goto loop_start;
    }
    printf("  goto 结束\n");
    printf("\n");

    printf("\n");
}
