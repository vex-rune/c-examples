#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ============================================
// 结构体与指针
// ============================================

/**
 * 本节内容：
 * 1. 结构体包含不同类型的数据
 * 2. 结构体指针的用法
 * 3. 指向结构体成员的指针
 * 4. 结构体数组与指针
 */

// ============================================
// 第1部分：结构体包含多种数据类型
// ============================================

// 定义一个包含多种数据类型的结构体
struct Student {
    int id;                // 整数
    char name[20];         // 字符数组（字符串）
    char gender;           // 字符
    float score;           // 单精度浮点数
    double gpa;            // 双精度浮点数
    int *grades;           // 指向整数的指针
    struct Student *best_friend;  // 指向同类型结构体的指针
};

// 打印学生信息
void print_student(struct Student *s) {
    printf("  ID=%d, Name=%s, Gender=%c, Score=%.1f, GPA=%.2f\n", 
           s->id, s->name, s->gender, s->score, s->gpa);
    if (s->grades != NULL) {
        printf("  成绩: %d, %d, %d\n", s->grades[0], s->grades[1], s->grades[2]);
    }
    if (s->best_friend != NULL) {
        printf("  最好的朋友: %s\n", s->best_friend->name);
    }
}

// ============================================
// 第2部分：结构体指针
// ============================================

// 普通结构体变量
struct Point {
    int x;
    int y;
};

// 打印坐标（传值）
void print_point_value(struct Point p) {
    printf("  [传值] x=%d, y=%d\n", p.x, p.y);
}

// 打印坐标（传指针）
void print_point_pointer(struct Point *p) {
    printf("  [传指针] x=%d, y=%d\n", p->x, p->y);
}

// 修改坐标（传指针）
void move_point(struct Point *p, int dx, int dy) {
    p->x += dx;
    p->y += dy;
}

// ============================================
// 第3部分：指向结构体成员的指针
// ============================================

struct Person {
    char name[20];
    int age;
    double salary;
};

// 打印整数
void print_int(int *p) {
    printf("  [int*] value=%d\n", *p);
}

// 打印double
void print_double(double *p) {
    printf("  [double*] value=%.2f\n", *p);
}

// ============================================
// 第4部分：结构体数组与指针
// ============================================

struct Item {
    int id;
    char name[20];
    int quantity;
};

/**
 * 演示函数
 */
