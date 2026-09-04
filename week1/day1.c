#include <stdio.h>

int main() {
    int a = 42;
    int *p = &a;

    printf("a的值:       %d\n", a);
    printf("a的地址:     %p\n", (void*)&a);
    printf("p的值(地址): %p\n", (void*)p);
    printf("p指向的值:   %d\n", *p);
    printf("p自己的地址: %p\n", (void*)&p);

    *p = 100;
    printf("修改后a:     %d\n", a);

    return 0;
}