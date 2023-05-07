//
//  main.cpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 04/12/22.
//

#include <iostream>
#include <limits>
#include <string>
#include <unistd.h>
#include <term.h>
#include "HashTable.hpp"
#include "Client.hpp"
#include "Queue.hpp"
using namespace std;


Hash ClientRecords(500); //Hash table to store records of clients

void menu();

int inputInt(int low_bound, int up_bound){ //Function which catches wrong inputs(works only with int)
    int i;
    while (true)
    {
        cin >> i;
        if (!cin or i < low_bound or i > up_bound)
        {
            cout << "Wrong Choice. Enter again " << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else break;
    }
    return i;
}

string InputPhone(){ //Function to input phone in a right format
    string phone;
    while(true){
        cout << "Enter Phone Number: +998 ";
        cin >> phone;
        if(phone.length() != 9){
            system("clear");
            cout << "Incorrect amount of digits!" << endl;
            continue;
        }
        for (int i = 0; i < 9; i++){
            if(!isdigit(phone[i])){
                system("clear");
                cout << "Number includes chars" << endl;
                continue;
            }
        }
        break;
    }
    return phone;
}

void EnterComplex(){ //Implements client entering function
    system("clear");
    string phone = InputPhone();
    Node* client = ClientRecords.searchItem(phone);
    if(client == NULL){
        cout << "Client not found" << endl;
        return;
    }
    if (client->subscription <= 0){
        cout << "Subscription has expired :(" <<endl<<endl<<endl;
        return;
    }
    client->subscription -= 1;
    system("clear");
    cout << "Client "<< client->name << "(" <<client->phone<< ")" << " has entered the cout"<<endl;
    cout << "Client has " << client->subscription <<" amount of entries left" << endl << endl << endl;
    return;
}


void AddClient(){//Creates a client and adds to hash table
    system("clear");
    string phone = InputPhone();
    string name;
    int sub;
    Node* findNode = ClientRecords.searchItem(phone);
    if(findNode == NULL){
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter amount of subscription: ";
        cin >> sub;
        ClientRecords.insertItem(new Client(phone, name, sub, -1));
        system("clear");
        cout << "Client with Phone Number: " << phone <<endl;
        cout << "Name: " << name << endl;
        cout << "Amount of subscription: " << sub << endl;
        cout << "has been added "<<endl << endl << endl;
        return;
    }
    system("clear");
    cout << "Client is already in table" << endl << endl << endl;
    return;
    
}


void RemoveClient(){
    system("clear");
    string phone = InputPhone();
    Node* client = ClientRecords.searchItem(phone);
    if(client == NULL){
        cout << "Client not found" << endl;
        return;
    }
    ClientRecords.deleteItem(phone);
    cout << "Client "<< client->name << "(" <<client->phone<< ")" << " was removed"<<endl << endl << endl;
    return;
}


void EditClient(){
    system("clear");
    string phone = InputPhone();
    Node* client = ClientRecords.searchItem(phone);
    if(client == NULL){
        cout << "Client not found" << endl << endl << endl;
        return;
    }
    cout << "1. Edit phone" << endl;
    cout << "2. Edit name" << endl;
    cout << "3. Add subscription" << endl;
    cout << "0. Back to Menu" << endl;
    cout << "Choose what you would like to change: ";
    int choice = inputInt(0, 3);
    if (choice == 1){
        string name = client->name;
        int sub = client->subscription;
        int id = client->id;
        ClientRecords.deleteItem(phone);
        phone = InputPhone();
        ClientRecords.insertItem(new Client(phone, name, sub, id));
        system("clear");
        cout << "Phone Number was changed to " << client->phone << endl << endl << endl;
        return;
        
    }
    else if (choice == 2){
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        client->name = name;
        system("clear");
        cout << "Name was changed to " << client->name << endl << endl << endl;
        return;
    }
    else if (choice == 3){
        cout << "Client has "<<client->subscription<<" amount of entries left " << endl;
        cout << "How much entries would you like to add (enter negative value if you want to subract): ";
        int sub = inputInt(-100, 300);
        client->subscription += sub;
        system("clear");
        cout << "Subscription was changed to " << client->subscription << endl << endl << endl;
        return;
    }
    else if(choice == 0){
        return;
    }
    
}


void FindClient(){
    system("clear");
    string phone = InputPhone();
    Node* client = ClientRecords.searchItem(phone);
    if(client == NULL){
        cout << "Client not found" << endl << endl << endl;
        return;
    }
    cout << "1. Get ID" << endl;
    cout << "2. Get name" << endl;
    cout << "3. Get subscription" << endl;
    cout << "4. Get all" << endl;
    cout << "0. Back to Menu" << endl;
    cout << "Choose what you would like to change: ";
    int choice = inputInt(0, 4);
    if (choice == 1){
        system("clear");
        cout << "ID: " << client->id << endl << endl << endl;
        return;
    }
    if (choice == 2){
        system("clear");
        cout << "Name: " << client->name << endl << endl << endl;
        return;
    }
    if (choice == 3){
        system("clear");
        cout << "Subscription left: " << client->subscription << endl << endl << endl;
        return;
    }
    if (choice == 4){
        system("clear");
        cout << "ID: " << client->id << endl;
        cout << "Name: " << client->name << endl;
        cout << "Phone: " << client->phone << endl;
        cout << "Subscription left: " << client->subscription << endl;
        return;
    }
    if (choice == 0){
        system("clear");
        return;
    }
    
}


void PrintHashTable(){
    ClientRecords.displayHash();
    cout << endl << endl << "Enter anything to get back to menu";
    string choice;
    cin >> choice;
    menu();
}

void menu(){
    while(true){
        cout << "1. Add Client" << endl;
        cout << "2. Remove Client" << endl;
        cout << "3. Edit Client" << endl;
        cout << "4. Enter Complex" << endl;
        cout << "5. Print hash table" << endl;
        cout << "6. Find client" << endl;
        cout << "Choose the operation: ";
        int choice = inputInt(1, 6);
        switch (choice) {
            case 1:
                AddClient();
                break;
            case 2:
                RemoveClient();
                break;
            case 3:
                EditClient();
                break;
            case 4:
                EnterComplex();
                break;
            case 5:
                PrintHashTable();
            case 6:
                FindClient();
                
            default:
                break;
        }
    }
}



int main(int argc, const char * argv[]) {
    menu();
    
    return 0;
}
