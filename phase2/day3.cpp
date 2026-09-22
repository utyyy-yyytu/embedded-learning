#include <iostream>
#include<vector>
using namespace std;

struct Listnode{
    int val;
    Listnode* next;

    Listnode() : val(0),next(nullptr) {}

    Listnode(int v) : val(v),next(nullptr) {}

    Listnode(int v,Listnode* n) : val(v),next(n) {} 
};

Listnode* inserthead(Listnode* head,int val){
    Listnode* cur=new Listnode(val);
    cur->next=head;
    return cur;
}

Listnode* inserttail(Listnode* head,int val){
    Listnode* cur=new Listnode(val);
    if(head==nullptr){
        return cur;
    }
    else{
        Listnode* temp=head;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=cur;
        return head;
    }
}

Listnode* insertNat(Listnode* head,int val,int n){
    Listnode* cur=new Listnode(val);
    Listnode dummy(0);
    dummy.next=head;
    Listnode* temp=&dummy;

    for(int i=0;i<n&&temp!=nullptr;i++){
        temp=temp->next;
    }
    if(temp==nullptr){
        delete cur;
        return dummy.next;
    }
    cur->next=temp->next;
    temp->next=cur;
    return dummy.next;
}


Listnode* deletehead(Listnode* head){
    if(head==nullptr){
        return nullptr;
    }
    Listnode* newhead = head->next;
    delete head;
    return newhead;
}

Listnode* deletetail(Listnode* head){
    if(head==nullptr){
        return 0;
    }
    if(head->next==nullptr){
        delete head;
        return nullptr;
    }
    Listnode* cur=head;
    while(cur->next->next!=nullptr){
        cur=cur->next;
    }
    Listnode* temp =cur->next;
    cur->next=nullptr;
    delete temp;
    return head;
}

Listnode* deleteValue(Listnode* head,int val){
    Listnode dummy(0);
    dummy.next=head;
    Listnode* cur=&dummy;

    while(cur->next!=nullptr){
        if(cur->next->val==val){
            Listnode* temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
            return dummy.next;
        }
        cur=cur->next;
    }
    return dummy.next;
}

Listnode* deleteAll(Listnode* head,int val){
    Listnode dummy(0);
    dummy.next=head;
    Listnode* cur=&dummy;

    while(cur->next!=nullptr){
        if(cur->next->val==val){
            Listnode* temp=cur->next;
            cur->next=cur->next->next;
            delete temp;
        }
        else{
            cur=cur->next;
        }
    }
    return dummy.next;
}

Listnode* deleteDuplicates(Listnode* head) {
    if (head == nullptr) return nullptr;

    Listnode* cur = head;
    while (cur->next != nullptr) {
        if (cur->val == cur->next->val) {
            Listnode* temp = cur->next;
            cur->next = cur->next->next;
            delete temp;
        } else {
            cur = cur->next;
        }
    }
    return head;
}