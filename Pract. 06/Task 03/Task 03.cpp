
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)



class Task {
    char* description; 
    unsigned priority;
    bool status;
    unsigned duration;

    void setDescription(const char* description) {
        if (!description) {
            return;
        }

        size_t len = strlen(description) + 1;
        this->description = new char[len];

        strcpy(this->description, description);

    }

    void copyFrom(const Task& other) {
        setDescription(other.description);
        setPriority(other.priority);
        setDuration(other.duration);
        setStatus(other.status);
    }

    void free() {
        delete[] description;
    }


public:

    Task() = default;

    Task(const char* description, unsigned priority, unsigned duration) : status(false){
        setDescription(description);
        setPriority(priority);
        setDuration(duration);
    }

    Task(const Task& other) {
        copyFrom(other);
    }

    Task& operator=(const Task& other) {
        if (this != &other) {
            free();
            copyFrom(other);
        }

        return *this;
    }

    bool operator>(const Task& other) const {
        if (this->priority > other.priority) {
            return true;
        }
        else if (this->priority == other.priority) {
            return other.duration < this->duration;
        }
        else {
            return false;
        }

    }

    void setPriority(unsigned priority) {
        this->priority = priority;
    }

    void setDuration(unsigned duration) {
        this->duration = duration;
    }

    void setStatus(bool status) {
        if (this->status) {
            return;
        }

        this->status = status;
    }

    void saveInTextFile(std::ofstream& ofs) const {
        if (!ofs.is_open()) {
            return;
        }

        ofs << strlen(this->description) << std::endl;
        ofs << this->description << std::endl;
        ofs << this->duration << std::endl;
        ofs << this->priority << std::endl;
        ofs << this->status << std::endl;


    }

    char* getDescription() const {
        return this->description;
    }

    unsigned getPriority() const {
        return this->priority;
    }

    unsigned getDuration() const {
        return this->duration;
    }

    bool getStatus() const {
        return this->status;
    }

    ~Task() {
        free();
    }




};

int main()
{
    Task* task = new Task("who is messi", 4, 10);

    Task task1 = *task;

    std::cout << task1.getDescription();


    std::ofstream ofs("output.txt", std::ios::trunc);
    task1.saveInTextFile(ofs);

    delete task;



}

