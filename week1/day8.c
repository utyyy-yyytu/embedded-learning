#include <stdio.h>

int main() {
    int a = 10, b = 20;

    // ========== const 在 * 左边：不能改值，能改指向 ==========
    printf("=== const int *p (锁值) ===\n");
    const int *p1 = &a;
    // *p1 = 100;    // 编译错误！不能通过 p1 改值
    p1 = &b;         // OK！可以改指向
    printf("*p1 = %d (指向了b)\n", *p1);

    // ========== const 在 * 右边：能改值，不能改指向 ==========
    printf("\n=== int * const p (锁指针) ===\n");
    int * const p2 = &a;
    *p2 = 100;       // OK！可以通过 p2 改值
    // p2 = &b;      // 编译错误！不能改指向
    printf("*p2 = %d (a被改成了100)\n", *p2);
    printf("a = %d\n", a);

    // ========== 两边都有 const：都不能改 ==========
    printf("\n=== const int * const p (全锁) ===\n");
    const int * const p3 = &a;
    // *p3 = 200;    // 编译错误
    // p3 = &b;      // 编译错误
    printf("*p3 = %d\n", *p3);

    // ========== int const *p 和 const int *p 完全一样 ==========
    printf("\n=== int const *p (等价写法) ===\n");
    int const *p4 = &a;
    // *p4 = 300;    // 编译错误，和 const int *p 一样
    p4 = &b;         // OK
    printf("*p4 = %d\n", *p4);

    return 0;
}