#ifndef RECORD_INCLUDED
#define RECORD_INCLUDED

#include <chrono>
#include <string>
#include <iostream>
#include <thread>

class Record {
protected:
    std::string recordId;
    std::string timestamp;
    std::string patientId;

public:
    Record(const std::string& id);
    virtual void display() const = 0; // Pure virtual for polymorphism
    //virtual void asyncDisplay(const Record* record) = 0; 
    virtual ~Record() = 0; // Pure virtual destructor
    std::string generateTimestamp();
    std::string getId();
};


#endif