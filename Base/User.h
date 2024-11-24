#ifndef USER_INCLUDED
#define USER_INCLUDED

#include "Record.h"

class User {
protected:
    std::string userId;
    std::string name;

public:
    User(const std::string& id, const std::string& userName) : userId(id), name(userName) {};
    virtual void accessRecord(const Record* record) const = 0;
    virtual ~User() = default;
    virtual void asyncDisplay(const Record* record) const = 0;
};

#endif