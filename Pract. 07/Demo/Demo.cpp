// Demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

class MultiSet {
private:
    uint16_t n;  
    uint8_t k;  
    uint8_t* data; 

    
    size_t getByteSize() const {
        return ((n + 1) * k + 7) / 8; 
    }

    void getBitPosition(uint16_t num, size_t& byteIndex, uint8_t& bitOffset) const {
        size_t bitPos = num * k;
        byteIndex = bitPos / 8;
        bitOffset = bitPos % 8;
    }

public:
    MultiSet(uint16_t maxNum, uint8_t bitCount) : n(maxNum), k(bitCount) {
        data = new uint8_t[getByteSize()](); 
    }

    
    ~MultiSet() {
        delete[] data;
    }

    void add(uint16_t num) {
        if (num > n) return;
        size_t byteIndex;
        uint8_t bitOffset;
        getBitPosition(num, byteIndex, bitOffset);

        uint16_t count = (data[byteIndex] >> bitOffset) & ((1 << k) - 1);
        if (count < (1 << k) - 1) {
            count++;
            data[byteIndex] &= ~(((1 << k) - 1) << bitOffset);
            data[byteIndex] |= (count << bitOffset);
        }
    }

    uint16_t count(uint16_t num) const {
        if (num > n) return 0;
        size_t byteIndex;
        uint8_t bitOffset;
        getBitPosition(num, byteIndex, bitOffset);
        return (data[byteIndex] >> bitOffset) & ((1 << k) - 1);
    }

    void print() const {
        for (uint16_t i = 0; i <= n; i++) {
            uint16_t c = count(i);
            if (c > 0) {
                std::cout << i << " -> " << c << " times\n";
            }
        }
    }

    void serialize(const char* filename) {
        std::ofstream file(filename, std::ios::binary);
        file.write((const char*)data, getByteSize());
    }

    void deserialize(const char* filename) {
        std::ifstream file(filename, std::ios::binary);
        file.read((char*)(data), getByteSize());
    }

    MultiSet intersection(const MultiSet& other) const {
        MultiSet result(n, k);
        for (size_t i = 0; i < getByteSize(); i++) {
            result.data[i] = data[i] & other.data[i];
        }
        return result;
    }

    MultiSet difference(const MultiSet& other) const {
        MultiSet result(n, k);
        for (size_t i = 0; i < getByteSize(); i++) {
            result.data[i] = data[i] & ~other.data[i];
        }
        return result;
    }
};

struct Test {
    char a;
    unsigned age;

};

struct A {
    char arr[5];
    int f;
    bool g;
};

struct B {
    float* c;
    char a;
    bool b;
};

struct C {
    int a;
    A obj1;
    bool f;
    B obj2;
};





int main() {
    std::cout << sizeof(size_t);
}