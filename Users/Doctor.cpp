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

    void Doctor::saveRecord(const Record* record)
    {
    if (record) {
        std::cout << "Doctor " << name << " saving record\n";
    }
    }

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

