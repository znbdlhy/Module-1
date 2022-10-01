//
//  information.cpp
//  Final Project
//
//  Created by Haoyang Li on 7/14/22.
//

#include "information.h"
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

Information::Information()
{
    address = "";
    city = "";
    state = "";
    zip_code = "";
    phone_number = "";
};

Information::Information(const Information& rhs)
{
    address = rhs.address;
    city = rhs.city;
    state = rhs.state;
    zip_code = rhs.zip_code;
    phone_number = rhs.phone_number;
};

Information::~Information()
{
    cout << "In Contact destructor (address is " << address << ")" << endl;
};


void Information::addInfo()
{
    cin.ignore();
    cout << "Enter Address: ";
    getline(cin, address);
    cout << "Enter City: ";
    getline(cin, city);
    cout << "Enter State: ";
    getline(cin, state);
    cout << "Enter Zip Code: ";
    getline(cin, zip_code);
};

void Information::showInfo()
{
    cout << address << ", " << city << ", " << state << ", " << zip_code << "\n";
};

