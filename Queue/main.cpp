//
//  main.cpp
//  Queue
//
//  Created by Joseph Runser on 10/11/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#include <iostream>

#include "Queue.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    
    Queue queue = Queue();
    
    int count = 1;
    
    while(!queue.isFull()) {
        cout << "isEmtpy: " << queue.isEmpty() << endl;
        cout << "isFull: " << queue.isFull() << endl;
        
        queue.enqueue(count);
        count++;
    }
    
    queue.display();
}
