#include "LinkedList.hpp"
//
//  LinkedList.hpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 07/12/22.
//

#include "LinkedList.hpp"


// Function to delete the
// node at given position
void Linkedlist::deleteNode(string phone)
{
    Node *temp1 = head, *temp2 = NULL;
    if(head == NULL){
        cout <<"Empty list"<<endl;
        return;
    }
    
    while(temp1->phone != phone){
        if(temp1 == NULL){
            cout << "Key value not found" << endl;
            return;
        }
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;
}
 
// Function to insert a new node.
void Linkedlist::insertNode(int id, string name, string phone, int subscription)
{
    // Create the new Node.
    Node* newNode = new Node(id, name, phone, subscription);
 
    // Assign to head
    if (head == NULL) {
        head = newNode;
        return;
    }
 
    // Traverse till end of list
    Node* temp = head;
    while (temp->next != NULL) {
 
        // Update temp
        temp = temp->next;
    }
 
    // Insert at the last.
    temp->next = newNode;
}
 
// Function to print the
// nodes of the linked list.
void Linkedlist::printList()
{
    Node* temp = head;
 
    // Check for empty list.
    if (head == NULL) {
        cout << "Empty" << endl;
        return;
    }
 
    // Traverse the list.
    while (temp != NULL) {
        cout << " - | " << temp->id << " | " << temp->name <<" | " << temp->phone << " | " << temp->subscription << " | " << " -> ";
        temp = temp->next;
    }
}


Node* Linkedlist::getNodeAddress(int index){
    Node* temp = this->head;
    if (this->head == NULL){
        cout << " - Empty" << endl;
        return NULL;
    }
    
    for(int i = 0; i < index; i++){
        if(temp == NULL and i < index){
            cout << "Index out of bound" << endl;
            return NULL;
        }
        temp = temp->next;
    }
    return temp;
    
}




int Linkedlist::getIndex(string key){
    Node* temp = head;
    int ListLen = 0;
    if (head == NULL){
        cout << "List is empty" << endl;
        return -1;
    }
    
    while (temp != NULL){
        if (key == temp->phone){
            return ListLen;
        }
        temp = temp->next;
        ListLen++;
    }
    return -1;
}

