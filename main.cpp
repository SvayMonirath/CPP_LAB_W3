#include <iostream>
#include "utils/sll.hpp"
#include "utils/csll.hpp"
#include "utils/helper.hpp"
#include <chrono>

using namespace std;
using namespace std::chrono;

int main(void) {

    // Q. A1
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
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // (ii.)
    cout << "SLL: ";
    singleLinkedList list1 = create_sample_list();
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list1.traverse_and_back_head();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
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
        csll_list2.pushBack(3);
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "CSLL: ";
    CSLL csll_list3;
    csll_list3.fill(5);
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list3.deleteNodeWithoutPrev(4);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
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
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list3.rotate_right_n(list3_length/2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list4.rotate_right_n(list4_length+3);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    CSLL csll_list4, csll_list5, csll_list6;
    csll_list4.fill(5);
    csll_list5.fill(5);
    csll_list6.fill(5);

    cout << "CSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list4.rotate(1);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "CSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list5.rotate(csll_list5.size()/2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    cout << "CSLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        csll_list6.rotate(csll_list6.size()+3);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // Q. A4

    cout << "----- Q.A4 -----\n\n";
    singleLinkedList list5 = create_sample_list();

    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list5.insert_at_position(10, 2);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

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
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // with tail
    singleLinkedList_with_tail list7;
    for(int i=0; i<5; i++) list7.add_node(i);
    cout << "SLL with tail: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list7.insert_at_beginning(10);
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    //(ii) insert back and remove back

    // no tail
    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list6.insert_at_end(20);
        list6.delete_at_end();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    // with tail
    for(int i=0; i<5; i++) list7.add_node(i);

    cout << "SLL: ";
    duration_sum = 0.0;
    for (int i = 1; i <= 5; i++) {
        auto start = high_resolution_clock::now();
        list7.insert_at_end(20);
        list7.delete_at_end();
        auto stop = high_resolution_clock::now();
        duration_sum += duration_cast<nanoseconds>(stop - start).count();
    }
    cout << "Average duration: " << duration_sum / 5 << " nanoseconds\n";

    return 0;
}
