#include "Base/Block.h"
#include "Base/BlockChain.h"
#include "Base/Record.h"
#include "Base/User.h"


#include "Records/DoctorRecord.h"
#include "Records/PatientRecord.h"

#include "Users/Doctor.h"
#include "Users/Patient.h"


int main() {
    // Create blockchain
    Blockchain blockchain;

    std::unique_ptr<Record> genesisRecord = std::make_unique<DoctorRecord>("R0", "System", "Genesis Block");
    Block genesisBlock(std::move(genesisRecord), "GENESIS");
    blockchain.addBlock(std::move(genesisBlock));

    // Create Doctors
    std::vector<std::unique_ptr<Doctor>> doctors;
    doctors.emplace_back(std::make_unique<Doctor>("D123", "Dr. Alice", MedicalSpecialty::InternalMedicine));
    doctors.emplace_back(std::make_unique<Doctor>("D456", "Dr. Bob", MedicalSpecialty::Orthopedics));

    // Create Patients
    std::vector<std::unique_ptr<Patient>> patients;
    patients.emplace_back(std::make_unique<Patient>("P101", "John Doe"));
    patients.emplace_back(std::make_unique<Patient>("P102", "Jane Smith"));
    patients.emplace_back(std::make_unique<Patient>("P103", "Michael Brown"));

    // Associate records with doctors and patients
    std::unique_ptr<Record> record1 = std::make_unique<DoctorRecord>("R1", "D123", "Flu Diagnosis");
    std::unique_ptr<Record> record2 = std::make_unique<PatientRecord>("R2", "P101", "No Prior Illnesses");

    // Save records asynchronously
    doctors[0]->saveRecordAsync(std::move(record1), blockchain);
    doctors[1]->saveRecordAsync(std::move(record2), blockchain);


    std::cout << "\n\n";

    // Display records for each patient asynchronously
    for (const auto& patient : patients) {
        std::cout << "Accessing records for: " << patient->getName() << std::endl;
        blockchain.displayChain(); // Display all blocks in the chain
    }

    // End of the program
    return 0;
}