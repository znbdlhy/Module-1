//
//  account.cpp
//  Final Project
//
//  Created by Haoyang Li on 7/14/22.
//

#include <iostream>
#include <string>
#include <iomanip>
#include "account.h"

int Account::next_id = -1;

Account::Account(): name(""), id_number(next_id++), balance(0.00), information(nullptr)
{
}

Account::Account(string name, float balance):
  name(name),id_number(next_id++), balance(balance)
{
}

void Account::Display()
{
    cout << "\nAccount ID: " << id_number;
    cout << "\tName: " << name;
    cout << "\tBalance: $" << fixed << setprecision(2) << balance << "\n";
    
    if (Account::getInformation() != nullptr)
    {
        Account::getInformation()->showInfo();
    };
}

void Account::AddFund()
{
    float amount;
    cout << "\nAmount to add: ";
    cin >> amount;
    balance = balance + amount;
}

void Account::Purchase1()
{
    if (balance >= 499)
    {
        balance = balance - 499;
        cout << "Thanks for purchsing the PS5 Console. It'll ship to the following address: ";
        this->getInformation()->showInfo();
    }
    
    else
    {
        cout << "Insufficient balance\n";
    }
}

void Account::Purchase2()
{
    if (balance >= 399)
    {
        balance = balance - 399;
        cout << "Thanks for purchsing the PS5 Digital Edition. It'll ship to the following address: ";
        this->getInformation()->showInfo();
    }
    
    else
    {
        cout << "Insufficient balance\n";
    }
}

void Account::addaccountInfo()
{
    information = make_shared<Information>();
    information->addInfo();
};



