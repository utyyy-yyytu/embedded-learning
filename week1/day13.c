#include <stdio.h>

// 打印一个字节的二进制
void print_binary(unsigned char x) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (x >> i) & 1);
    }
}

int main() {
    unsigned char reg = 0;

    printf("=== 位操作演示 ===\n");
    printf("初始值:    "); print_binary(reg); printf(" = %d\n", reg);

    // 置位：把第 0、2、4 位设为 1
    reg |= (1 << 0);
    reg |= (1 << 2);
    reg |= (1 << 4);
    printf("置位0,2,4: "); print_binary(reg); printf(" = %d\n", reg);

    // 读取：读第 2 位
    printf("第2位 = %d\n", (reg >> 2) & 1);

    // 清零：把第 2 位清零
    reg &= ~(1 << 2);
    printf("清零第2位: "); print_binary(reg); printf(" = %d\n", reg);

    // 取反：把第 3 位取反
    reg ^= (1 << 3);
    printf("取反第3位: "); print_binary(reg); printf(" = %d\n", reg);

    // ========== 位掩码 ==========
    printf("\n=== 位掩码 ===\n");
    unsigned int flags = 0xAB;  // 1010 1011

    // 取低 4 位
    unsigned char low = flags & 0x0F;
    printf("低4位: 0x%X\n", low);   // 0xB

    // 取高 4 位
    unsigned char high = (flags >> 4) & 0x0F;
    printf("高4位: 0x%X\n", high);  // 0xA

    // ========== 大小端判断 ==========
    printf("\n=== 大小端判断 ===\n");
    unsigned int num = 0x01020304;
    unsigned char *p = (unsigned char *)&num;

    if (p[0] == 0x04) {
        printf("小端（Little-Endian）：低位字节存低地址\n");
    } else if (p[0] == 0x01) {
        printf("大端（Big-Endian）：高位字节存低地址\n");
    }

    printf("内存中的字节顺序: ");
    for (int i = 0; i < 4; i++) {
        printf("%02x ", p[i]);
    }
    printf("\n");

    return 0;
}