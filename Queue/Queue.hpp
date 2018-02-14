//
//  Queue.hpp
//  Queue
//
//  Created by Joseph Runser on 10/11/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <iostream>

/* Implimentation:
public:
     Queue();
     void enqueue(int x);
     int dequeue();
     bool isFull();
     bool isEmpty();
     void clear();
     void display();

 private:
     int front;
     int rear;
     int arr[CAPACITY];
*/

class Queue {
    
public:
    Queue();
    Queue(int size);
    void enqueue(int x);
    int dequeue();
    bool isFull();
    bool isEmpty();
    void clear();
    void display();
 
private:
    static const int MAX_SIZE = 500000; //__INT_MAX__;
    int size;
    int front;
    int rear;
    int arr[MAX_SIZE];
    
};

#endif /* Queue_hpp */
