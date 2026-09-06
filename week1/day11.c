#include <stdio.h>

// ========== 位域 ==========
struct Flags {
    unsigned int ready   : 1;   // 1 bit:0 或 1
    unsigned int mode    : 2;   // 2 bit: 0~3
    unsigned int channel : 5;   // 5 bit: 0~31
};

// ========== 联合体 ==========
union Data {
    int i;
    float f;
    char c;
};

// ========== 结构体指针 ==========
struct Student {
    char name[20];
    int age;
    float score;
};

void print_student(struct Student *p) {
    printf("姓名: %s, 年龄: %d, 成绩: %.1f\n",
           p->name, p->age, p->score);
}

int main() {
    // ----- 位域 -----
    printf("=== 位域 ===\n");
    struct Flags f = {1, 3, 25};
    printf("ready = %u, mode = %u, channel = %u\n",
           f.ready, f.mode, f.channel);
    printf("sizeof(Flags) = %lu\n", sizeof(struct Flags));

    // ----- 联合体 -----
    printf("\n=== 联合体 ===\n");
    union Data d;
    d.i = 42;
    printf("写入 int: d.i = %d\n", d.i);

    d.f = 3.14f;
    printf("写入 float: d.f = %f\n", d.f);
    printf("此时读 d.i = %d (乱码，因为float和int的编码方式不同)\n", d.i);

    d.c = 'A';
    printf("写入 char: d.c = %c\n", d.c);
    printf("sizeof(union Data) = %lu\n", sizeof(union Data));

    // ----- 联合体的常见用途：类型双关 -----
    printf("\n=== 联合体用途：查看float的字节 ===\n");
    union {
        float f;
        unsigned char bytes[4];
    } converter;
    converter.f = 3.14f;
    printf("3.14 的字节: ");
    for (int i = 0; i < 4; i++) {
        printf("%02x ", converter.bytes[i]);
    }
    printf("\n");

    // ----- 结构体指针 -----
    printf("\n=== 结构体指针 ===\n");
    struct Student s = {"张三", 20, 95.5};
    struct Student *p = &s;

    printf("用 . 访问: %s, %d, %.1f\n", s.name, s.age, s.score);
    printf("用 -> 访问: %s, %d, %.1f\n", p->name, p->age, p->score);

    printf("\n通过函数传递结构体指针:\n");
    print_student(p);

    return 0;
}