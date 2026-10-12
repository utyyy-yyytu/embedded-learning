#include <iostream>
#include <string>
using namespace std;

class Counter{
public:
    Counter() : count(0) {
        cout<<"默认构造"<<endl;
    }

    explicit Counter(int a) : count(a){
        cout<<"有参构造： "<<a<<endl;
    }

    ~Counter(){
        cout<<"析构函数: "<<count<<endl;
    }


private:
    int count;
};


class Student{
public:
    Student() : name(""),age(0),score(0) {}

    Student(string n, int a, int s) : name(n),age(a),score(s) {}

    ~Student() {
        cout<<"析构函数: "<<name<<"被销毁"<<endl;
    }

    void stuprintf(const Student& s) {
        cout<<"姓名: "<<s.name<<endl;
        cout<<"年龄: "<<s.age<<endl;
        cout<<"成绩: "<<s.score<<endl;
    }


private:
    string name;
    int age;
    int score;
};


int main(){
    // Counter v1;
    // Counter v2(10);
    // Counter* v3= new Counter(30);
    // delete v3;


    Student s1;
    Student s2("张三",20,100);
    Student* s3 = new Student("李四",21,90);
    s1.stuprintf(s1);
    s2.stuprintf(s2);
    s3->stuprintf(*s3);
    delete s3;
    
    return 0;
}