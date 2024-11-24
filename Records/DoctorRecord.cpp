#include "DoctorRecord.h"

DoctorRecord::DoctorRecord(const std::string& id, const std::string& dId, const std::string& diag)
    : Record(id), doctorId(dId), diagnosis(diag) {}
    
void DoctorRecord::display() const  {
    std::cout << "Doctor Record ID: " << recordId
              << "\nDoctor ID: " << doctorId
              << "\nDiagnosis: " << diagnosis
              << "\nTimestamp: " << timestamp;
}
