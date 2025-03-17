// Task 05.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <sstream>
#include <fstream>

namespace Constants {
    constexpr int FIRM_MAX_LEN = 20;
    constexpr int BUFFER_MAX_SIZE = 1024;
}

struct JobOffer {
    char firm[Constants::FIRM_MAX_LEN];
    int programmersCount;
    long long salary;
};
void readJobOffer(JobOffer& job);
JobOffer* readJobArray(const char* filename, size_t& size);
int getFileSize(std::ifstream& ifs);
void filterOffers(const char* filePath, long long minSalary);
bool my_compare(const char* str1, const char* str2);
bool existOffers(const char* filePath, const char* name);
JobOffer* readJobArray(const char* filename, size_t& size);


void readJobOffer(JobOffer& job) {
    std::cin.getline(job.firm, Constants::FIRM_MAX_LEN);
    std::cin >> job.programmersCount;
    std::cin >> job.salary;

    std::cin.ignore();

}

void saveJobsInFile(JobOffer* offers, size_t size, const char* filename) {

    std::ofstream ofs(filename, std::ios::binary | std::ios::app);

    if (!ofs.is_open()) {
        return;
    }

    ofs.write((const char*)offers, size * sizeof(JobOffer));

}

int getFileSize(std::ifstream& ifs) {
    size_t currPos = ifs.tellg();
    ifs.seekg(0, std::ios::end);
    size_t size = ifs.tellg();
    ifs.seekg(currPos);

    return size;

}

unsigned countFilteredJobOffers(JobOffer* offers, size_t size, long long minSalary)
{
    unsigned count = 0;
    for (size_t i = 0; i < size; i++) {
        if (offers[i].salary > minSalary) {
            count++;
        }
    }

    return count;
}

void filterOffers(const char* filePath, long long minSalary) {

    size_t size = 0;
    JobOffer* offers = readJobArray(filePath, size);

    unsigned count = countFilteredJobOffers(offers, size, minSalary);

    JobOffer* filteredOffers = new JobOffer[count];
    int idx = 0;
    for (size_t i = 0; i < size; i++) {
        if (offers[i].salary > minSalary) {
            filteredOffers[idx++] = offers[i];
        }
    }

    delete[] offers;

    saveJobsInFile(filteredOffers, count, "filtered.dat");
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

bool existOffers(const char* filePath, const char* name) {
    
    size_t size = 0;
    JobOffer* offers = readJobArray(filePath, size);

    for (int i = 0; i < size; i++) {
        
        if (my_compare(offers[i].firm, name)) {
            delete[] offers;
            return true;
        }
    }
    delete[] offers;

    return false;
}

JobOffer* readJobArray(const char* filename, size_t& size) {
    std::ifstream ifs(filename, std::ios::binary);

    if (!ifs.is_open()) {
        return nullptr;
    }

    size = getFileSize(ifs) / sizeof(JobOffer);

    JobOffer* offers = new JobOffer[size];

    ifs.read((char*)offers, size * sizeof(JobOffer));

    ifs.close();

    return offers;

}


int main()
{
    int n;
    std::cin >> n;
    std::cin.ignore();


    JobOffer* jobs = new JobOffer[n];

    for (size_t i = 0; i < n; i++) {
        readJobOffer(jobs[i]);
    }

    saveJobsInFile(jobs, n, "input.dat");
    filterOffers("input.dat", 200);



}

