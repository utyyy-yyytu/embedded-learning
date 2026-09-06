#include <stdio.h>

size_t my_strlen(const char * s){
    const char *p=s;
    while(*p!='\0'){
        p++;
    }
    return p-s;
}

char *my_strcpy(char *dest,const char *s){
    char *p=dest;
    while((*dest++=*s++)!='\0');

    return p;
}

char *my_strcat(char *de,const char *s){
    const char *p=de;
    while(*de!='\0'){
        de++;
    }
    while((*de++=*s++)!='0');

    return p;
}

char *my_strcmp(const char *s1,const char *s2){
    while(*s1&&*s1==*s2){
        s1++;
        s2++;
    }
    return (unsigned char)*s1-(unsigned char)*s2;
}

int main(){
    // 测试 strlen
    printf("=== my_strlen ===\n");
    printf("len of \"hello\" = %d\n", my_strlen("hello"));
    printf("len of \"\" = %d\n", my_strlen(""));

    // 测试 strcpy
    printf("\n=== my_strcpy ===\n");
    char buf[50];
    my_strcpy(buf, "Hello, Embedded!");
    printf("buf = %s\n", buf);

    // 测试 strcat
    printf("\n=== my_strcat ===\n");
    my_strcat(buf, " C++ Linux.");
    printf("拼接后: %s\n", buf);

    // 测试 strcmp
    printf("\n=== my_strcmp ===\n");
    printf("strcmp(\"abc\", \"abc\") = %d\n", my_strcmp("abc", "abc"));  // 0
    printf("strcmp(\"abc\", \"abd\") = %d\n", my_strcmp("abc", "abd"));  // 负数
    printf("strcmp(\"abd\", \"abc\") = %d\n", my_strcmp("abd", "abc"));  // 正数

    // ========== 缓冲区溢出演示 ==========
    printf("\n=== 缓冲区溢出（危险！）===\n");
    char small[5];
    // my_strcpy(small, "Hello World!");  // 危险！"Hello World!" 超过5字节
    // 只能放 "Hell" + \0 刚好5字节
    my_strcpy(small, "Hell");
    printf("safe: %s\n", small);

    return 0;
}