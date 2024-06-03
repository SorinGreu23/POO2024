#ifndef COLLEAGUE_H
#define COLLEAGUE_H

#include "Contact.h"

class Colleague : public Contact {
    std::string phoneNumber;
    std::string company;
    std::string address;

public:
    Colleague(const std::string& n, const std::string& ph, const std::string& comp, const std::string& addr);
    ContactType getType() const override;
};

#endif // COLLEAGUE_H
