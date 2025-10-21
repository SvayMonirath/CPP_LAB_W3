#ifndef HELPER_HPP
#define HELPER_HPP

#include <iostream>
#include "node.hpp"
#include "sll.hpp"

using namespace std;

// make 5 node linked list
singleLinkedList create_sample_list() {
    singleLinkedList list;
    for (int i = 1; i <= 5; ++i) {
        list.add_node(i);
    }
    return list;
}


#endif
