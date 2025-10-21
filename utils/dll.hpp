#include <iostream>
#include <chrono>
#include <string>
using namespace std;

struct Dll{
    int data;
    Dll* prev;
    Dll* next;
};

class Linkedlist{
    private:
        Dll* head;
    public:
        Linkedlist(){
            head = nullptr;
        }

    void insertFront(int value){
        Dll* newDll = new Dll;
        newDll->data = value;
        newDll->next =  head;
        newDll->prev = nullptr;
        head = newDll;
    }

    void insertEnd(int value){
        Dll* newDll = new Dll;
        newDll->data = value;
        newDll->next = nullptr;
        
        if(head == nullptr){
            head = newDll;
            return;
        }
        Dll* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = newDll;
        newDll->prev = temp;
    }

    void rotation(int k){
        if(head == nullptr || k == 0){
            return;
        }

        Dll* tail = head;
        int len = 1;
        while(tail->next){
            tail = tail->next;
            len++;
        }

        k = k % len;
        if(k == 0){
            return;
        }

        Dll* newTail = head;
        for(int i=1; i < len - k; i++){
            newTail = newTail->next;
        }

        Dll* newHead = newTail->next;
        newTail->next = nullptr;
        newHead->prev = nullptr;
        tail->next = head;
        head->prev = tail;
        head = newHead;
    }
};

