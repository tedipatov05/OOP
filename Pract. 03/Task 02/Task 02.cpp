// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>

namespace Constants{

    constexpr size_t MAX_LEN = 20;
    constexpr size_t BUFFER_SIZE = 1024;
    const char DELIM = '-';
    const char PERSON_DELIM = ' ';
}

struct Person{

    char name[Constants::MAX_LEN];
    int age;
};

size_t getFileSize(std::stringstream& ifs)
{
    size_t currPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currPos, std::ios::beg);
    return size;
}

Person* getPersonArrayFromStr(const char* str, size_t& size){

    if (!str){
        return nullptr;
    }

    std::stringstream ss(str);

    size_t fileSize = getFileSize(ss);

    if (!fileSize){
        return nullptr;
    }




}

int main()
{
    char buffer[Constants::BUFFER_SIZE];

    std::cin.getline(buffer, Constants::BUFFER_SIZE);

    size_t arrSize = 0;
    
}
