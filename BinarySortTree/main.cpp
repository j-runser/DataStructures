// In today's class, we will discuss designing and implementing a Binary
//     Search Tree. There are many ways to implement it, and this way is
//     one of them.
//
// Note: We will use recursion in our implementation, we will take
//     the advantage of tree structure. (i.e every subtree is a tree.)

#include "BinarySearchTree.hpp"
#include <iostream>

int main() {
    
    // Numbers are stored in an array for simplicity.
    const int arraySize = 10;
    int testData[arraySize] = {40, 30, 100, 40, 7, 22, 87, 13, 40, 15};

    // Create a BST object, myTree
    BSTree myTree;
    
    // Print empty tree and report its height
    myTree.printInOrder();
    cout << "Tree height BEFORE insertion: " << myTree.treeHeight() << endl << endl;
    
    // Insert the numbers to myTree one-by-one
    for(int i = 0; i < arraySize ; i++) {
        myTree.insertNode(testData[i]);
    }
    
    // Print the tree using in-order traversal
    myTree.printInOrder();
    cout << "Tree height AFTER insertion: " << myTree.treeHeight() << endl << endl;
    
    // Test the findKey(int key) function.
    myTree.findKey(7);
    myTree.findKey(100);
    myTree.findKey(11);
    myTree.findKey(40);
    
    cout << endl;
    
    return 0;

}
