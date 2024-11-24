#include "../Users/Doctor.h"

    Doctor::Doctor(const std::string& id, const std::string& userName, const MedicalSpecialty& spec) : User(id, userName), specialization(spec)
    {
        std::cout << "Doctor created with specialization: " << getSpecialtyName(spec) << "\n";
    }

    void Doctor::accessRecord(const Record* record) const {
    if (record) {
        std::cout << "Doctor " << name << " accessing record\n";
        record->display();
    }
}

    //chatgpt
    void Doctor::asyncDisplay(const Record* record) const
    {
    std::thread displayThread([record]() {
        record->display();
    });
    displayThread.detach(); // Allow it to run independently
    }

    // void Doctor::saveRecord(const Record* record)
    // {
    //     if (record) {
    //         std::cout << "Doctor " << name << " saving record\n";
    //     }
    // }

    const char* Doctor::getSpecialtyName(MedicalSpecialty specialty) {
        switch (specialty) {
            case MedicalSpecialty::InternalMedicine:
                return "Internal Medicine";
            case MedicalSpecialty::Surgery:
                return "Surgery";
            case MedicalSpecialty::Orthopedics:
                return "Orthopedics";
            case MedicalSpecialty::Dermatology:
                return "Dermatology";
            default:
                return "Unknown Specialty";
        }
    }

    std::string Doctor::getName() const
    {
        return name;
    }

    // void Doctor::saveRecordAsync(std::unique_ptr<Record> record, Blockchain& blockchain) {
    //     std::thread saveThread([this, &blockchain, record = std::move(record)]() mutable {
    //         blockchain.addBlock(std::make_unique<Block>(std::move(record)));
    //         std::cout << "Record saved by: " << getName() << std::endl;
    //     });
    //     saveThread.detach();
    // }


void Doctor::saveRecordAsync(std::unique_ptr<Record> record, Blockchain& blockchain) {
    std::thread saveThread([this, &blockchain, rec = std::move(record)]() mutable {
        Block block(std::move(rec),blockchain.getLatestBlockHash());  // Create a Block object
        blockchain.addBlock(block);  // Pass the Block object directly
        std::cout << "Record saved by: " << getName() << std::endl;
    });
    saveThread.detach();
}
