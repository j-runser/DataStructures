//
//  main.cpp
//  ArrayList
//
//  Created by Joseph Runser on 10/30/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#include <iostream>
#include "LinkedList.hpp"

int main(){
    
    LinkedList myList;
    int inputID;
    string inputName;
    int choice;
    
    // populate for testing
    myList.insertAtBeginning(3, "Maggie");
    myList.insertAtBeginning(24, "Joe");
    myList.insertAtBeginning(25, "Alicia");
    myList.insertAtBeginning(59, "Roger");
    myList.insertAtBeginning(52, "Beth");
    
    do {
        // Options menue
        cout << endl << "1 -- insert at beginning" << endl;
        cout << "2 -- delete from beginning " << endl;
        cout << "3 -- delete key" << endl;
        cout << "4 -- display" << endl;
        cout << "5 -- size" << endl;
        cout << "6 -- sort the list" << endl;
        cout << "7 -- EXIT." << endl << endl;
        
        cout << "What would you like to do: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "Enter a ID: ";
                cin >> inputID;
                cout << "Enter a name: ";
                cin >> inputName;
                myList.insertAtBeginning(inputID, inputName);
                break;
            case 2:
                myList.deleteFromBeginning();
                break;
            case 3:
                cout << "Enter the name to be deleted: ";
                cin >> inputName;
                myList.deleteKey(inputName);
                break;
            case 4:
                myList.displayList();
                break;
            case 5:
                cout << "List size is: " << myList.getSize() << endl;
                break;
            case 6:
                myList.bSortList();
                break;
        }
    } while( choice != 7);
    
    return 0;
    
}

