#include <iostream>
#include <vector>
using namespace std;

struct Nodelist{
    int val;
    Nodelist* next;

    Nodelist() : val(0),next(nullptr) {}

    Nodelist(int v) : val(v),next(nullptr) {}

    Nodelist(int v,Nodelist* n) : val(v),next(n) {}
};


Nodelist* createlist(const vector<int>& nums){
    Nodelist* head=nullptr;
    Nodelist* tail=nullptr;
    for(int num : nums){
        Nodelist* node=new Nodelist(num);
        if(head==nullptr){
            head=node;
            tail=node;
        }
        else{
            tail->next=node;
            tail=node;
        }
    }
    return head;
}

Nodelist* hcreatelist(const vector<int>& nums){
    Nodelist* head=nullptr;
    for(int num : nums){
        Nodelist* node=new Nodelist(num);
        node->next=head;
        head=node;
    }
    return head;
}

void printlist(Nodelist* head){
    Nodelist* cur=head;
    while(cur!=nullptr){
        cout<<cur->val<<" ";
        if(cur->next!=nullptr){
            cout<<"->";
        }
        cur=cur->next;
    }
    cout<<endl;
}

void deletelist(Nodelist* head){
    while(head!=nullptr){
        Nodelist* temp=head;
        head=head->next;
        delete temp;
    }
}

int length(Nodelist* head){
    int len=0;
    Nodelist* cur=head;
    while(cur!=nullptr){
        len++;
        cur=cur->next;
    }
    return len;
}

int sum(Nodelist* head){
    int total=0;
    Nodelist* cur=head;
    while(cur!=nullptr){
        total+=cur->val;
        cur=cur->next;
    }
    return total;
}

bool contains(Nodelist* head,int num){
    Nodelist* cur=head;
    while(cur!=nullptr){
        if(cur->val==num){
            return true;
        }
        cur=cur->next;
    }
    return false;
}

Nodelist* reverseList(Nodelist* head){
    Nodelist* pre=nullptr;
    Nodelist* cur=head;
    while(cur!=nullptr){
        Nodelist* next=cur->next;
        cur->next=pre;
        pre=cur;
        cur=next;
    }
    return pre;
}

int main() {
    Nodelist* head = createlist({1, 2, 3, 4, 5});
    printlist(head);        // 1 -> 2 -> 3 -> 4 -> 5

    deletelist(head);
    head = nullptr;

    return 0;
}