//
//  BinarySearchTree.cpp
//  BinarySortTree
//
//  Created by Joseph Runser on 11/15/17.
//  Copyright © 2017 Joe's Laptop. All rights reserved.
//

#include "BinarySearchTree.hpp"

// Constructor -- initialize root pointer to NULL
BSTree::BSTree(){
    
    root = NULL;
    
}

// A utility function to create a node and returns a pointer to the created node
BSTree::node* BSTree::createNode(const int addData){
    
    node* newNode = new node;
    
    newNode->data = addData;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}



// Node insertion is done recursively, that's why we have
// a utility function that has two parameters: data + pointer
void BSTree::insertNode(const int addData){
    
    insertNodeUtil(addData, root);
    
}



// This function uses recursion to find the right place for
// new node to inserted. Every subtree is considered as a tree.
void BSTree::insertNodeUtil(const int data, node* subTreePtr) {
    
    if(root == NULL) { // Check for an empty tree.
        root = createNode(data);
    }
    else if (data <= subTreePtr->data) { // Check the left side of the tree
        // Keep going to the left until we find a node that has left child
        if( subTreePtr->left == NULL) {
            subTreePtr->left = createNode(data);
        }
        else { // keep going left
            insertNodeUtil(data, subTreePtr->left);
        }
    }
    else /*if(data > subTreePtr->data) */ { // check the right side of the tree
        if( subTreePtr->right == NULL) {
            subTreePtr->right = createNode(data);
        }
        else { // keep going right
            insertNodeUtil(data, subTreePtr->right);
        }
    }
    
}

// in-order traversal: Left-Root-Right
// we use a recursive utility function
void BSTree::printInOrder() {
    
    printInOrderUtil(root);
    cout<<endl;
    
}



// utility function to traverse a tree recursively
// in-order traversal:
// 1) explore left side - 2) print node - 3) expolre right side
void BSTree::printInOrderUtil(node* subTreePtr) {
    
    if (root == NULL) {
        cout<<"The TREE is Empty ..."<<endl;
    }
    else {
        // 1) explore left side
        if(subTreePtr->left != NULL) {
            printInOrderUtil(subTreePtr->left);
        }
        
        // 2) print node
        cout << subTreePtr->data << " ";
        
        // 3) expolre right side
        if(subTreePtr->right != NULL) {
            printInOrderUtil(subTreePtr->right);
        }
    }
    
}

// Find the height of a tree, the height of an empty tree is 0
// treeHeight() function will call treeHeightUtil(root) function to
// find the height of a given treen recursively
int BSTree::treeHeight() {
    
    if(root == NULL)
        return 0;
    else
        return treeHeightUtil(root);
    
}



// this utility function will find the height of a given tree by
// taking the maximum height of left and right subtrees.
int BSTree::treeHeightUtil(node* subTreePtr) {
    
    if(subTreePtr == NULL) {
        return 0;
    }
    else{
        int lHeight = treeHeightUtil(subTreePtr->left) + 1;
        int rHeight = treeHeightUtil(subTreePtr->right) + 1;
        
        return (lHeight >= rHeight ? lHeight : rHeight);
        /* another way to do it using if-else
         * if( lHeight >= rHeight){
         *     return lHeight;
         * }
         * else{
         *     return rHeight;
         * }
         */
    }
    
}

bool BSTree::findKey(const int key) {
    
    return findKeyUtil(key, root);
    
}

// This utility function is a recursive function to implement this function:
//     1) think of the base case(s), where you terminate the function
//     2) think of the sub-problems that will be solved recursively.
bool BSTree::findKeyUtil(const int key, node* subTreePtr) {
    
    if(subTreePtr == NULL) {
        cout << key << " could not be found." << endl;
        return false;
    }
    else if(subTreePtr->data == key) {
        cout << key << " has been found." << endl;
        return true;
    }
    else if(subTreePtr->data > key) {
        return findKeyUtil(key, subTreePtr->left);
    }
    else {
        return findKeyUtil(key, subTreePtr->right);
    }
}
