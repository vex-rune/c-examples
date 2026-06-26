#include <stdio.h>
#include <string.h>

// ============================================
// 结构体与共用体
// ============================================

/**
 * 本节内容：
 * 1. 结构体 (struct) - 所有成员独立存储
 * 2. 共用体 (union) - 所有成员共享同一块内存
 * 3. 两者的区别和应用场景
 */

// ============================================
// 第1部分：结构体
// ============================================

// 结构体定义
struct Data {
    int type;           // 类型标识
    int int_value;      // 整数值
    float float_value;  // 浮点值
    char str_value[20]; // 字符串
};

// ============================================
// 第2部分：共用体
// ============================================

// 共用体定义
union SharedData {
    int int_value;      // 4字节
    float float_value; // 4字节
    char str_value[20]; // 20字节
    // 所有成员共享同一块内存！
    // 内存大小 = 最大成员的大小 = 20字节
};

// ============================================
// 第3部分：结构体与共用体结合
// ============================================

// 使用结构体包装共用体（常见用法）
struct Message {
    int type;           // 消息类型
    union {             // 共用体：节省内存
        int int_data;
        float float_data;
        char str_data[20];
    } payload;          // payload 是共用体变量名
};

// 另一种写法：匿名共用体
struct Message2 {
    int type;
    union {             // 匿名共用体，可以直接访问成员
        int int_data;
        float float_data;
        char str_data[20];
    };
};

/**
 * 打印内存布局
 */
void print_memory_info(const char *name, int size) {
    printf("  %s: 大小 = %d 字节\n", name, size);
    printf("  内存布局: [");
    for (int i = 0; i < size; i++) {
        printf("__");
        if (i < size - 1) printf(" ");
    }
    printf("]\n\n");
}

/**
 * 演示函数
 */
