// Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

void saveArrayInFile(const char* str, std::ofstream& ofs) {

    if (!ofs.is_open()) {
        return;
    }
    size_t len = strlen(str);

    ofs.write((const char*)&len, sizeof(len));
    ofs.write(str, strlen(str));

    ofs.close();

}

char* readArrayFromFile(std::ifstream& ifs) {
    if (!ifs.is_open()) {
        return nullptr;
    }

    size_t len = 0;
    ifs.read((char*)&len, sizeof(len));
    char* charArr = new char[len + 1];
    ifs.read(charArr, len);
    charArr[len] = '\0';

    return charArr;
}

int main()
{
    std::ofstream ofs("output.dat", std::ios::binary);
    
    char arr[] = "abc";
    saveArrayInFile(arr, ofs);

    std::ifstream ifs("output.dat", std::ios::binary);


    char* arr2 = readArrayFromFile(ifs);

    std::cout << arr2;
    
}

