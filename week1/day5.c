#include <stdio.h>

// 两个简单的函数
int add(int a, int b) { return a + b; }
int sub(int a, int b) { return a - b; }

int main() {
    // 声明函数指针，指向 add
    int (*p)(int, int) = add;

    printf("=== 直接调用 vs 通过函数指针调用 ===\n");
    printf("add(3, 2) = %d\n", add(3, 2));
    printf("p(3, 2)   = %d\n", p(3, 2));

    // 换一个函数，让 p 指向 sub
    p = sub;
    printf("\n换成 sub 之后：\n");
    printf("sub(3, 2) = %d\n", sub(3, 2));
    printf("p(3, 2)   = %d\n", p(3, 2));

    // 函数指针数组：实现一个简单的"计算器"
    printf("\n=== 函数指针数组 ===\n");
    int (*ops[2])(int, int) = {add, sub};
    char *names[] = {"add", "sub"};

    for (int i = 0; i < 2; i++) {
        printf("%s(10, 3) = %d\n", names[i], ops[i](10, 3));
    }

    return 0;
}