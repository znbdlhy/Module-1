//
//  information.h
//  Final Project
//
//  Created by Haoyang Li on 7/14/22.
//

#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

class Information
{
private:
    string address;
    string city;
    string state;
    string zip_code;
    string phone_number;
    
public:
    Information();
    Information(const Information& rhs);
    ~Information();
    string getAddress()const {return address;};
    void addInfo();
    void showInfo();
    
};
