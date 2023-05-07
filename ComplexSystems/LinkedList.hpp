//
//  LinkedList.hpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 07/12/22.
//

#ifndef LinkedList_hpp
#define LinkedList_hpp

#include <stdio.h>

#include <iostream>
#include <string>
#include <cstring>
using namespace std;



// C++ program for the above approach
#include <iostream>
using namespace std;
 
// Node class to represent
// a node of the linked list.
class Node {
public:
    string name;
    int id;
    string phone;
    int subscription;
    Node* next;
 
    // Default constructor
    Node(){}
 
    // Parameterised Constructor
    Node(int id, string name, string phone, int subscription)
    {
        this->id = id;
        this->name = name;
        this->phone = phone;
        this->subscription = subscription;
        this->next = NULL;
    }
    
};
 
// Linked list class to
// implement a linked list.
class Linkedlist {
    Node* head;
 
public:
    // Default constructor
    Linkedlist() { head = NULL; }
 
    // Function to insert a
    // node at the end of the
    // linked list.
    void insertNode(int, string, string, int);
 
    // Function to print the
    // linked list.
    void printList();
 
    // Function to delete the
    // node at given position
    void deleteNode(string);
    
    //Get node address by index
    Node* getNodeAddress(int);
    
    //Returns index in linked list
    int getIndex(string);
};
 

#endif /* LinkedList_hpp */
