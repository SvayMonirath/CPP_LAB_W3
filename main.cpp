#include <iostream>
#include "utils/sll.hpp"
#include "utils/csll.hpp"
#include "utils/dll.hpp"
#include "utils/helper.hpp"
#include <chrono>
#include <vector>

using namespace std;
using namespace std::chrono;


int main(void) {

    // Q. A1
    cout << "Part A\n\n";
    cout << "----- Q.A1 -----\n\n";

    // (i.)
    cout << "CSLL: ";
    CSLL csll_list1;
    csll_list1.fill(5);
    double duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list1.traverse_back_to_head();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // (ii.)
    cout << "\nSLL: ";
    singleLinkedList list1 = create_sample_list();
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list1.traverse_and_back_head();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // Q. A2
    cout << "----- Q.A2 -----\n\n";
    cout << "CSLL: ";
    CSLL csll_list2;
    csll_list2.fill(5);
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list2.deleteNode(3);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
        csll_list2.pushBack(3);
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nCSLL: ";
    CSLL csll_list3;
    csll_list3.fill(5);
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list3.deleteNodeWithoutPrev(4);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
        csll_list3.pushBack(4);
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // Q. A3
    cout << "----- Q.A3 -----\n\n";
    singleLinkedList list2 = create_sample_list();
    singleLinkedList list3 = create_sample_list();
    singleLinkedList list4 = create_sample_list();

    int list3_length = list3.get_length(), list4_length = list4.get_length();

    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list2.rotate_right_n(1);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list3.rotate_right_n(list3_length/2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list4.rotate_right_n(list4_length+3);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    CSLL csll_list4, csll_list5, csll_list6;
    csll_list4.fill(5);
    csll_list5.fill(5);
    csll_list6.fill(5);

    cout << "\nCSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list4.rotate(1);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nCSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list5.rotate(csll_list5.size()/2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nCSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list6.rotate(csll_list6.size()+3);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // Q. A4

    cout << "----- Q.A4 -----\n\n";

    cout << "DLL: ";
    DoublyLinkedList dll_list1;
    for(int i=1; i<=5; i++) {
        dll_list1.insertEnd(i);
    }
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        dll_list1.delete_at_position(2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    singleLinkedList list5 = create_sample_list();

    cout << "\nSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list5.insert_at_position(10, 2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "\nDLL: ";


    //Q. A5

    cout << "----- Q.A5 -----\n\n";
    //(i) insert front and remove front
    // no tail
    singleLinkedList list6 = create_sample_list();
    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list6.insert_at_beginning(10);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // with tail
    singleLinkedList_with_tail list7;
    for(int i=0; i<5; i++) list7.add_node(i);
    cout << "\nSLL with tail: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list7.insert_at_beginning(10);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    //(ii) insert back and remove back

    // no tail
    cout << "\nSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list6.insert_at_end(20);
        list6.delete_at_end();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // with tail
    for(int i=0; i<5; i++) list7.add_node(i);

    cout << "\nSLL with tail: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list7.insert_at_end(20);
        list7.delete_at_end();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // DLL
    DoublyLinkedList dll_list;
    for(int i=1; i<=5; i++) {
        dll_list.insertEnd(i);
    }

    cout << "\nDLL with tail: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        dll_list.insertFront(40);
        dll_list.deleteFront();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "DLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        dll_list.insertEnd(50);
        dll_list.deleteEnd();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(stop - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // Q. A6
    cout << "----- Q.A6 -----\n\n";
    int n = 1000;
    singleLinkedList large_sll;
    duration_sum = 0.0;
    auto start_mem = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        large_sll.insert_at_end(i);
    }
    auto stop_mem = high_resolution_clock::now();
    duration_sum += duration_cast<nanoseconds>(stop_mem - start_mem).count();
    cout << "\nSLL: ";
    cout << "MEMORY USAGE: " << n * sizeof(Node) << " bytes\n";
    cout << "Time to create list: " << duration_sum << " nanoseconds\n";

    cout << "\nDLL: ";
    cout << "MEMORY USAGE: " << n * sizeof(Dll) << " bytes\n";
    duration_sum = 0.0;
    start_mem = high_resolution_clock::now();
    DoublyLinkedList large_dll;
    for (int i = 0; i < n; i++) {
        large_dll.insertEnd(i);
    }
    stop_mem = high_resolution_clock::now();
    duration_sum += duration_cast<nanoseconds>(stop_mem - start_mem).count();
    cout << "Time to create list: " << duration_sum << " nanoseconds\n";

    CSLL large_csll;
    duration_sum = 0.0;
    start_mem = high_resolution_clock::now();
    for (int i = 0; i < n; i++) {
        large_csll.pushBack(i);
    }
    stop_mem = high_resolution_clock::now();
    duration_sum += duration_cast<nanoseconds>(stop_mem - start_mem).count();
    cout << "\nCSLL: ";
    cout << "MEMORY USAGE: " << n * sizeof(Node) << " bytes\n";
    cout << "Time to create list: " << duration_sum << " nanoseconds\n";

    cout << "\nPart B\n\n";
    cout << "----- Q.B1 -----\n\n";


    cout << "Recent items tray\n";

    singleLinkedList Tray1 = create_sample_list();
    DoublyLinkedList Tray2;

    for(int i=0; i<5; i++) Tray2.insertFront(i);

    // implement a mixed work load of adding and removing at front
    duration_sum = 0.0;
    cout << "SLL: ";
    for(int i=0; i<5; i++) {

        auto start = high_resolution_clock::now();
        for(int i=0; i<3; i++) Tray1.insert_at_beginning(i);
        for(int i=0; i< 4; i++) Tray1.delete_at_beginning();
        auto end = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(end - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    duration_sum = 0.0;
    cout << "\nDLL: ";
    for(int i=0; i<5; i++) {

        auto start = high_resolution_clock::now();
        for(int i=0; i<3; i++) Tray2.insertFront(i);
        for(int i=0; i< 4; i++) Tray2.deleteFront();
        auto end = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(end - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "----- Q.B2 -----\n\n";

    duration_sum = 0.0;
    cout << "SLL: ";
    for(int i=0; i<5; i++) {

        auto start = high_resolution_clock::now();
        for(int i=0; i<3; i++) Tray1.insert_at_beginning(i);
        for(int i=0; i< 4; i++) Tray1.delete_at_beginning();
        auto end = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(end - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";


    // implement vector stack
    vector<int> Tray3;
    for(int i=0; i<5; i++) Tray3.push_back(i);
    duration_sum = 0.0;
    cout << "\nVector: ";
    for(int i=0; i<5; i++) {
        auto start = high_resolution_clock::now();
        for(int i=0; i<3; i++) Tray3.push_back(i);
        for(int i=0; i< 4; i++) Tray3.pop_back();
        auto end = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(end - start).count();
        cout << "test " << i << ": " << duration_cast<nanoseconds>(end - start).count() << " nanoseconds\n";
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    return 0; // code success
}
