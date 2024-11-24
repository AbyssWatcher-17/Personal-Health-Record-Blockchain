#ifndef BLOCKCHAIN_INCLUDED
#define BLOCKCHAIN_INCLUDED

#include "Block.h"
#include <list>

class Blockchain {
    std::list<Block> chain;
    mutable std::mutex mtx;

public:
    Blockchain();

    void addBlock(Block& newBlock);

    void displayChain() const;
};

#endif