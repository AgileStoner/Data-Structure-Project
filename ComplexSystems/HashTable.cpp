//
//  HashTable.cpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 04/12/22.
//

#include "HashTable.hpp"

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new Linkedlist[BUCKET];
}


int Hash::hashFunction(string phone) {
    int convert;
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        convert = phone[i];
        sum += convert;
    }
    return (sum % BUCKET);
}


void Hash::insertItem(Client* user)
{
    int index = hashFunction(user->getPhone());
    
    //table[index].push_back(user.getNumber());
    table[index].insertNode(user->getID(), user->getName(), user->getPhone(), user->getSub());
}
    
Node* Hash::searchItem(string phone){
    int index = hashFunction(phone);
    int NodeIndex = table[index].getIndex(phone);
    if (NodeIndex == -1){
        cout << "The key does not exist" << endl;
        return NULL;
    }
    return table[index].getNodeAddress(NodeIndex);
}
 
void Hash::deleteItem(string phone)
{
    // get the hash index of key
    /*int index = hashFunction(phone);
    
    // find the key in (index)th list
    int ListIndex = table[index].getIndex(phone);
    if (ListIndex == -1){
        cout << "The key does not exist"<<endl;
        return;
    }*/
    int index = hashFunction(phone);
    table[index].deleteNode(phone);
}
 
// function to display hash table
void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++){
        cout << "Index: " << i;
        table[i].printList();
        cout << endl;
    }
}
