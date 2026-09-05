#include <stdio.h>
#include <stdlib.h>  // malloc, free 在这个头文件里

int main() {
    // ========== 栈上的变量 ==========
    int a = 10;
    printf("栈上: a = %d, 地址 = %p\n", a, (void*)&a);

    // ========== 堆上申请内存 ==========
    // malloc 申请一块能存 5 个 int 的内存
    int *arr = (int *)malloc(5 * sizeof(int));

    // 检查是否申请成功（重要！malloc 可能失败返回 NULL）
    if (arr == NULL) {
        printf("内存申请失败！\n");
        return 1;
    }

    // 使用堆内存
    for (int i = 0; i < 5; i++) {
        arr[i] = (i + 1) * 10;
    }

    printf("\n堆上: arr = %p\n", (void*)arr);
    for (int i = 0; i < 5; i++) {
        printf("  arr[%d] = %d, 地址 = %p\n", i, arr[i], (void*)&arr[i]);
    }

    // 用完必须释放！
    free(arr);
    arr = NULL;  // 好习惯：free 后把指针置为 NULL，防止野指针

    printf("\nfree 之后，arr = %p\n", (void*)arr);

    // ========== calloc 对比 ==========
    // calloc 申请并初始化为 0
    int *buf = (int *)calloc(3, sizeof(int));
    printf("\ncalloc 初始化为 0:\n");
    for (int i = 0; i < 3; i++) {
        printf("  buf[%d] = %d\n", i, buf[i]);
    }
    free(buf);
    buf = NULL;

    return 0;
}