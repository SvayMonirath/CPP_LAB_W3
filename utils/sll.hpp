#ifndef SLL_HPP
#define SLL_HPP

#include <iostream>
#include "node.hpp"

class singleLinkedList {
private:
    Node* head;
public:
    singleLinkedList() : head(nullptr) {}

    void add_node(int val) {
        if (!head) {
            head = new Node{val, nullptr};
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node{val, nullptr};
    }

    //INSERTION METHODS

    void insert_at_beginning(int val) {
        Node* new_node = new Node{val, head};
        head = new_node;
    }

    void insert_at_end(int val) {
        if (!head) {
            head = new Node{val, nullptr};
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node{val, nullptr};
    }

    void insert_at_position(int val, int position) {
        if (position == 0) {
            insert_at_beginning(val);
            return;
        }
        Node* curr = head;
        for (int i = 0; i < position - 1 && curr; ++i) {
            curr = curr->next;
        }
        if (curr) {
            Node* new_node = new Node{val, curr->next};
            curr->next = new_node;
        }
    }

    void delete_at_beginning() {
        if(head == nullptr) return;

        Node* tmp = head;
        head = head->next;
        delete tmp;
    }

    void delete_at_position(int position) {
        if(head == nullptr) return;

        if(position == 0) {
            delete_at_beginning();
            return;
        }

        Node* curr = head;
        for(int i = 0; i < position - 1 && curr->next != nullptr; ++i) {
            curr = curr->next;
        }

        if(curr->next != nullptr) {
            Node* tmp = curr->next;
            curr->next = curr->next->next;
            delete tmp;
        }
    }

    void delete_at_end() {
        if(head == nullptr) return;

        Node* curr = head;
        while(curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node* tmp = curr->next;
        delete tmp;

        curr->next = nullptr;
    }

    void rotate_right_n(int n) {
        if (!head || !head->next || n <= 0) return;

        Node* curr = head;
        int length = 1;

        // get size of linked list
        while (curr->next) {
            curr = curr->next;
            length++;
        }
        curr->next = head;

        n = n % length;
        for (int i = 0; i < length - n; i++) {
            curr = curr->next;
        }
        head = curr->next;
        curr->next = nullptr;
    }

    void traverse_and_back_head() {
        if(!head) return;

        Node* curr = head;
        while(curr) {
            curr = curr->next;
        }

        curr = head;
    }

    int get_length() {
        if(!head) return 0;

        Node* curr = head;
        int length = 1;
        while(curr->next) {
            curr = curr->next;
            length++;
        }

        return length;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr" << std::endl;
    }

};

class singleLinkedList_with_tail {
private:
    Node* head;
    Node* tail;

public:
    singleLinkedList_with_tail() : head(nullptr), tail(nullptr) {}

    void add_node(int val) {
        Node* new_node = new Node{val, nullptr};

        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void insert_at_beginning(int val) {
        Node* new_node = new Node{val, head};
        head = new_node;
        if (!tail) tail = new_node; // if list was empty
    }

    void insert_at_end(int val) {
        Node* new_node = new Node{val, nullptr};

        if (!head) {
            head = tail = new_node;
        } else {
            tail->next = new_node;
            tail = new_node;
        }
    }

    void insert_at_position(int val, int position) {
        if (position <= 0) {
            insert_at_beginning(val);
            return;
        }

        Node* curr = head;
        for (int i = 0; i < position - 1 && curr; ++i) {
            curr = curr->next;
        }

        if (!curr) {
            insert_at_end(val);
            return;
        }

        Node* new_node = new Node{val, curr->next};
        curr->next = new_node;

        if (curr == tail) {
            tail = new_node;
        }
    }

    void delete_at_beginning() {
        if (!head) return;

        Node* tmp = head;
        head = head->next;
        delete tmp;

        if (!head) tail = nullptr; // if list becomes empty
    }

    void delete_at_position(int position) {
        if (!head) return;

        if (position == 0) {
            delete_at_beginning();
            return;
        }

        Node* curr = head;
        for (int i = 0; i < position - 1 && curr->next; ++i) {
            curr = curr->next;
        }

        if (curr->next) {
            Node* tmp = curr->next;
            curr->next = curr->next->next;
            if (tmp == tail) tail = curr; // update tail if last node deleted
            delete tmp;
        }
    }

    void delete_at_end() {
        if (!head) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* curr = head;
        while (curr->next != tail) {
            curr = curr->next;
        }

        delete tail;
        tail = curr;
        tail->next = nullptr;
    }

    void rotate_right_n(int n) {
        if (!head || !head->next || n <= 0) return;

        // Find length and tail
        Node* curr = head;
        int length = 1;
        while (curr->next) {
            curr = curr->next;
            length++;
        }
        curr->next = head;  // make it circular

        n = n % length;
        for (int i = 0; i < length - n; i++) {
            curr = curr->next;
        }

        head = curr->next;
        curr->next = nullptr;
        tail = curr;
    }

    int get_length() {
        int length = 0;
        Node* curr = head;
        while (curr) {
            curr = curr->next;
            length++;
        }
        return length;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            std::cout << curr->data << " -> ";
            curr = curr->next;
        }
        std::cout << "nullptr" << std::endl;
    }
};

#endif
