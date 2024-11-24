#ifndef BLOCK_INCLUDED
#define BLOCK_INCLUDED

#include <vector>
#include <functional>
#include <mutex>
#include <thread>
#include "Record.h"

class Block {
    std::string previousHash;
    std::vector<Record*> records;
    std::string blockHash;
    mutable std::mutex mtx;

public:
    Block(const std::string& prevHash);

    void addRecord(Record* record);

    void computeHash();

    void displayRecords() const;

    // Move assignment operator
    Block& operator=(Block&& other) noexcept {
        if (this != &other) {
            previousHash = std::move(other.previousHash);
            records = std::move(other.records);
            blockHash = std::move(other.blockHash);
            // Mutex remains in place
        }
        return *this;
    }

    // Move constructor
    Block(Block&& other) noexcept : previousHash(std::move(other.previousHash))
        , records(std::move(other.records))
        , blockHash(std::move(other.blockHash)) {
        // Mutex can't be moved, but it's okay as it's default constructed
    }

        // Delete copy constructor and assignment operator
    Block(const Block&) = delete;
    Block& operator=(const Block&) = delete;
};

#endif