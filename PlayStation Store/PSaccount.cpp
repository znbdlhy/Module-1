//
//  PSaccount.cpp
//  Final Project
//
//  Created by Haoyang Li on 7/14/22.
//

#include <iostream>
#include <string>
#include <list>
#include <algorithm>
#include <numeric>
#include "account.h"

using namespace std;

void add_member(list<Account>& member_list)
{
    string name;
    float balance;
    
    cout << "Enter the name: ";
    cin >> name;
    cout << "Enter the balance: ";
    cin >> balance;
    
    Account account{name, balance};
    
    member_list.push_back(account);
}

void display_member(list<Account>& member_list)
{
    list<Account>::iterator it;
    for (it = member_list.begin(); it != member_list.end(); it++)
    {
        it->Display();
    }
}

void remove_members(list<Account>& member_list, int removeID)
{
    auto remove = remove_if(member_list.begin(), member_list.end(), [removeID](auto& person) {return removeID == person.get_id(); });
    member_list.erase(remove, member_list.end());
}

list<Account>::iterator find_by_id(list<Account>& member_list, int id)
{
    list<Account>::iterator it;
    for (it = member_list.begin(); it != member_list.end(); it++)
    {
        if (it->get_id() == id)
        {
            return it;
        }
    }
    
    return it;
}

int main()
{
    Account account;
    Information information;
    int choice = -1;
    int removeID;
    int console;
    
    list<Account> members;
    
    while (choice != 6)
    {
        cout << "\nWelcome to the PlayStation Store!\n";
        cout << "\nMenu:\n";
        cout << "0. Create an PlayStation account\n";
        cout << "1. Remove an account\n";
        cout << "2. Display Account Information\n";
        cout << "3. Add fund to an account\n";
        cout << "4. Add shipping address to an account\n";
        cout << "5. Purchase a PlayStation 5 Console\n";
        cout << "6. Quit the programe\n";
        cout << "Your choice: ";
        cin >> choice;
        
        if (choice == 0)
        {
            add_member(members);
        }
        
        else if (choice == 1)
        {
            cout << "Enter account ID to remove: ";
            cin >> removeID;
            list<Account>::iterator it;
            it = find_by_id(members, removeID);

            if (it != members.end())
            {
                remove_members(members, removeID);
            }
            else
            {
                cout << "Account not found." << endl;
            }
        }
        
        else if (choice == 2)
        {
            display_member(members);
        }
        
        else if (choice == 3)
        {
            int input;
            cout << "Enter the ID of the account to find: ";
            cin >> input;
            list<Account>::iterator it;
            it = find_by_id(members, input);
            
            if (it != members.end())
            {
                cout << "Found account: ";
                it->Display();
            }
            
            else
            {
                cout << "That ID was not found\n";
            }
            it->AddFund();
        }
        
        else if (choice == 4)
        {
            int input;
            cout << "Enter the ID of the account to find: ";
            cin >> input;
            list<Account>::iterator it;
            it = find_by_id(members, input);
            
            if (it != members.end())
            {
                cout << "Found account: ";
                it->Display();
                it->addaccountInfo();
            }
            
            else
            {
                cout << "That ID was not found\n";
            }
        }
        
        else if (choice == 5)
        {
            cout << "1. PS5 Console: $499\n";
            cout << "2. PS5 Digital Edition: $399\n";
            cout << "Your Choice: ";
            cin >> console;
            
            int input;
            cout << "Enter the account ID: ";
            cin >> input;
            
            list<Account>::iterator it;
            it = find_by_id(members, input);
            
            if (it != members.end())
            {
                if (it->getInformation() != nullptr)
                {
                    if (console == 1)
                    {
                            it->Purchase1();
                    }
                    
                    else if (console == 2)
                    {
                        if (it != members.end())
                        {
                            it->Purchase2();
                        }
                    }
                }
                else
                {
                    cout << "\nYou haven't enter any address, please enter the address first, then go back to the opition 5 to repurchase.\n\n";
                    it->addaccountInfo();
                }
            }
        }
    }
}


