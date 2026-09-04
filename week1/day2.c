#include <stdio.h>

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int len = sizeof(arr) / sizeof(arr[0]);  // 计算数组元素个数

    int *p = arr;   // arr 退化成指向第一个元素的指针，等价于 &arr[0]

    printf("=== 用指针遍历数组 ===\n");
    for (int i = 0; i < len; i++) {
        printf("arr[%d] = %d,  *(p+%d) = %d,  地址 = %p\n",
               i, arr[i], i, *(p + i), (void*)(p + i));
    }

    printf("\n=== 指针相减 ===\n");
    int *p_first = &arr[0];
    int *p_last  = &arr[4];
    printf("p_last - p_first = %ld\n", p_last - p_first);

    printf("\n=== sizeof 的区别 ===\n");
    printf("sizeof(arr) = %lu\n", sizeof(arr));   // 整个数组的大小
    printf("sizeof(p)   = %lu\n", sizeof(p));      // 指针本身的大小

    return 0;
}