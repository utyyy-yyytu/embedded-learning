#include <stdio.h>

int main() {
    int a = 10;
    int *p = &a;       // 一级指针，指向 a
    int **pp = &p;     // 二级指针，指向 p

    printf("=== 三个变量的值 ===\n");
    printf("a   = %d\n", a);          // 直接访问：10
    printf("*p  = %d\n", *p);         // 一次解(citation:10)
    printf("**pp = %d\n", **pp);      // 两次解(citation:10)

    printf("\n=== 地址关系 ===\n");
    printf("a的地址  = %p\n", (void*)&a);
    printf("p的值    = %p  （存的是a的地址）\n", (void*)p);
    printf("p的地址  = %p\n", (void*)&p);
    printf("pp的值   = %p  （存的是p的地址）\n", (void*)pp);

    printf("\n=== 通过二级指针修改 a 的值 ===\n");
    **pp = 100;        // 通过 pp 改了 a
    printf("修改后 a = %d\n", a);

    return 0;
}