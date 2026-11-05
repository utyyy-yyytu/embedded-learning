#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int count = 0;
mutex mtx;

void add(){
    for(int i=0;i<100000;i++){
        lock_guard<mutex> lock(mtx);
        count++;
    }
}

void woker(){
    for(int i=0;i<5;i++){
        cout << "工作线程输出: " << i << endl;
        this_thread::sleep_for(chrono::milliseconds(10));
    }
}

int main(){
    cout<< "主线程开始" << endl;

    //thread t(woker);

    //t.join();

    thread t1(add);

    //t1.join();
    thread t2(add);
    //t2.join();

    t1.join();
    t2.join();

    cout << "最终计数值: " << count << endl;

    cout << "主线程结束" << endl;


    return 0;
}