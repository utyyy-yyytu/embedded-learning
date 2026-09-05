#include <stdio.h>
#include <stddef.h>  // offsetof 宏

// ========== 结构体1：有对齐问题 ==========
struct Example1 {
    char  a;    // 1字节，偏移0
    int   b;    // 4字节，需要对齐到4的倍数，偏移4（中间填充3字节）
    char  c;    // 1字节，偏移8
              // 总共9字节，但要对齐到最大成员int(4)的倍数，所以是12
};

// ========== 结构体2：改变成员顺序 ==========
struct Example2 {
    int   b;    // 4字节，偏移0
    char  a;    // 1字节，偏移4
    char  c;    // 1字节，偏移5
              // 总共6字节，对齐到4的倍数，所以是8
};

int main() {
    printf("=== 结构体大小对比 ===\n");
    printf("Example1: sizeof = %lu\n", sizeof(struct Example1));
    printf("Example2: sizeof = %lu\n", sizeof(struct Example2));

    printf("\n=== Example1 各成员偏移 ===\n");
    printf("a: 偏移 %lu, 大小 %lu\n",
           offsetof(struct Example1, a), sizeof(((struct Example1*)0)->a));
    printf("b: 偏移 %lu, 大小 %lu\n",
           offsetof(struct Example1, b), sizeof(((struct Example1*)0)->b));
    printf("c: 偏移 %lu, 大小 %lu\n",
           offsetof(struct Example1, c), sizeof(((struct Example1*)0)->c));

    printf("\n=== Example2 各成员偏移 ===\n");
    printf("b: 偏移 %lu\n", offsetof(struct Example2, b));
    printf("a: 偏移 %lu\n", offsetof(struct Example2, a));
    printf("c: 偏移 %lu\n", offsetof(struct Example2, c));

    printf("\n=== 内存布局图 ===\n");
    printf("Example1: [a][pad][pad][pad][b][b][b][b][c][pad][pad][pad]\n");
    printf("Example2: [b][b][b][b][a][c][pad][pad]\n");

    return 0;
}