// Task 06.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

namespace Constants {
    constexpr int MAX_LEN = 20;
    
}

//void saveBooksInBinaryFile(const char* filename, Book* books, size_t size);
size_t getFileSize(std::ifstream& ifs);


struct Book {
    char Title[Constants::MAX_LEN];
    char Author[Constants::MAX_LEN];
    int Year;
    int Copies;
};

size_t getFileSize(std::ifstream& ifs) {
    size_t currPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currPos);

    return size;
}

void saveBooksInBinaryFile(const char* filename, Book* books, size_t size) {
    std::ofstream ofs(filename, std::ios::binary | std::ios::app);

    if (!ofs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return;
    }

    ofs.write((const char*)books, size * sizeof(Book));
    ofs.close();
}

Book* readBooksFromBinaryFile(const char* filename, size_t& size) {
    std::ifstream ifs(filename, std::ios::binary);

    if (!ifs.is_open()) {
        std::cout << "Could not open the file" << std::endl;
        return nullptr;
    }

    size_t fileSize = getFileSize(ifs);
    size = fileSize / sizeof(Book);

    Book* books = new Book[size];

    ifs.read((char*)books, size * sizeof(Book));
    ifs.close();

    return books;
}


bool my_compare(const char* str1, const char* str2) {
    if (!str1 || str2) {
        return false;
    }

    while (*str1 && *str2) {

        if (*str1 != *str2) {
            return false;
        }
    }

    return true;

}

void printAllBooks(const char* filename) {
    size_t size = 0;
    Book* books = readBooksFromBinaryFile(filename, size);

    if (!books) {
        return;
    }

    for (size_t i = 0; i < size; i++) {
        std::cout << books[i].Title << " " << books[i].Author << books[i].Year << std::endl;
    }

    delete[] books;
}

void addBook(const char* filename, Book book) {
    size_t newSize = 1;
    Book* books = new Book[1]{book};
    
    saveBooksInBinaryFile(filename, books, newSize);
}

Book findBookByTitle(const char* filename, const char* title) {

    Book book;

    size_t size = 0;

    Book* books = readBooksFromBinaryFile(filename, size);

    for (size_t i = 0; i < size; i++) {
        if (my_compare(books[i].Title, title)) {
            book = books[i];
            break;
        }
    }

    delete[] books;

    return book;


}


int main()
{
    std::cout << "Hello World!\n";
}

