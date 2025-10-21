#ifndef UTILS_CSLL_HPP
#define UTILS_CSLL_HPP

#include <iostream>
#include "node.hpp"
using namespace std;

class CSLL {
private:
    Node* tail;
    int n;

public:
    CSLL() : tail(nullptr), n(0) {}

    void fill(int count) {
        for (int i = 1; i <= count; i++) {
            pushBack(i);
        }
    }

    void setAtIndex(int index, int data) {
        if (!tail || index < 0 || index >= n) {
            cout << "Invalid index.\n";
            return;
        }

        Node* cur = tail->next;
        for (int i = 0; i < index; i++) {
            cur = cur->next;
        }
        cur->data = data;
    }

    void print() const {
        if (!tail) {
            cout << "List is empty.\n";
            return;
        }

        Node* cur = tail->next;
        do {
            cout << cur->data << " ";
            cur = cur->next;
        } while (cur != tail->next);
        cout << endl;
    }

    void pushBack(int data) {
        Node* new_node = new Node{data};
        if (!tail) {
            tail = new_node;
            tail->next = tail;
        } else {
            new_node->next = tail->next;
            tail->next = new_node;
            tail = new_node;
        }
        n++;
    }

    void pushFront(int data) {
        Node* new_node = new Node{data};
        if (!tail) {
            tail = new_node;
            tail->next = tail;
        } else {
            new_node->next = tail->next;
            tail->next = new_node;
        }
        n++;
    }

    void popFront() {
        if (!tail) return;

        Node* head = tail->next;
        if (head == tail) {
            delete head;
            tail = nullptr;
        } else {
            tail->next = head->next;
            delete head;
        }
        n--;
    }

    void rotate(int k) {
        if (!tail || k <= 0) return;
        k = k % n;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
        }
    }

    void deleteNode(int data) {
        if (!tail) return;

        Node* cur = tail->next;
        Node* prev = tail;

        if (tail == tail->next && tail->data == data) {
            delete tail;
            tail = nullptr;
            n--;
            return;
        }

        do {
            if (cur->data == data) {
                prev->next = cur->next;
                if (cur == tail) tail = prev;
                delete cur;
                n--;
                return;
            }
            prev = cur;
            cur = cur->next;
        } while (cur != tail->next);
    }

    void deleteNodeWithoutPrev(int data) {
        if (!tail) return;

        Node* cur = tail->next;

        do {
            if (cur->data == data) {
                if (cur == tail && cur == tail->next) {
                    delete cur;
                    tail = nullptr;
                } else {
                    Node* temp = cur->next;
                    cur->data = temp->data;
                    cur->next = temp->next;
                    if (temp == tail) tail = cur;
                    delete temp;
                }
                n--;
                return;
            }
            cur = cur->next;
        } while (cur != tail->next);
    }

    void traverse(int steps) const {
        if (!tail || steps <= 0) return;

        Node* cur = tail->next;
        for (int i = 0; i < steps; i++) {
            cout << cur->data << " ";
            cur = cur->next;
        }
    }

    void traverse_back_to_head() const {
        if (!tail) return;

        Node* cur = tail->next;
        do {
            cur = cur->next;
        } while (cur != tail->next);
    }


    int size() const { return n; }

};

#endif // UTILS_CSLL_HPP
