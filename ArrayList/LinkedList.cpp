//
//  ArrayList.cpp
//  ArrayList
//
//  Created by Joseph Runser on 10/30/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#include "LinkedList.hpp"

// Initialize head and tail pointers to NULL
LinkedList::LinkedList(){
    head = NULL;
    tail = NULL;
    size = 0;
}

// To add a node at the beginning, we have two cases:
//     1. Empty list
//     2. Non-empty list
// If the list is empty we need to update both pointers head and tail.
void LinkedList::insertAtBeginning(const int addID, const string addData) {
    node* newNode = new node;
    newNode->id = addID;
    newNode->data = addData;
    newNode->next = NULL;
    
    if(head == NULL){
        head = newNode;
        tail = newNode;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

void LinkedList::deleteFromBeginning(){
    if(head == NULL)
        cout<<"Empty list"<<endl;
    else {
        node* delPtr = head;
        head = head->next;
        delete delPtr;
        size--;
    }
}

// To delete a node at random location, we need two pointers:
//     - mark the node to be deleted
//     - mark the node before
// the node to be deleted. The two pointers will point to two consecutive nodes.
void LinkedList::deleteKey(const string delData){
    node* temp;
    node* curr;
    curr = head;
    temp = head;
    
    while(curr != NULL && curr->data != delData){
        temp = curr;
        curr = curr->next;
    }
    
    if(curr == NULL)
        cout<<"Key is not in the list"<<endl;
    else {
        temp->next = curr->next;
        if(curr == head) // first node to be deleted => update head
            head = head->next;
        delete curr; // to free to memory used by the deleted node
        size--;
    }
}

// Get the number of elements in the list
int LinkedList::getSize() {
    return size;
}

// Create a temporary pointer and traverse the entire list
// do not use head pointer.
void LinkedList::displayList() {
    node* curr = head;
    cout << "Start:" << endl;
    while( curr != NULL){
        cout << "Item " << curr->id << ": " << curr->data << endl;
        curr = curr->next;
    }
    cout << "End" << endl;
}

void LinkedList::bSortList() {
    if(size > 1) {
        node* iNode = head;
        node* jNode;
        
        while(iNode != NULL) {
            jNode = head;
            while (jNode->next != NULL) {
                if(jNode->next->id < jNode->id) {
                    swap(jNode, jNode->next);
                }
                jNode = jNode->next;
            }
            iNode = iNode->next;
        }
    }
}

void LinkedList::swap(LinkedList::node* current, LinkedList::node* next) {
    int tmpId = current->id;
    string tmpData = current->data;
    
    current->id = next->id;
    current->data = next->data;
    
    next->id = tmpId;
    next->data = tmpData;
}
