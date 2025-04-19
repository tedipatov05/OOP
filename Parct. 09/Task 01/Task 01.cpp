// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "MyString.h"


int main()
{
    MyString string = "abcd";
    MyString string2 = "fjknwd";
    MyString stringCopy(string);

    string2 += string;

    MyString str = string + string2;

    str[3] = 't';
    std::cout <<std::boolalpha << (string2 == stringCopy);
    
}
