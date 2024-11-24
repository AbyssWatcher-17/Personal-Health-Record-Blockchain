
#include "PatientRecord.h"


PatientRecord::PatientRecord(const std::string& id, const std::string& pId, const std::string& history)
    : Record(id), patientId(pId), medicalHistory(history) {}
    
void PatientRecord::display() const {
    std::cout << "Patient Record ID: " << recordId
              << "\nPatient ID: " << patientId
              << "\nHistory: " << medicalHistory
              << "\nTimestamp: " << timestamp;
}