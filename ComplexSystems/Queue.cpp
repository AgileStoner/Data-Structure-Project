//
//  Queue.cpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 07/12/22.
//

#include "Queue.hpp"
// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new string[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
 
// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}
 
// Utility function to dequeue the front element
string Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    string x = arr[front];
    cout << "Removing " << x << endl;
 
    front = (front + 1) % capacity;
    count--;
 
    return x;
}
 
// Utility function to add an item to the queue
void Queue::enqueue(string item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
 
    cout << "Inserting " << item << endl;
 
    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}
 
// Utility function to return the front element of the queue
string Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}
 
// Utility function to return the size of the queue
int Queue::size() {
    return count;
}
 
// Utility function to check if the queue is empty or not
bool Queue::isEmpty() {
    return (size() == 0);
}
 
// Utility function to check if the queue is full or not
bool Queue::isFull() {
    return (size() == capacity);
}
