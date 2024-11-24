#include "../Users/Patient.h"



Patient::Patient(const std::string& id, const std::string& userName) : User(id,userName)
{
    std::cout <<"Created Patient\n";
}

void Patient::accessRecord(const Record* record) const {
    if (record) {
        asyncDisplay(record);
    }
}

void Patient::asyncDisplay(const Record* record)  const {
    std::thread displayThread([record]() {
        record->display();
    });
    displayThread.detach(); // Allow it to run independently
}