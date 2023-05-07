//
//  Client.hpp
//  ComplexSystems
//
//  Created by Asadulla Kudrateellaev on 04/12/22.
//

#ifndef Client_hpp
#define Client_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include "LinkedList.hpp"
using namespace std;

class Client{
private:
    static int count;
    int id;
    string name;
    string phone;
    int subscription;
public:
    Client(){
        id = ++count;
    }
    Client(string phone, string name, int subscription, int id){
        this->name = name;
        this->phone = phone;
        this->subscription = subscription;
        if (id != -1){
            this->id = id;
        }
    }
    string getName(){
        return name;
    }
    void setName(string NAME){
        name = NAME;
    }
    int getID(){
        return id;
    }
    string getPhone(){
        return phone;
    }
    void setPhone(int NUM){
        phone = NUM;
    }
    int getSub(){
        return subscription;
    }
    void setSub(int Sub){
        subscription = Sub;
    }
};

#endif /* Client_hpp */
