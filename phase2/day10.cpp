#include <iostream>
#include <thread>
#include <string>
#include <queue>
#include <mutex>
#include <condition_variable>
using namespace std;

queue<int> q;
mutex mtx;
condition_variable cv;
bool finished=false;

void producer(){
    for(int i=0;i<1000;i++){
        {
            lock_guard<mutex> lock(mtx);
            q.push(i);
            cout << "生产: " << i << endl;
            //cv.notify_one();
        }
        cv.notify_one();
    }
    {
        lock_guard<mutex> lock(mtx);
        finished=true;
    }
    cv.notify_one();
}


void consumer(){
    int count=0;
    while(true){
        unique_lock<mutex> lock(mtx);

        cv.wait(lock,[] {return !q.empty() || finished;});

        if(finished && q.empty()){
            break;
        }
        int val=q.front();
        q.pop();
        cout << "消费: " << val << endl;
        count++;
    }
    cout << "消费者总共消费了: " << count << " 个数据" << endl;
}

int main(){
    thread t1(producer);
    thread t2(consumer);

    t1.join();
    t2.join();



    return 0;
}