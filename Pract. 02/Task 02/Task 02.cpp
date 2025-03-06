// Task 02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

double findSum(double a, double b, double c) {
    return a + b + c;
}

double findProduct(double a, double b, double c) {
    return a * b * c;
}


void saveFile(const char* fileName, double sum, double product) {
    std::ofstream ofs(fileName);

    if (!ofs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    ofs << sum << std::endl << product;
    ofs.close();
}

void readFromFile(const char* fileName, double& sum, double& product) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    ifs >> sum >> product;
    ifs.close();
}

void printDifference(const char* filename) {

    double sum, product;
    readFromFile(filename, sum, product);

    std::cout << (sum - product) << std::endl;

}


int main()
{
    int a, b,c;

    std::cin >> a >> b >>c;
    saveFile("input.txt", findSum(a, b, c), findProduct(a, b, c));
    printDifference("input.txt");
}

