#include <fcntl.h>
#include <unistd.h>
#include <iostream>
#include <cstring>
using namespace std;

class File{
public:
    explicit File(const char* path){
        fd = open(path,O_WRONLY | O_CREAT | O_APPEND, 0644);
        if(fd<0){
            throw runtime_error("文件打开失败");
        }
        cout<<"构造：文件打开成功,fd= "<<fd<<endl;
    }

    ~File(){
        if(fd>=0){
            close(fd);
            cout<<"析构：文件关闭成功"<<endl; 
        }
    }

    int getFD() const{
        return fd;
    }

    //禁拷贝
    File(const File&)=delete;
    File& operator=(const File&)=delete;
    

private:
    int fd;
};

int main(){
    File f("test.txt");
    ssize_t n= write(f.getFD(), "Hello, RAII!\n", strlen("Hello, RAII!\n"));
    if(n<0){
        cerr<<"文件写入失败"<<endl;
        return 1;
    }

    cout<<"main 即将结束"<<endl;
    return 0;
}