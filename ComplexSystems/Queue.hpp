//
//  Queue.hpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 07/12/22.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
 
// Define the default capacity of a queue
#define SIZE 1000
 
// A class to store a queue
class Queue
{
    string *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue
 
public:
    Queue(int size = SIZE);     // constructor
    ~Queue();                   // destructor
 
    string dequeue();
    void enqueue(string x);
    string peek();
    int size();
    bool isEmpty();
    bool isFull();
};


#endif /* Queue_hpp */
