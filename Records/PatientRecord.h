
#include "../Base/Record.h"

class PatientRecord : public Record {
    std::string patientId;
    std::string medicalHistory;

public:
    PatientRecord(const std::string& id, const std::string& pId, const std::string& history);

    void display() const override;
    //void asyncDisplay(const Record* record) override; 
    virtual ~PatientRecord() override = default;
};