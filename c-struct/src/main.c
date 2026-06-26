#include <stdio.h>

// 函数声明
void demo_struct_basic(void);
void demo_struct_nested(void);
void demo_struct_self_ref(void);
void demo_struct_pointer(void);
void demo_struct_union(void);

// 主函数
int main(void) {
    printf("############################################\n");
    printf("#                                          #\n");
    printf("#          C 语言结构体专题                 #\n");
    printf("#                                          #\n");
    printf("############################################\n\n");

    demo_struct_basic();
    demo_struct_nested();
    demo_struct_self_ref();
    demo_struct_pointer();
    demo_struct_union();

    printf("############################################\n");
    printf("#            程序执行完毕                   #\n");
    printf("############################################\n");

    return 0;
}
