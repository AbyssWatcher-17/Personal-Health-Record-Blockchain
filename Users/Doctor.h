#ifndef DOCTOR_INCLUDED
#define DOCTOR_INCLUDED

#include "../Base/User.h"

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
    void saveRecord(const Record* record);
    void asyncDisplay(const Record* record) const override;
    const char* getSpecialtyName(MedicalSpecialty specialty);

};




#endif