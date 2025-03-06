// Task 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

// Files Theory 
// .tellg() - returns the position of get pointer (ifstream)
// .tellp() - returns the position of put pointer (ofstream)
// .seekg(offset, position) - put the get pointer offset positions 
// .seekp(offset, position) - put the put pointer offset positions

// by default position is std::ios::beg

// std::ios::beg - the beginning of the file
// std::ios::end - the end of the file 
// std::ios::curr - the current position of the pointer 

// cout is object of type ostream
// cin is object of type istream

// UNFORMATTED INPUT
// ---------------------------------------------------------------------------
// .get() - return ASCII code of the symbol which is on the position of get pointer 
//          and move get pointer with one position
// .peek() - return ASCII code of the symbol which is on the position of get pointer
//           but NOT move the pointer
// .ignore() - move get pointer with one position 
// .ignore(positionsCount) - move get pointer with positionsCount positions 
// .ignore(positionsCount, delim)

// .get(char* buffer, int BUFFER_SIZE, char delim) - Прочита съдържанието на файла в буфера, 
//      докато не срещне разделител или докато не се запълни буферът. 
//      В буфера, на мястото на разделителя слага терминираща нула. 
//      Разделителят по подразбиране е краят на файла. 
//      Премества get указателя НА ПОЗИЦИЯТА, НА КОЯТО Е БИЛ РАЗДЕЛИТЕЛЯТ!

// .getline(char* buffer, int BUFFER_SIZE, char delim) - Прочита съдържанието на файла в буфера, 
//      докато не срещне разделител или докато не се запълни буферът. 
//      В буфера, на мястото на разделителя слага терминираща нула. 
//      Разделителят по подразбиране е краят на файла. 
//      Премества get указателя НА ПОЗИЦИЯТА, СЛЕД РАЗДЕЛИТЕЛЯТ!


// UNFORMATTED OUTPUT
// ---------------------------------------------------------------------
// .put(char ch) - поставя един символ на позицията на put указатля
// 


unsigned findOccurrencesSymbolInFile(const char* fileName, char symbol) {
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) {
        return 0; 
    }

    unsigned occurs = 0;

    while (true) {
        int currCharacter = ifs.get();
        
        if (ifs.eof()) {
            ifs.close();
            return occurs;
        }

        if (currCharacter = symbol) {
            occurs++;
        }
    }
}


int main()
{
    
}
