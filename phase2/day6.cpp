#include <cstdio>
#include <cstring>
#include <string>

// ===== 实验1：裸指针 + 默认拷贝 → double free =====
struct BadBox {
    int* p;
    BadBox(int v) : p(new int(v)) {}
    ~BadBox() { delete p; }
    // 没有自定义拷贝构造/赋值 → 编译器生成浅拷贝
};

void testBad() {
    BadBox a(42);
    BadBox b = a;              // 浅拷贝：b.p 和 a.p 指向同一块内存
    printf("a.p=%p b.p=%p\n", (void*)a.p, (void*)b.p);   // 相同地址
    // 离开作用域：b 先析构 delete p，a 再析构 delete p → double free
}

// ===== 实验2：std::string 成员 + 默认拷贝 → 各自独立 =====
struct GoodBox {
    std::string s;             // string 自己实现了深拷贝
    GoodBox(const char* v) : s(v) {}
};

void testGood() {
    GoodBox a("hello");
    GoodBox b = a;             // 拷贝构造 string → 深拷贝
    b.s[0] = 'H';
    printf("a.s=%s b.s=%s\n", a.s.c_str(), b.s.c_str());  // "hello" 和 "Hello"
}

// ===== 实验3：同时有析构 + 默认拷贝（判断力） =====
struct Mixed {
    int* p;
    Mixed(int v) : p(new int(v)) {}
    ~Mixed() { delete p; }
    // 有析构，但没禁拷贝、没写拷贝构造
};

int main() {
    printf("--- 实验2：GoodBox ---\n");
    testGood();

    printf("--- 实验1：BadBox（预期 double free）---\n");
    testBad();

    // 实验3：单独跑，观察崩溃
    printf("--- 实验3：Mixed ---\n");
    {
        Mixed a(1);
        Mixed b = a;           // 浅拷贝 → 同样 double free
    }

    return 0;
}