void demo_struct_pointer(void) {
    printf("=== 4. 结构体与指针 ===\n\n");
    
    // ========================================
    // 第1步：结构体包含多种数据类型
    // ========================================
    printf("【第1步】结构体包含多种数据类型\n\n");
    
    printf("  struct Student {\n");
    printf("      int id;                // 整数\n");
    printf("      char name[20];         // 字符数组\n");
    printf("      char gender;           // 字符\n");
    printf("      float score;           // 单精度浮点\n");
    printf("      double gpa;            // 双精度浮点\n");
    printf("      int *grades;           // 指向int的指针\n");
    printf("      struct Student *best_friend;  // 指向自身的指针\n");
    printf("  };\n\n");
    
    // 创建学生
    struct Student stu;
    stu.id = 1001;
    strcpy(stu.name, "张三");
    stu.gender = 'M';
    stu.score = 85.5f;
    stu.gpa = 3.5;
    
    // 动态分配成绩数组
    stu.grades = (int*)malloc(3 * sizeof(int));
    stu.grades[0] = 90;
    stu.grades[1] = 85;
    stu.grades[2] = 88;
    
    // best_friend 暂不设置
    stu.best_friend = NULL;
    
    printf("  创建学生:\n");
    print_student(&stu);
    printf("\n");
    
    free(stu.grades);
    
    
    // ========================================
    // 第2步：结构体指针（传值 vs 传指针）
    // ========================================
    printf("【第2步】结构体指针\n\n");
    
    struct Point point = {10, 20};
    
    printf("  struct Point point = {10, 20};\n\n");
    
    // 传值：复制整个结构体
    printf("  传值（复制整个结构体）:\n");
    printf("  -----------------------\n");
    printf("  void print_point_value(struct Point p)\n");
    printf("  调用时复制一份 point，函数内修改不影响原变量\n");
    print_point_value(point);
    printf("\n");
    
    // 传指针：只复制指针大小
    printf("  传指针（只复制地址）:\n");
    printf("  --------------------\n");
    printf("  void print_point_pointer(struct Point *p)\n");
    printf("  调用时只传递地址，函数内修改会影响原变量\n");
    print_point_pointer(&point);
    printf("\n");
    
    // 通过指针修改
    printf("  通过指针修改结构体:\n");
    printf("  ------------------\n");
    printf("  move_point(&point, 5, -3);  // 移动坐标\n");
    move_point(&point, 5, -3);
    printf("  移动后: x=%d, y=%d\n", point.x, point.y);
    printf("\n");
    
    printf("  传值 vs 传指针:\n");
    printf("  ----------------------------------------------\n");
    printf("  | 方式 | 复制大小 | 修改原变量 | 性能 |\n");
    printf("  |------|----------|------------|------|\n");
    printf("  | 传值 | 结构体大小 | 否 | 慢 |\n");
    printf("  | 传指针 | 8字节(64位) | 是 | 快 |\n");
    printf("  ----------------------------------------------\n");
    printf("\n");
    
    
    // ========================================
    // 第3步：指向结构体成员的指针
    // ========================================
    printf("【第3步】指向结构体成员的指针\n\n");
    
    struct Person person = {"李四", 25, 10000.0};
    
    printf("  struct Person person = {\"李四\", 25, 10000.0};\n\n");
    
    // 指向 int 成员
    int *p_age = &person.age;
    printf("  int *p_age = &person.age;\n");
    print_int(p_age);
    
    // 指向 double 成员
    double *p_salary = &person.salary;
    printf("  double *p_salary = &person.salary;\n");
    print_double(p_salary);
    
    // 注意：不能指向数组成员作为指针参数
    // char *p_name = person.name;  // 可以，但不推荐
    // printf("%s\n", p_name);
    printf("\n");
    
    
    // ========================================
    // 第4步：结构体数组与指针
    // ========================================
    printf("【第4步】结构体数组与指针\n\n");
    
    // 定义结构体数组
    struct Item items[] = {
        {1, "苹果", 10},
        {2, "香蕉", 20},
        {3, "橘子", 15}
    };
    int item_count = sizeof(items) / sizeof(items[0]);
    
    printf("  struct Item items[] = {{1,\"苹果\",10}, {2,\"香蕉\",20}, {3,\"橘子\",15}};\n\n");
    
    // 数组名就是首地址
    printf("  结构体数组的指针运算:\n");
    printf("  --------------------\n");
    printf("  items       = %p (数组首地址)\n", (void*)items);
    printf("  items[0]    = %p (第1个元素的地址)\n", (void*)&items[0]);
    printf("  items + 1   = %p (第2个元素的地址)\n", (void*)(items + 1));
    printf("  &items[1]  = %p\n\n", (void*)&items[1]);
    
    // 用指针遍历数组
    printf("  用指针遍历数组:\n");
    printf("  -------------\n");
    struct Item *p_item = items;
    for (int i = 0; i < item_count; i++) {
        printf("  第%d项: id=%d, name=%s, quantity=%d\n", 
               i+1, (p_item+i)->id, (p_item+i)->name, (p_item+i)->quantity);
    }
    printf("\n");
    
    // 指针算术运算
    printf("  指针算术运算:\n");
    printf("  ------------\n");
    printf("  *(items + 0) 等价于 items[0]\n");
    printf("  *(items + 1) 等价于 items[1]\n");
    printf("  &items[i]   等价于 items + i\n");
    printf("  p_item[i]   等价于 *(p_item + i)\n");
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
    printf("      float score;\n");
    printf("      double gpa;\n");
    printf("      int[] grades;\n");
    printf("      Student bestFriend;\n");
    printf("  }\n");
    printf("  \n");
    printf("  // Java 都是引用传递，不用区分传值还是传指针\n");
    printf("  void printStudent(Student s) {\n");
    printf("      s.name = \"新名字\";  // 直接修改\n");
    printf("  }\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  struct Student {\n");
    printf("      int id;\n");
    printf("      char name[20];\n");
    printf("      char gender;\n");
    printf("      float score;\n");
    printf("      double gpa;\n");
    printf("      int *grades;\n");
    printf("      struct Student *best_friend;\n");
    printf("  };\n");
    printf("  \n");
    printf("  // C 必须区分传值还是传指针\n");
    printf("  void printStudent(struct Student *s) {  // 传指针才能修改\n");
    printf("      strcpy(s->name, \"新名字\");\n");
    printf("  }\n");
    printf("\n");
}
