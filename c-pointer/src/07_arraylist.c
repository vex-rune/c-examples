#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ============================================
// Java ArrayList 的 C 语言实现
// ============================================

/**
 * 动态数组结构体
 * 
 * Java 的 ArrayList 内部就是这样的结构：
 * public class ArrayList {
 *     private Object[] elementData;  // 对应这里的 data
 *     private int size;               // 对应这里的 size
 *     // capacity 是内部计算的，不需要单独存储
 * }
 */
typedef struct {
    int *data;      // 【指向数组的指针】存放数据的数组
    int size;       // 【当前元素个数】已有多少个元素
    int capacity;   // 【数组容量】最多能存多少个元素
} ArrayList;

/**
 * 创建 ArrayList
 * 
 * 相当于 Java 的：
 * ArrayList<Integer> list = new ArrayList<>();
 */
ArrayList* arraylist_create(void) {
    // 1. 给 ArrayList 结构体分配内存
    int arraylist_size = sizeof(ArrayList); // 得到 ArrayList 结构体的在内存中的大小
    ArrayList *p_array_list = (ArrayList*)malloc(arraylist_size); // 分配内存， 得到 ArrayList 结构体的指针
    
    // 2. 设置初始容量（类似 Java 的默认容量 10）
    p_array_list->capacity = 4;           // 初始容量为4
    
    // 3. 当前没有元素
    p_array_list->size = 0;
    
    // 4. 给数据数组分配内存
    p_array_list->data = (int*)malloc(sizeof(int) * p_array_list->capacity);
    
    return p_array_list;  // 返回创建好的 ArrayList的指针
}

/**
 * 自动扩容（当容量不够时调用）
 * 
 * 扩容策略：容量翻倍
 * 4 -> 8 -> 16 -> 32 -> ...
 * 
 * 相当于 Java 的：
 * private void grow() {
 *     int newCapacity = oldCapacity * 2;
 *     elementData = Arrays.copyOf(elementData, newCapacity);
 * }
 */
void arraylist_expand(ArrayList *list) {
    // 如果当前元素个数 >= 容量，就需要扩容
    if (list->size >= list->capacity) {
        
        // 1. 计算新容量（扩容为原来的2倍）
        int new_capacity = list->capacity * 2;
        
        // 2. 分配新的更大的数组
        int *new_data = (int*)malloc(sizeof(int) * new_capacity);
        
        // 3. 把旧数组的数据复制到新数组
        //    memcpy(目标, 源, 复制的字节数)
        memcpy(new_data, list->data, sizeof(int) * list->size);
        
        // 4. 释放旧的数组（重要！否则内存泄漏）
        free(list->data);
        
        // 5. 更新指向新数组
        list->data = new_data;
        
        // 6. 更新容量
        list->capacity = new_capacity;
        
        printf("  [扩容] 容量: %d -> %d\n", new_capacity / 2, new_capacity);
    }
}

/**
 * 添加元素（对应 Java 的 add）
 * 
 * 相当于 Java 的：
 * list.add(10);
 */
void arraylist_add(ArrayList *list, int value) {
    // 1. 先检查是否需要扩容
    arraylist_expand(list);
    
    // 2. 把新元素放到数组末尾
    list->data[list->size] = value;
    
    // 3. 元素个数+1
    list->size++;
}

/**
 * 获取元素（对应 Java 的 get）
 * 
 * 相当于 Java 的：
 * int value = list.get(0);
 */
int arraylist_get(ArrayList *list, int index) {
    // 检查索引是否越界
    if (index < 0 || index >= list->size) {
        printf("  错误: 索引越界！index=%d, size=%d\n", index, list->size);
        return -1;
    }
    
    // 返回指定位置的元素
    return list->data[index];
}

/**
 * 获取当前元素个数
 * 
 * 相当于 Java 的：list.size()
 */
int arraylist_size(ArrayList *list) {
    return list->size;
}

/**
 * 获取最大值
 * 
 * 相当于 Java 的：
 * int max = Collections.max(list);
 */
int arraylist_max(ArrayList *list) {
    if (list->size == 0) {
        printf("  错误: 列表为空！\n");
        return -1;
    }
    
    int max = list->data[0];
    for (int i = 1; i < list->size; i++) {
        if (list->data[i] > max) {
            max = list->data[i];
        }
    }
    return max;
}

/**
 * 获取数组容量
 * 
 * Java 的 ArrayList 没有直接获取容量的方法
 */
int arraylist_capacity(ArrayList *list) {
    return list->capacity;
}

