#include "../Base/Record.h"


class DoctorRecord : public Record {
    std::string doctorId;
    std::string diagnosis;

public:
    DoctorRecord(const std::string& id, const std::string& dId, const std::string& diag);
    void display() const override;
    //void asyncDisplay(const Record* record) override; 
    virtual ~DoctorRecord() override = default;

    
};