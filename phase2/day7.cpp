#include <iostream>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

string formatline(const string& name,const string& subject, const int& age,const int& score){
    string line="[";
    line +=name;
    line +="] ";
    line +="[";
    line +=subject;
    line +="] ";
    line +=": ";
    line +=to_string(age);
    line +=" ";
    line +=": ";
    line +=to_string(score);

    return line;
}

class Logger{
public:
    string formatLog(const string& timemap,const string& level,const string& msg) const{
        string line="[";
        line +=timemap;
        line +="] ";
        line +="[";
        line +=level;
        line +="] ";
        line +=": ";
        line +=msg;
        return line;
    }
};


int main(){
    string name="student";
    string subject="Cpp";
    int age=20;
    int score=100;

    auto start = chrono::high_resolution_clock::now();

    vector<string> records;
    records.reserve(1000);
    for(int i=0;i<1000;i++){
        string line=formatline(name + to_string(i), subject, age+i%40, score+i%60);
        records.push_back(line);
    }
    
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end-start);

    cout<<"容器大小： "<<records.size()<<endl;
    cout<<"第一条记录："<<records[0]<<endl;
    cout<<"最后一条记录： "<<records.back()<<endl;
    cout<<"耗时： "<<duration.count()<<" ms(微秒)"<<endl;


    Logger logger;
    auto start2 = chrono::high_resolution_clock::now();
    vector<string> logs;
    logs.reserve(100000);
    for(int i=0;i<100000;i++){
        string line=logger.formatLog("2023-06-01 12:00:00", "INFO", "This is log message number " + to_string(i));
        logs.push_back(line);
    }

    auto end2 = chrono::high_resolution_clock::now();
    auto duration2 = chrono::duration_cast<chrono::microseconds>(end2-start2);

    cout<<"日志容器大小： "<<logs.size()<<endl;
    cout<<"第一条日志："<<logs[0]<<endl;
    cout<<"最后一条日志： "<<logs.back()<<endl;
    cout<<"耗时： "<<duration2.count()<<" ms(微秒)"<<endl;


    return 0;
}