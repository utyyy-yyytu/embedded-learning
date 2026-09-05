#include <stdio.h>

// ========== static 用法1：局部变量 ==========
void counter() {
    static int count = 0;  // 只初始化一次
    count++;
    printf("count = %d\n", count);
}

// ========== static 用法2：全局变量 ==========
static int file_secret = 42;  // 只有本文件能访问

// ========== volatile 模拟演示 ==========
volatile int interrupt_flag = 0;

void simulate_interrupt() {
    interrupt_flag = 1;  // 模拟中断修改了这个变量
}

int main() {
    printf("=== static 局部变量 ===\n");
    counter();  // count = 1
    counter();  // count = 2
    counter();  // count = 3

    printf("\n=== static 全局变量 ===\n");
    printf("file_secret = %d (只能本文件访问)\n", file_secret);

    printf("\n=== volatile ===\n");
    printf("interrupt_flag = %d\n", interrupt_flag);
    simulate_interrupt();
    printf("中断后 interrupt_flag = %d\n", interrupt_flag);

    // extern 用法：因为 file_secret 是 static 的，
    // 如果在另一个文件中 extern int file_secret; 会链接失败
    extern int file_secret;  // 同一个文件内，这个OK
    printf("\nextern 访问 file_secret = %d\n", file_secret);

    return 0;
}