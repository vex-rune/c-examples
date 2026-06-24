#include <stdio.h>
#include <stdlib.h>

// ============================================
// 自我引用结构体
// ============================================

/**
 * 什么是自我引用结构体？
 * 
 * 结构体中包含指向自身类型的指针
 * 这是链表、树等数据结构的基础
 * 
 * struct Node {
 *     int data;          // 数据
 *     struct Node *next; // 指向下一个 Node 的指针
 * };
 * 
 * 注意：C语言必须写完整的 "struct Node*"
 * 不能只写 "Node*"，否则编译器会报错
 */

// 链表节点结构体
struct Node {
    int data;             // 节点数据
    struct Node *next;     // 指向下一个节点的指针
};
//                 ^^^^^^^^^^^^^^^^^^^^^^
//                 注意：必须写完整的 struct Node*
//                 不能只写 Node* ！

/**
 * 打印链表（从头到尾）
 */
void print_list(struct Node *head) {
    printf("  链表: ");
    struct Node *current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf(" -> NULL\n");
}

/**
 * 创建新节点
 */
struct Node* create_node(int data) {
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/**
 * 释放链表内存
 */
void free_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        struct Node *next = current->next;
        free(current);
        current = next;
    }
}

/**
 * 主演示函数
 */
void demo_struct_self_ref(void) {
    printf("=== 3. 自我引用结构体（链表） ===\n\n");
    
    // ========================================
    // 第1步：手动创建链表
    // ========================================
    printf("【第1步】手动创建简单链表\n\n");
    
    // 创建3个节点
    struct Node node3 = {3, NULL};     // 最后一个节点
    struct Node node2 = {2, &node3};    // 中间节点，指向 node3
    struct Node node1 = {1, &node2};    // 头节点，指向 node2
    
    printf("  内存布局:\n");
    printf("  ---------\n");
    printf("  node1: data=%d, next=%p (指向node2)\n", node1.data, (void*)node1.next);
    printf("  node2: data=%d, next=%p (指向node3)\n", node2.data, (void*)node2.next);
    printf("  node3: data=%d, next=%p (NULL)\n", node3.data, (void*)node3.next);
    printf("\n");
    
    // 遍历链表
    printf("  遍历结果: ");
    struct Node *p = &node1;
    while (p != NULL) {
        printf("%d", p->data);
        if (p->next != NULL) printf(" -> ");
        p = p->next;
    }
    printf(" -> NULL\n");
    printf("\n");
    
    // ========================================
    // 第2步：访问链表节点
    // ========================================
    printf("【第2步】访问链表节点\n\n");
    
    printf("  head->data     = %d (第一个节点的数据)\n", node1.data);
    printf("  head->next->data = %d (第二个节点的数据)\n", node1.next->data);
    printf("  head->next->next->data = %d (第三个节点的数据)\n", node1.next->next->data);
    printf("\n");
    
    // ========================================
    // 第3步：动态创建链表
    // ========================================
    printf("【第3步】动态创建链表\n\n");
    
    // 使用函数创建节点
    struct Node *head = create_node(10);
    head->next = create_node(20);
    head->next->next = create_node(30);
    
    printf("  使用 malloc 动态分配节点:\n");
    printf("  head = create_node(10)\n");
    printf("  head->next = create_node(20)\n");
    printf("  head->next->next = create_node(30)\n");
    print_list(head);
    printf("\n");
    
    // 释放内存
    free_list(head);
    printf("  已释放链表内存\n");
    printf("\n");
    
    // ========================================
    // 第4步：为什么需要 struct Node*？
    // ========================================
    printf("【第4步】为什么需要完整的 struct Node*？\n\n");
    
    printf("  错误写法:\n");
    printf("  -----------\n");
    printf("  struct Node {\n");
    printf("      int data;\n");
    printf("      Node *next;  // 错误！C 编译器不认识 Node\n");
    printf("  };\n");
    printf("\n");
    
    printf("  正确写法:\n");
    printf("  -----------\n");
    printf("  struct Node {\n");
    printf("      int data;\n");
    printf("      struct Node *next;  // 正确！完整的类型名\n");
    printf("  };\n");
    printf("\n");
    
    printf("  原因: C 语言中，struct Xxx 是一个完整的类型名\n");
    printf("       Node 只是 struct Node 的别名（不能自动推断）\n");
    printf("       必须写完整的 struct Node*\n");
    printf("\n");
    
    // ========================================
    // Java 对比
    // ========================================
    printf("【Java 对比】\n\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  class Node {\n");
    printf("      int data;\n");
    printf("      Node next;  // Java 可以直接写 Node\n");
    printf("  }\n");
    printf("  \n");
    printf("  // Java 中 class 名称本身就是类型名\n");
    printf("  // 不需要像 C 那样写 class Node + struct Node\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  struct Node {\n");
    printf("      int data;\n");
    printf("      struct Node *next;  // 必须写完整的 struct Node*\n");
    printf("  };\n");
    printf("\n");
}
