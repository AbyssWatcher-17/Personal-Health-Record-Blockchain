#include "BlockChain.h"

#include <mutex>



    Blockchain::Blockchain(): chain() {}

    void Blockchain::addBlock(Block& newBlock) {
        std::lock_guard<std::mutex> lock(mtx);
        //newBlock.calculateHash();
        chain.push_back(std::move(newBlock));
    }

    void Blockchain::displayChain() const {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& block : chain) {
            std::cout <<"\n";
            block.getRecord();
        }
    }

    std::string Blockchain::getLatestBlockHash()
    {
    if (chain.empty()) {
        return "GENESIS"; // Return a placeholder hash for the genesis block
    }
    return chain.back().getCurrentHash();
    } 

    void Blockchain::addBlock(Block&& block) {
    chain.push_back(std::move(block));
    std::cout << "Block added to the blockchain. Current size: " << chain.size() << std::endl;
    }

