#include <stdio.h>

// 回调函数：不同的人处理数据的方式不同
void print_square(int x) {
    printf("平方: %d\n", x * x);
}

void print_double(int x) {
    printf("翻倍: %d\n", x * 2);
}

void print_negate(int x) {
    printf("取反: %d\n", -x);
}

// 一个通用的处理函数，接收数组和一个"怎么处理"的回调
void process_array(int arr[], int len, void (*callback)(int)) {
    for (int i = 0; i < len; i++) {
        callback(arr[i]);   // 调用回调函数
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int len = 5;

    printf("=== 平方 ===\n");
    process_array(arr, len, print_square);

    printf("\n=== 翻倍 ===\n");
    process_array(arr, len, print_double);

    printf("\n=== 取反 ===\n");
    process_array(arr, len, print_negate);

    return 0;
}