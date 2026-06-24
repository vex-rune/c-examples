#include <stdio.h>
#include <string.h>

// ============================================
// 结构体基础
// ============================================

/**
 * 什么是结构体？
 * 
 * 结构体是将多个不同类型的数据组合成一个整体
 * 相当于 Java 的 class（但没有方法）
 */

// 定义结构体
struct Student
{
    int id;
    char name[30];
    char gender;
    int age;
    char address[50];
};

// 定义猫结构体
struct Cat
{
    int id;
    char name[30];
    int age;
    char color[10];
};

// 定义狗结构体（同时声明全局变量）
struct Dog
{
    int id;
    char name[30];
    int age;
    char color[10];
} dog1, dog2;  // 直接声明全局变量

// 定义鸟结构体（同时声明全局变量）
struct Bird
{
    int id;
    char name[30];
    int age;
    char color[10];
} bird1, bird2;  // 直接声明全局变量

// 定义羊结构体（同时声明并初始化全局变量）
struct Sheep
{
    int id;
    char name[30];
    int age;
    char color[10];
} sheep1 = {1, "喜羊羊", 1, "白色"},
  sheep2 = {2, "懒羊羊", 1, "黄色"};  // 直接初始化全局变量

// 定义牛结构体（同时声明并初始化全局变量）
struct Cow
{
    int id;
    char name[30];
    int age;
    char color[10];
} cow1 = {1, "牛魔王", 3, "黑色"}, 
  cow2 = {2, "铁扇公主", 2, "棕色"};

// 打印学生结构体
void print_student(struct Student *stu)
{
    printf("  id=%d, name=%s, gender=%c, age=%d, address=%s\n", 
           stu->id, stu->name, stu->gender, stu->age, stu->address);
}

// 打印猫结构体
void print_cat(struct Cat *cat)
{
    printf("  id=%d, name=%s, age=%d, color=%s\n", 
           cat->id, cat->name, cat->age, cat->color);
}

// 打印狗结构体
void print_dog(struct Dog *dog)
{
    printf("  id=%d, name=%s, age=%d, color=%s\n", 
           dog->id, dog->name, dog->age, dog->color);
}

// 打印鸟结构体
void print_bird(struct Bird *bird)
{
    printf("  id=%d, name=%s, age=%d, color=%s\n", 
           bird->id, bird->name, bird->age, bird->color);
}

// 打印羊结构体
void print_sheep(struct Sheep *sheep)
{
    printf("  id=%d, name=%s, age=%d, color=%s\n", 
           sheep->id, sheep->name, sheep->age, sheep->color);
}

// 打印牛结构体
void print_cow(struct Cow *cow)
{
    printf("  id=%d, name=%s, age=%d, color=%s\n", 
           cow->id, cow->name, cow->age, cow->color);
}

/**
 * 主演示函数
 */
void demo_struct_basic(void)
{
    printf("=== 1. 结构体基础 ===\n\n");
    
    // ========================================
    // 第1步：先声明结构体变量，再逐个赋值
    // ========================================
    printf("【第1步】先声明，再赋值\n\n");
    
    struct Student stu1;
    stu1.id = 1;
    strcpy(stu1.name, "张三");  // 字符串赋值用 strcpy
    stu1.gender = 'M';
    stu1.age = 18;
    strcpy(stu1.address, "北京市海淀区");
    printf("  struct Student stu1;\n");
    printf("  stu1.id = 1;\n");
    printf("  strcpy(stu1.name, \"张三\");\n");
    printf("  stu1.gender = 'M';\n");
    printf("  stu1.age = 18;\n");
    printf("  -> ");
    print_student(&stu1);
    printf("\n");
    
    struct Cat cat1;
    cat1.id = 2;
    strcpy(cat1.name, "小白");
    cat1.age = 1;
    strcpy(cat1.color, "黄色");
    printf("  struct Cat cat1;\n");
    printf("  cat1.id = 2;\n");
    printf("  -> ");
    print_cat(&cat1);
    printf("\n");
    
    // ========================================
    // 第2步：声明时直接初始化
    // ========================================
    printf("【第2步】声明时直接初始化\n\n");
    
    struct Student stu2 = {1002, "李四", 'F', 20, "北京市朝阳区"};
    printf("  struct Student stu2 = {1002, \"李四\", 'F', 20, \"北京市朝阳区\"};\n");
    printf("  -> ");
    print_student(&stu2);
    
    struct Cat cat2 = {1002, "小黑", 2, "黑色"};
    printf("  struct Cat cat2 = {1002, \"小黑\", 2, \"黑色\"};\n");
    printf("  -> ");
    print_cat(&cat2);
    printf("\n");
    
    // ========================================
    // 第3步：全局结构体变量（定义时直接声明）
    // ========================================
    printf("【第3步】全局结构体变量\n");
    printf("  定义结构体时直接声明变量（相当于全局变量）\n\n");
    
    // 给全局变量赋值
    dog1.id = 3;
    strcpy(dog1.name, "旺财");
    dog1.age = 2;
    strcpy(dog1.color, "金色");
    
    dog2.id = 4;
    strcpy(dog2.name, "大黄");
    dog2.age = 3;
    strcpy(dog2.color, "黄色");
    
    printf("  struct Dog dog1, dog2;  // 定义时直接声明\n");
    printf("  dog1 -> ");
    print_dog(&dog1);
    printf("  dog2 -> ");
    print_dog(&dog2);
    
    printf("  bird1, bird2 未赋值（随机值）\n");
    printf("  bird1 -> ");
    print_bird(&bird1);
    printf("  bird2 -> ");
    print_bird(&bird2);
    printf("\n");
    
    // ========================================
    // 第4步：全局结构体变量 + 初始化
    // ========================================
    printf("【第4步】全局结构体变量 + 初始化\n");
    printf("  定义结构体时直接声明并初始化变量\n\n");
    
    printf("  struct Sheep sheep1 = {1, \"喜羊羊\", 1, \"白色\"};\n");
    printf("  -> ");
    print_sheep(&sheep1);
    
    printf("  struct Cow cow1 = {1, \"牛魔王\", 3, \"黑色\"};\n");
    printf("  -> ");
    print_cow(&cow1);
    printf("\n");
    
    // ========================================
    // Java 对比
    // ========================================
    printf("【Java 对比】\n\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  class Student {\n");
    printf("      int id;\n");
    printf("      String name;\n");
    printf("      char gender;\n");
    printf("      int age;\n");
    printf("      String address;\n");
    printf("  }\n");
    printf("\n");
    printf("  Student stu = new Student();\n");
    printf("  stu.id = 1;\n");
    printf("  stu.name = \"张三\";\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  struct Student {\n");
    printf("      int id;\n");
    printf("      char name[30];\n");
    printf("      char gender;\n");
    printf("      int age;\n");
    printf("      char address[50];\n");
    printf("  };\n");
    printf("\n");
    printf("  struct Student stu;\n");
    printf("  stu.id = 1;\n");
    printf("  strcpy(stu.name, \"张三\");  // 字符串用 strcpy\n");
    printf("\n");
}
