#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
struct LinkedList {
    Node* head;
    LinkedList() : head(nullptr) {}

    void add_node(int val) {
        if (!head) {
            head = new Node(val);
            return;
        }
        Node* curr = head;
        while (curr->next) {
            curr = curr->next;
        }
        curr->next = new Node(val);
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


