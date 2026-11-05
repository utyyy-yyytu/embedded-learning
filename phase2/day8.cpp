#include <iostream>
#include <deque>
#include <chrono>
#include <thread>
#include <map>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

struct Data {
    int value;
    chrono::steady_clock::time_point timestamp;
};

class WindowDeque{
public:
    void add(int value){
        auto now = chrono::steady_clock::now();
        window.push_back({value,now});

        // Remove old data points that are outside the 10-second window
        
        while(!window.empty()&& (now - window.front().timestamp)>chrono::seconds(10)){
            window.pop_front();
        }
    }
    
    int sum() const{
        int total = 0;
        for(const auto& data : window){
            total += data.value;
        }
        return total;
    }

    size_t size() const {
        return window.size();
    }


private:
    deque<Data> window;
};

int main() {
    // WindowDeque wd;

    // for(int i=0;i<20;i++){
    //     wd.add(i);
    //     cout << "加入 " << i << "，当前窗口大小: " << wd.size()
    //          << "，总和: " << wd.sum() << endl;
    //      this_thread::sleep_for(chrono::seconds(1));
    // }
   
    // string text="apple banana apple cherry banana apple";
    // map<string,int> frep;
    // istringstream iss(text);
    // string word;
    // while(iss >> word){
    //     frep[word]++;
    // }

    // for(const auto& [k,v] : frep){
    //     cout << k << ": " << v << endl;
    // }


    //测试deque与vector的性能差异
    //auto start = chrono::high_resolution_clock::now();

    // 测试deque的性能
    // deque<int> dq;
    // for(int i=0;i<1000000;i++){
    //     dq.push_back(i);
    // }
    // for(int i=0;i<1000000;i++){
    //     dq.pop_front();
    // }
    // cout<<"deque测试开始："<<endl;
    // 测试vector的性能
    vector<int> vec;
    // for(int i=0;i<1000000;i++){
    //     vec.push_back(i);
    // }
    // for(int i=0;i<1000000;i++){
    //     vec.erase(vec.begin());
    // }
    // cout<<"vector测试开始："<<endl;

    // auto end = chrono::high_resolution_clock::now();
    // auto duration = chrono::duration_cast<chrono::milliseconds>(end-start);

    // cout<<"性能测试耗时: " << duration.count() << " 毫秒" << endl;


    map<string,int> frep;
    string text1 = "apple banana apple cherry banana apple";
    istringstream iss(text1);
    string word1;
    while(iss >> word1){
        frep[word1]++;
    }
    for(const auto& [k,v] : frep){
        cout << k << ": " << v << endl;
    }

    return 0;
}