void demo_struct_union(void) {
    printf("=== 5. 结构体与共用体 ===\n\n");
    
    // ========================================
    // 第1步：结构体 vs 共用体的内存布局
    // ========================================
    printf("【第1步】内存布局对比\n\n");
    
    // 结构体
    struct Data data_struct;
    printf("  struct Data {\n");
    printf("      int type;           // 4字节\n");
    printf("      int int_value;      // 4字节\n");
    printf("      float float_value;  // 4字节\n");
    printf("      char str_value[20]; // 20字节\n");
    printf("  };\n");
    print_memory_info("struct Data", sizeof(data_struct));
    printf("  总大小 = 4 + 4 + 4 + 20 = 32 字节\n\n");
    
    // 共用体
    union SharedData data_union;
    printf("  union SharedData {\n");
    printf("      int int_value;      // 4字节\n");
    printf("      float float_value; // 4字节\n");
    printf("      char str_value[20]; // 20字节\n");
    printf("  };\n");
    print_memory_info("union SharedData", sizeof(data_union));
    printf("  总大小 = max(4, 4, 20) = 20 字节\n\n");
    
    printf("  ┌─────────────────────────────────────────────┐\n");
    printf("  │ struct - 每个成员独立存储                     │\n");
    printf("  │ [type][int][float][str...    ]              │\n");
    printf("  │  4    4    4     20                        │\n");
    printf("  ├─────────────────────────────────────────────┤\n");
    printf("  │ union - 所有成员共享同一块内存               │\n");
    printf("  │ [    str_value[20] (共享)    ]               │\n");
    printf("  │  ^int  ^float                              │\n");
    printf("  │  都指向同一块内存！                          │\n");
    printf("  └─────────────────────────────────────────────┘\n\n");
    
    
    // ========================================
    // 第2步：验证共用体的共享内存
    // ========================================
    printf("【第2步】验证共用体的共享内存\n\n");
    
    union SharedData u;
    
    // 给 int_value 赋值
    u.int_value = 0x41424344;  // ASCII: 'D', 'C', 'B', 'A' (小端序)
    printf("  u.int_value = 0x%X (十六进制)\n", u.int_value);
    printf("  u.int_value = %d (十进制)\n", u.int_value);
    printf("  u.float_value = %f\n", u.float_value);
    printf("  u.str_value = \"%s\"\n", u.str_value);
    printf("\n");
    
    // 修改 float_value，会影响 int_value
    u.float_value = 3.14f;
    printf("  修改 u.float_value = 3.14f 后:\n");
    printf("  u.int_value = 0x%X\n", u.int_value);
    printf("  u.float_value = %f\n", u.float_value);
    printf("\n");
    
    // 修改 str_value，会影响其他成员
    strcpy(u.str_value, "Hello");
    printf("  修改 u.str_value = \"Hello\" 后:\n");
    printf("  u.int_value = 0x%X\n", u.int_value);
    printf("  u.float_value = %f\n", u.float_value);
    printf("  u.str_value = \"%s\"\n", u.str_value);
    printf("\n");
    
    
    // ========================================
    // 第3步：结构体与共用体结合（常见用法）
    // ========================================
    printf("【第3步】结构体包裹共用体（常见用法）\n\n");
    
    printf("  struct Message {\n");
    printf("      int type;           // 类型标识\n");
    printf("      union {\n");
    printf("          int int_data;\n");
    printf("          float float_data;\n");
    printf("          char str_data[20];\n");
    printf("      } payload;          // 负载数据\n");
    printf("  };\n\n");
    
    struct Message msg;
    
    // 类型1：发送整数
    msg.type = 1;
    msg.payload.int_data = 100;
    printf("  msg.type = 1 (整数消息)\n");
    printf("  msg.payload.int_data = %d\n\n", msg.payload.int_data);
    
    // 类型2：发送浮点数
    msg.type = 2;
    msg.payload.float_data = 99.9f;
    printf("  msg.type = 2 (浮点消息)\n");
    printf("  msg.payload.float_data = %.1f\n\n", msg.payload.float_data);
    
    // 类型3：发送字符串
    msg.type = 3;
    strcpy(msg.payload.str_data, "Hello");
    printf("  msg.type = 3 (字符串消息)\n");
    printf("  msg.payload.str_data = \"%s\"\n\n", msg.payload.str_data);
    
    
    // ========================================
    // 第4步：匿名共用体
    // ========================================
    printf("【第4步】匿名共用体\n\n");
    
    printf("  struct Message2 {\n");
    printf("      int type;\n");
    printf("      union {            // 匿名共用体\n");
    printf("          int int_data;\n");
    printf("          float float_data;\n");
    printf("      };                // 注意：没有变量名！\n");
    printf("  };\n\n");
    
    struct Message2 msg2;
    msg2.type = 1;
    msg2.int_data = 200;  // 直接访问，不需要 .payload
    
    printf("  msg2.int_data = %d  // 直接访问，无需 msg2.payload.int_data\n\n", msg2.int_data);
    
    
    // ========================================
    // 第5步：枚举与共用体结合
    // ========================================
    printf("【第5步】枚举 + 共用体（类型安全）\n\n");
    
    enum DataType { INT, FLOAT, STRING };
    
    struct TaggedData {
        enum DataType type;  // 枚举标记类型
        union {
            int i;
            float f;
            char s[20];
        } data;
    };
    
    printf("  enum DataType { INT, FLOAT, STRING };\n");
    printf("  struct TaggedData {\n");
    printf("      enum DataType type;\n");
    printf("      union { int i; float f; char s[20]; } data;\n");
    printf("  };\n\n");
    
    struct TaggedData td;
    td.type = INT;
    td.data.i = 42;
    
    printf("  td.type = INT (%d), td.data.i = %d\n\n", td.type, td.data.i);
    
    
    // ========================================
    // Java 对比
    // ========================================
    printf("【Java 对比】\n\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  // Java 没有 union，用类代替\n");
    printf("  class Message {\n");
    printf("      int type;\n");
    printf("      Object data;  // 万能容器\n");
    printf("  }\n");
    printf("  \n");
    printf("  // 或者用多态\n");
    printf("  interface Data { }\n");
    printf("  class IntData implements Data { int value; }\n");
    printf("  class FloatData implements Data { float value; }\n");
    printf("  class StringData implements Data { String value; }\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  // union 节省内存，但需程序员自己维护类型\n");
    printf("  struct Message {\n");
    printf("      int type;  // 必须手动跟踪类型！\n");
    printf("      union { int i; float f; char s[20]; } data;\n");
    printf("  };\n");
    printf("\n");
    
    
    // ========================================
    // 总结
    // ========================================
    printf("【总结】\n\n");
    printf("  ┌──────────┬──────────────────────────────────┐\n");
    printf("  │          │ struct          │ union         │\n");
    printf("  ├──────────┼─────────────────┼───────────────┤\n");
    printf("  │ 内存     │ 所有成员独立     │ 所有成员共享   │\n");
    printf("  │ 大小     │ = 所有成员之和   │ = 最大成员    │\n");
    printf("  │ 访问     │ 同时访问所有成员  │ 同一时刻一个  │\n");
    printf("  │ 用途     │ 组合不同数据     │ 节省内存/变体  │\n");
    printf("  └──────────┴─────────────────┴───────────────┘\n\n");
}
