//
//  BinarySearchTree.hpp
//  BinarySortTree
//
//  Created by Joseph Runser on 11/15/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <iostream>

using namespace std;

// Binary Search Tree
class BSTree{
    
private:
    struct node{
        int data;
        node* left;  // a pointer to the left subtree
        node* right; // a pointer to the right subtree
    };
    
    // A pointer to the root node, it declared as a private
    // so users cant access it directly.
    node* root;
    
    // These functions are declared in the private section
    // to be used inside the class as utility functions,
    // user can't use them.
    node* createNode(const int data);
    void insertNodeUtil(const int data, node* subTreePtr);
    void printInOrderUtil(node* subTreePtr);
    int treeHeightUtil(node* subTreePtr);
    bool findKeyUtil(const int key, node* subTreePtr);
    
public:
    BSTree();
    void insertNode(const int addData);
    void printInOrder();
    int treeHeight();
    bool findKey(const int key);
};

#endif /* BinarySearchTree_hpp */
