#include <stdio.h>

int main() {
    // ==================== 指针数组 ====================
    printf("=== 指针数组 int *arr[3] ===\n");

    int a = 10, b = 20, c = 30;
    int *arr[3] = {&a, &b, &c};   // 一个数组，3个元素都是指针

    for (int i = 0; i < 3; i++) {
        printf("arr[%d] 存的地址: %p, 指向的值: %d\n",
               i, (void*)arr[i], *arr[i]);
    }

    // ==================== 数组指针 ====================
    printf("\n=== 数组指针 int (*p)[5] ===\n");

    int nums[5] = {100, 200, 300, 400, 500};
    int (*p)[5] = &nums;   // p 指向整个数组 nums

    // 通过数组指针访问数组元素
    for (int i = 0; i < 5; i++) {
        printf("(*p)[%d] = %d\n", i, (*p)[i]);
    }

    // ==================== sizeof 对比 ====================
    printf("\n=== sizeof 对比 ===\n");
    printf("sizeof(arr) = %lu\n", sizeof(arr));   // 指针数组的大小
    printf("sizeof(p)   = %lu\n", sizeof(p));      // 数组指针的大小
    printf("sizeof(nums)= %lu\n", sizeof(nums));   // 原数组的大小

    return 0;
}