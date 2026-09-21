#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student{
    string name;
    int age;
    double gpa;

    Student() : name(""),age(0),gpa(0.0) {}

    Student(string n,int a,double g) : name(n),age(a),gpa(g) {}
};

void printStudent(const Student& s){
    cout<< "Name: " << s.name << ", Age: " << s.age << ", GPA: " << s.gpa << endl;
}

void printS(const vector<Student>& students){
    if(students.empty()){
        cout << "No students to display." << endl;
        return;
    }

    for(const auto&s : students){
        printStudent(s);
    }
}

void sortByGPA(vector<Student>& students){
    sort(students.begin(),students.end(),[](const Student& a,const Student& b){
        return a.gpa>b.gpa;
    });
}

int main() {
    vector<Student> students;
    students.emplace_back("Alice", 20, 3.5);
    students.emplace_back("Bob", 22, 3.8);
    students.emplace_back("Charlie", 19, 3.2);
    students.emplace_back("David", 21, 3.9);
    
    cout << "Students before sorting by GPA:" << endl;
    printS(students);

    sortByGPA(students);
    cout << "\nStudents after sorting by GPA:" << endl;
    printS(students);



    return 0;
}