#ifndef PATIENT_INCLUDED
#define PATIENT_INCLUDED

#include "../Base/User.h"


class Patient : public User {
public:
    Patient(const std::string& id, const std::string& userName);
    void accessRecord(const Record* record) const override;
    void asyncDisplay(const Record* record) const override;
    virtual ~Patient() override = default;
};

#endif