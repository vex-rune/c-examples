#include <stdio.h>

// 指针与结构体

struct Student {
    char name[20];
    int age;
    float score;
};

// 打印学生信息（传递结构体）
void print_student(struct Student s) {
    printf("  姓名: %s, 年龄: %d, 分数: %.1f\n", s.name, s.age, s.score);
}

// 修改学生信息（传递结构体指针）
void modify_student(struct Student *ps) {
    printf("  修改前: %s, 年龄: %d\n", ps->name, ps->age);
    ps->age = 20;
    printf("  修改后: %s, 年龄: %d\n", ps->name, ps->age);
}

void demo_pointer_struct(void) {
    printf("=== 4. 指针与结构体 ===\n");
    printf("\n");

    // 第1步：结构体变量
    printf("【第1步】结构体变量\n");
    struct Student stu = {"Tom", 18, 95.5f};
    printf("  struct Student stu = {\"Tom\", 18, 95.5f};\n");
    printf("  stu.name: %s\n", stu.name);
    printf("  stu.age: %d\n", stu.age);
    printf("  stu.score: %.1f\n", stu.score);
    printf("\n");

    // 第2步：结构体指针
    printf("【第2步】结构体指针\n");
    struct Student *pstu = &stu;
    printf("  struct Student *pstu = &stu;\n");
    printf("  (*pstu).name: %s\n", (*pstu).name);
    printf("  pstu->name: %s (更常用)\n", pstu->name);
    printf("  pstu->age: %d\n", pstu->age);
    printf("  pstu->score: %.1f\n", pstu->score);
    printf("  -> 是结构体指针访问成员运算符\n");
    printf("\n");

    // 第3步：通过指针修改结构体
    printf("【第3步】通过指针修改结构体\n");
    printf("  调用 modify_student(&stu)\n");
    modify_student(&stu);
    printf("  修改后 stu.age = %d\n", stu.age);
    printf("\n");

    // 第4步：结构体数组
    printf("【第4步】结构体数组\n");
    struct Student class[] = {
        {"Alice", 18, 90.0f},
        {"Bob", 19, 85.5f},
        {"Charlie", 20, 92.0f}
    };
    printf("  struct Student class[3];\n");
    for (int i = 0; i < 3; i++) {
        printf("  class[%d]: %s, %d岁, %.1f分\n", 
               i, class[i].name, class[i].age, class[i].score);
    }
    printf("\n");

    // 第5步：结构体指针数组
    printf("【第5步】结构体指针数组\n");
    struct Student *students[] = {&class[0], &class[1], &class[2]};
    printf("  struct Student *students[3];\n");
    for (int i = 0; i < 3; i++) {
        printf("  students[%d]->name: %s\n", i, students[i]->name);
    }
    printf("\n");
}
