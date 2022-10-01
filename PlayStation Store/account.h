//
//  account.h
//  Final Project
//
//  Created by Haoyang Li on 7/14/22.
//

using namespace std;
#include <iostream>
#include <string>
#include <memory>
#include "information.h"

class Account
{
public:
    int get_id() {return id_number;}
    float get_balance() {return balance;}
    void Display();
    void AddFund();
    void Purchase1();
    void Purchase2();
    Account();
    Account(string name, float balance);
    
    shared_ptr<Information> getInformation() const { return information; };
    
    Account& operator*(const float& rhs) {
        balance *= rhs;
        return *this;
    };
    
    void addaccountInfo();
    
private:
    int id_number;
    static int next_id;
    string name;
    float balance;
    shared_ptr<Information> information;
};



