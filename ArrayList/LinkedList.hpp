//
//  ArrayList.hpp
//  ArrayList
//
//  Created by Joseph Runser on 10/30/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <iostream>
#include <string>

using namespace std;

class LinkedList{
private:
    struct node{
        int id;
        string data;
        node* next;
    };
    node* head;
    node* tail;
    int size;
    
    void swap(node* current, node* next);
    
public:
    LinkedList();
    void insertAtBeginning(const int addID, const string addData);
    void deleteFromBeginning();
    void deleteKey(const string delData);
    int getSize();
    void displayList();
    void bSortList();
};

#endif /* LinkedList_hpp */