/**
 * 释放内存（重要！）
 * 
 * Java 有垃圾回收器自动回收
 * C 必须手动释放！
 * 
 * 相当于 Java 的：
 * list = null;  // 然后等垃圾回收
 */
void arraylist_free(ArrayList *list) {
    // 1. 先释放数据数组
    free(list->data);
    
    // 2. 再释放 ArrayList 结构体本身
    free(list);
    
    // 3. 把指针设为 NULL，避免野指针
    list = NULL;
}

/**
 * 打印 ArrayList 的内容
 */
void arraylist_print(ArrayList *list) {
    printf("  [");
    for (int i = 0; i < list->size; i++) {
        printf("%d", list->data[i]);
        if (i < list->size - 1) {
            printf(", ");
        }
    }
    printf("] size=%d, capacity=%d\n", list->size, list->capacity);
}

/**
 * 主演示函数
 */
void demo_arraylist(void) {
    printf("=== 7. Java ArrayList 的 C 实现 ===\n\n");
    
    // ========================================
    // 第1步：创建 ArrayList
    // ========================================
    printf("【第1步】创建 ArrayList\n");
    ArrayList *list = arraylist_create();// 得到指针
    printf("  arraylist_create() 创建了一个新的列表\n");
    printf("  初始容量: %d\n", list->capacity); // list->capacity 等价于 (*list).capacity 是C的写法
    printf("  初始大小: %d\n", list->size); // list->size 等价于 (*list).size 是C的写法
    printf("\n");
    
    // ========================================
    // 第2步：添加元素（观察容量变化）
    // ========================================
    printf("【第2步】添加元素（容量为4）\n");
    printf("  添加 3 个元素:\n");
    arraylist_add(list, 10);  // 容量 4
    printf("    add(10): "); arraylist_print(list);
    
    arraylist_add(list, 20);  // 容量 4
    printf("    add(20): "); arraylist_print(list);
    
    arraylist_add(list, 30);  // 容量 4
    printf("    add(30): "); arraylist_print(list);
    printf("\n");
    
    // ========================================
    // 第3步：触发扩容
    // ========================================
    printf("【第3步】触发扩容（容量为4，再添加1个就满了）\n");
    printf("  添加第4个元素:\n");
    arraylist_add(list, 40);  // 刚好满，容量 4
    printf("    add(40): "); arraylist_print(list);
    
    printf("  添加第5个元素（触发扩容）:\n");
    arraylist_add(list, 50);  // 扩容为 8
    printf("    add(50): "); arraylist_print(list);
    printf("\n");
    
    // ========================================
    // 第4步：获取元素
    // ========================================
    printf("【第4步】获取元素\n");
    printf("  list = [10, 20, 30, 40, 50]\n");
    printf("  get(0) = %d\n", arraylist_get(list, 0));
    printf("  get(2) = %d\n", arraylist_get(list, 2));
    printf("  get(4) = %d\n", arraylist_get(list, 4));
    printf("\n");
    
    // ========================================
    // 第5步：获取最大值
    // ========================================
    printf("【第5步】获取最大值\n");
    printf("  list = [10, 20, 30, 40, 50]\n");
    printf("  max(list) = %d\n", arraylist_max(list));
    printf("\n");
    
    // ========================================
    // 第6步：Java 对比
    // ========================================
    printf("【第6步】Java 对比\n");
    printf("\n");
    printf("  Java 写法:\n");
    printf("  -----------\n");
    printf("  ArrayList<Integer> list = new ArrayList<>();\n");
    printf("  list.add(10);      // 添加元素\n");
    printf("  list.add(20);\n");
    printf("  int value = list.get(0);  // 获取元素\n");
    printf("  int size = list.size();    // 获取大小\n");
    printf("  int max = Collections.max(list);  // 获取最大值\n");
    printf("\n");
    printf("  C 写法:\n");
    printf("  -------\n");
    printf("  ArrayList *list = arraylist_create();\n");
    printf("  arraylist_add(list, 10);    // 添加元素\n");
    printf("  arraylist_add(list, 20);\n");
    printf("  int value = arraylist_get(list, 0);  // 获取元素\n");
    printf("  int size = arraylist_size(list);     // 获取大小\n");
    printf("  int max = arraylist_max(list);       // 获取最大值\n");
    printf("\n");
    
    // ========================================
    // 第7步：内存释放
    // ========================================
    printf("【第7步】释放内存（重要！）\n");
    printf("  Java: 有垃圾回收器，自动释放\n");
    printf("  C:    必须手动 free，否则内存泄漏！\n");
    printf("\n");
    arraylist_free(list);
    printf("  arraylist_free(list) 已释放所有内存\n");
    printf("\n");
}
