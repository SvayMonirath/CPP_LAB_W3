#ifndef DLL_HPP
#define DLL_HPP

#include <iostream>
#include <chrono>
#include <string>
using namespace std;

struct Dll{
    int data;
    Dll* prev;
    Dll* next;
};

class DoublyLinkedList{
    private:
    Dll* head;
    public:
    DoublyLinkedList(){
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
    void deleteFront(){
        if(head == nullptr){
            return;
        }
        Dll* temp = head;
        head = head->next;
        if(head != nullptr){
            head->prev = nullptr;
        }
        delete temp;
    }
    void deleteEnd(){
        if(head == nullptr){
            return;
        }
        Dll* temp = head;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        if(temp->prev != nullptr){
            temp->prev->next = nullptr;
        } else {
            head = nullptr;
        }
        delete temp;
    }
    void delete_at_position(int position){
        if(head == nullptr || position < 0){
            return;
        }
        Dll* temp = head;
        for(int i=0; temp != nullptr && i < position; i++){
            temp = temp->next;
        }
        if(temp == nullptr){
            return;
        }
        if(temp->prev != nullptr){
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if(temp->next != nullptr){
            temp->next->prev = temp->prev;
        }
        delete temp;
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

#endif // DLL_HPP
