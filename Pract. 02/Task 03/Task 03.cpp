// Task 03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

size_t getFileSize(std::ifstream& ifs)
{
    size_t currPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currPos, std::ios::beg);
    return size;
}

int* readArrayFromFile(const char* filename, size_t& size) {
    std::ifstream ifs(filename);

    if (!ifs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return nullptr;
    }

    if (!getFileSize(ifs)) {
        std::cout << "The file is empty" << std::endl;
        return nullptr;
    }

    ifs >> size;
    
    int* arr = new int[size];
    for (size_t i = 0; i < size; i++) {
        ifs >> arr[i];
    }

    ifs.close();
    
    return arr;
}


bool descendingOrder(int a, int b)
{
    return (a > b);
}

bool ascendingOrder(int a, int b)
{
    return (a < b);
}

void selectionSort(int* arr, size_t size, bool(*predicate)(int, int))
{
    for (size_t i = 0; i < size - 1; i++)
    {
        size_t bestIndex = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (predicate(arr[j], arr[bestIndex]))
            {
                bestIndex = j;
            }
        }
        if (bestIndex != i)
        {
            std::swap(arr[i], arr[bestIndex]);
        }
    }
}


void saveArrayInFile(const char* filename, size_t size, int* arr, bool(*predicate)(int, int)) {
    if (!arr) {
        return;
    }

    selectionSort(arr, size, predicate);

    std::ofstream ofs(filename);

    if (!ofs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    ofs << size << std::endl;
    for (size_t i = 0; i < size; i++) {
        ofs << arr[i] << " ";
    }
    ofs.close();

}


int main()
{
    size_t size;
    int* arr = readArrayFromFile("input.txt", size);
    saveArrayInFile("ascending.txt", size, arr, ascendingOrder);
    saveArrayInFile("descending.txt", size, arr, descendingOrder);
    delete[] arr;
}

