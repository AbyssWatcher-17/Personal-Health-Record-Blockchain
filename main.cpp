//#include <iostream>

#include "Base/Block.h"
#include "Base/BlockChain.h"
#include "Base/Record.h"
#include "Base/User.h"

#include "Users/Doctor.h"
#include "Users/Patient.h"


int main(int argc, char const *argv[])
{

    std::cout << "Personal Health Record Blockchain\n";
    
    // Create a blockchain
    Blockchain blockchain;
    
    // Create a block
    Block block("0");
    
    // Add the block to the chain
    blockchain.addBlock(block);
    
    std::cout << "Blockchain initialized successfully\n";
    
    return 0;
}
