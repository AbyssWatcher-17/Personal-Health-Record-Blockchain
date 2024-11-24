#include "BlockChain.h"

#include <mutex>



    Blockchain::Blockchain() {
        // Add genesis block
        chain.emplace_back("0");
    }

    void Blockchain::addBlock(Block& newBlock) {
        std::lock_guard<std::mutex> lock(mtx);
        newBlock.computeHash();
        chain.push_back(std::move(newBlock));
    }

    void Blockchain::displayChain() const {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& block : chain) {
            block.displayRecords();
        }
    }

