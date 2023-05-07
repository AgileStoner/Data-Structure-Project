//
//  HashTable.hpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 04/12/22.
//

#ifndef HashTable_hpp
#define HashTable_hpp
#include <iostream>
#include <stdio.h>
#include <list>
#include "Client.hpp"
#include "LinkedList.hpp"
#include <cstring>

//stoi(str) string to int
//to_string(int) int to string

using namespace std;


class Hash
{
    int BUCKET;    // No. of buckets
 
    // Pointer to an array containing buckets
    Linkedlist *table;
public:
    Hash(int V);  // Constructor
 
    // inserts a key into hash table
    void insertItem(Client* user);
 
    // deletes a key from hash table
    void deleteItem(string phone);
    
    //search
    Node* searchItem(string phone);
    
    // Function to compute the ASCII value of each
    // character one by one
 
    // hash function to map values to key
    int hashFunction(string phone);
 
    void displayHash();
};

#endif /* HashTable_hpp */
