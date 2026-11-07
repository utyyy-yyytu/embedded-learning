#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <vector>
using namespace std;

int count = 0;
mutex mtx;

atomic<int> atomic_count{0};
atomic<bool> flag{true};

void thread_printf(int id){
    int thread_count=0;
    while(flag.load()){
        {
            lock_guard<mutex> lock(mtx);
            cout <<"线程"<<id<<"打印第"<<++thread_count<< "次" << endl;
        }
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    {
        lock_guard<mutex> lock(mtx);
        cout << "线程 " << id << " 收到停止信号，退出。共打印 " << thread_count << " 次" << endl;
    }
}

void add(){
    for(int i=0;i<100000;i++){
        lock_guard<mutex> lock(mtx);
        atomic_count++;
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

    thread t(woker);

    t.join();

    thread t1(add);

    t1.join();
    thread t2(add);
    t2.join();

    t1.join();
    t2.join();

    cout << "最终计数值: " << atomic_count << endl;

    cout << "主线程结束" << endl;

    vector<thread> threads;

    for(int i=1;i<=4;i++){
        threads.emplace_back(thread_printf,i);
    }

    this_thread::sleep_for(chrono::seconds(1));
    cout << "\n=== 主线程发出停止信号 ===\n" << endl;
    flag.store(false);

    for(auto& t : threads){
        t.join();
    }

    cout << "\n所有线程已退出，主线程结束。" << endl;

    return 0;
}