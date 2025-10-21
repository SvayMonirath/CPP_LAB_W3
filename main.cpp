#include <iostream>
#include "utils/sll.hpp"
#include "utils/helper.hpp"


// TODO[]: implement timing system

int main(void) {

    // Q. A1

    // (ii.)
    singleLinkedList list1 = create_sample_list();
    list1.traverse_and_back_head();


    // Q. A2

    // Q. A3

    singleLinkedList list2 = create_sample_list();
    singleLinkedList list3 = create_sample_list();
    singleLinkedList list4 = create_sample_list();

    int list3_length = list3.get_length(), list4_length = list4.get_length();

    list2.rotate_right_n(1);
    list3.rotate_right_n(list3_length/2);
    list4.rotate_right_n(list4_length+3);


    // Q. A4

    singleLinkedList list5 = create_sample_list();
    list5.delete_at_position(2);

    //Q. A5

    //(i) insert front and remove front
    // no tail
    singleLinkedList list6 = create_sample_list();
    list6.insert_at_beginning(10);
    list6.delete_at_beginning();

    // with tail
    singleLinkedList_with_tail list7;
    list7.insert_at_beginning(10);
    list7.delete_at_beginning();

    //(ii) insert back and remove back

    // no tail
    list6.insert_at_end(20);
    list6.delete_at_end();

    // with tail
    for(int i=0; i<5; i++) list7.add_node(i);

    list7.insert_at_end(20);
    list7.delete_at_end();

    return 0;
}
