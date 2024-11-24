#ifndef BLOCK_INCLUDED
#define BLOCK_INCLUDED

#include <vector>
#include <functional>
#include <mutex>
#include <thread>
#include "Record.h"

class Block {
    std::string previousHash;
    std::string currentHash;
    //std::vector<Record*> records;
    std::unique_ptr<Record> record;  // Each block holds a unique record

    std::string blockHash;
    mutable std::mutex mtx;
    std::string calculateHash() const;

public:
        // Constructor to create a Block with a Record and the previous hash
    Block(std::unique_ptr<Record> rec, const std::string& prevHash);

    void addRecord(Record* record);

    void computeHash();

    //void displayRecords() const;
    
    const std::string& getCurrentHash() const;
    const std::string& getPreviousHash() const;
    const Record* getRecord() const;

    // Move assignment operator
    Block& operator=(Block&& other) noexcept {
        if (this != &other) {
            previousHash = std::move(other.previousHash);
            record = std::move(other.record);
            blockHash = std::move(other.blockHash);
            // Mutex remains in place
        }
        return *this;
    }

    // Move constructor
    Block(Block&& other) noexcept : previousHash(std::move(other.previousHash))
        , record(std::move(other.record))
        , blockHash(std::move(other.blockHash)) {
        // Mutex can't be moved, but it's okay as it's default constructed
    }

        // Delete copy constructor and assignment operator
    Block(const Block&) = delete;
    Block& operator=(const Block&) = delete;
};

#endif