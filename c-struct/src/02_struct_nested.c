#include <stdio.h>

// ============================================
// 嵌套结构体
// ============================================

/**
 * 什么是嵌套结构体？
 * 
 * 一个结构体的成员可以是另一个结构体
 * 相当于 Java 的内部类
 * 
 * struct Person {
 *     struct Name name;       // 嵌套结构体
 *     enum Gender gender;     // 嵌套枚举
 *     struct Company company; // 嵌套结构体
 * }
 */

// 嵌套结构体：姓名（包含姓和名）
struct Name {
    char first[20];  // 名
    char last[20];   // 姓
};

// 枚举：性别（C语言没有boolean，用枚举代替）
enum Gender {
    MALE,    // 男性 = 0
    FEMALE   // 女性 = 1
};

// 嵌套结构体：公司
struct Company {
    char name[20];      // 公司名称
    int employees;     // 员工数量
};

// 嵌套结构体：人（包含姓名、性别、公司）
struct Person {
    struct Name name;       // 嵌套：姓名结构体
    enum Gender gender;     // 嵌套：性别枚举
    struct Company company; // 嵌套：公司结构体
};

// 定义时直接创建全局变量
struct Person global_person = {
    .name = {"Luke", "Doe"},
    .gender = MALE,
    .company = {"Apple", 1000}
};

/**
 * 打印人员信息
 */
void print_person(struct Person *p) {
    printf("  姓名: %s %s\n", p->name.first, p->name.last);
    printf("  性别: %s\n", p->gender == MALE ? "男" : "女");
    printf("  公司: %s, 员工数: %d\n", p->company.name, p->company.employees);
}

/**
 * 主演示函数
 */
void demo_struct_nested(void) {
    printf("=== 2. 嵌套结构体 ===\n\n");
    
    // ========================================
    // 第1步：指定初始化器（推荐）
    // ========================================
    printf("【第1步】指定初始化器 .field（推荐）\n\n");
    
    // 使用 .field 指定初始化，更清晰，不依赖顺序
    struct Person p1 = {
        .name = {"Qing", "Luo"},
        .gender = FEMALE,
        .company = {"Google", 10000}
    };
    
    print_person(&p1);
    printf("\n");
    
    // ========================================
    // 第2步：顺序初始化
    // ========================================
    printf("【第2步】顺序初始化\n\n");
    
    // 按定义顺序依次赋值（嵌套结构体需要大括号包裹）
    struct Person p2 = {
        {"Qing", "Luo"},  // name
        FEMALE,           // gender
        {"Google", 10000} // company
    };
    
    printf("  struct Person p2 = {\"Qing\", \"Luo\", FEMALE, \"Google\", 10000};\n");
    printf("  p2.name.first = %s\n", p2.name.first);
    printf("\n");
    
    // ========================================
    // 第3步：全局变量（定义时初始化）
    // ========================================
    printf("【第3步】全局结构体变量\n\n");
    
    printf("  定义 struct Person 时直接创建全局变量:\n");
    printf("  struct Person global_person = {\"Luke\", \"Doe\", MALE, \"Apple\", 1000};\n");
    printf("  ->\n");
    print_person(&global_person);
    printf("\n");
    
    // ========================================
    // 第4步：访问嵌套成员
    // ========================================
    printf("【第4步】访问嵌套成员\n\n");
    
    printf("  访问语法：结构体变量名.成员.子成员\n");
    printf("  ----------------------------------------\n");
    printf("  p1.name.first       = %s\n", p1.name.first);
    printf("  p1.name.last        = %s\n", p1.name.last);
    printf("  p1.gender           = %d\n", p1.gender);
    printf("  p1.company.name     = %s\n", p1.company.name);
    printf("  p1.company.employees = %d\n", p1.company.employees);
    printf("\n");
    
    // ========================================
    // Java 对比
    // ========================================
    printf("【Java 对比】\n\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  class Name {\n");
    printf("      String first, last;\n");
    printf("  }\n");
    printf("  \n");
    printf("  class Person {\n");
    printf("      Name name;\n");
    printf("      String gender;\n");
    printf("      Company company;\n");
    printf("  }\n");
    printf("  \n");
    printf("  Person p = new Person();\n");
    printf("  p.name.first = \"Qing\";\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  struct Person {\n");
    printf("      struct Name name;\n");
    printf("      enum Gender gender;\n");
    printf("      struct Company company;\n");
    printf("  };\n");
    printf("  \n");
    printf("  struct Person p;\n");
    printf("  p.name.first 访问嵌套成员\n");
    printf("  // 注意：C 没有 class，用 struct 代替\n");
    printf("\n");
}
