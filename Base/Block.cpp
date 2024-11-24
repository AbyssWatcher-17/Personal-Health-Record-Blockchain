#include "Block.h"


    Block::Block(const std::string& prevHash) : previousHash(prevHash) {}

    void Block::addRecord(Record* record) {
        std::lock_guard<std::mutex> lock(mtx);
        records.push_back(record);
    }

    void Block::computeHash() {
        std::lock_guard<std::mutex> lock(mtx);
        std::thread hashThread([this]() {
            std::string combinedData;
            for (const auto& record : records) {
                combinedData += record->generateTimestamp();
                
            }
            blockHash = std::to_string(std::hash<std::string>{}(combinedData + previousHash));
        });
        hashThread.join();
    }

    void Block::displayRecords() const {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& record : records) {
            record->display();
        }
    }



