#include <string>
#include "Record.h"



std::string Record::generateTimestamp() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        return std::ctime(&time);
    }

Record::Record(const std::string& id) : recordId(id), timestamp(generateTimestamp()){};

Record::~Record() {}