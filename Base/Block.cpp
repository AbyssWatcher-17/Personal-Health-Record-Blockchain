#include "Block.h"
#include <iostream>
#include <utility> // For std::move

// Constructor to initialize a Block with a record and previous hash
Block::Block(std::unique_ptr<Record> rec, const std::string& prevHash)
    : record(std::move(rec)), previousHash(prevHash), currentHash(calculateHash()) {}

// Calculate a simple hash for demonstration purposes
std::string Block::calculateHash() const {
    // Simplified hash calculation for demonstration
    return previousHash + (record ? record->getId() : "");
}

const std::string& Block::getPreviousHash() const {
    return previousHash;
}

const std::string& Block::getCurrentHash() const {
    return currentHash;
}

const Record* Block::getRecord() const {
    record->display();
    return record.get();
}
