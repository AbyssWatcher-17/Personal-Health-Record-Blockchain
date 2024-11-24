#ifndef DOCTOR_INCLUDED
#define DOCTOR_INCLUDED

#include "../Base/User.h"
#include "../Base/BlockChain.h"

enum class MedicalSpecialty {
    InternalMedicine,
    Surgery,
    Orthopedics,
    Dermatology,
    // Add more specialties as needed
};

class Doctor : public User {
private:
    MedicalSpecialty specialization;

public:

    Doctor(const std::string& id, const std::string& userName, const MedicalSpecialty& spec);
    virtual ~Doctor() override = default;
    
    void accessRecord(const Record* record) const override; 
    //void saveRecord(const Record* record);
    void saveRecordAsync(std::unique_ptr<Record> record, Blockchain& blockchain);
    void asyncDisplay(const Record* record) const override;
    const char* getSpecialtyName(MedicalSpecialty specialty);
    std::string getName() const override;
    

};




#endif