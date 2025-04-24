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

    MyString str = "****888888888888888888888888";

    str.insert(1, "abcd", 2);

	bool result = str.contains("k");

	MyString res = str.substr(5, 3);

    str.erase(1, 5);
	str.append("1234567890", 5);

    std::cout << str;


   /* std::string str = "****888888888888888888888888";

    str.replace(0, 3, "ab");
	std::cout << str << std::endl;*/
    
    
}
