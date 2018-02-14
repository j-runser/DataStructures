//
//  Queue.cpp
//  Queue
//
//  Created by Joseph Runser on 10/11/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#include "Queue.hpp"

Queue::Queue() {
    front = 0;
    rear = 0;
    size = MAX_SIZE;
}

Queue::Queue(int size) {
    front = 0;
    rear = 0;
    this->size = size;
}

void Queue::enqueue(int x) {
    if(isFull()) { return; }
    
    arr[rear] = x;
    
    if(rear % size == 0) { rear = 0; }
    rear++;
}

int Queue::dequeue() {
    if(isEmpty()) { return __INT_MAX__; }
    
    int retVal = arr[front];
    front++;
    
    return retVal;
}

bool Queue::isFull() {
    if((size - front % size) == (size - rear + 1 % size)) { return true; }
    return false;
}

bool Queue::isEmpty() {
    if(rear + 1 % size == front % size) { return true; }
    return false;
}

void Queue::clear() {
    front = 0;
    rear = 0;
}

void Queue::display() {
    int i = front - 1;
    while(i != rear) {
        if(i == -1) { i = MAX_SIZE; }
        std::cout << i << std::endl;
    }
}
