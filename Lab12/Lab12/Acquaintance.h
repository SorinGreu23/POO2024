#ifndef ACQUAINTANCE_H
#define ACQUAINTANCE_H

#include "Contact.h"

class Acquaintance : public Contact {
    std::string phoneNumber;

public:
    Acquaintance(const std::string& n, const std::string& ph);
    ContactType getType() const override;
};

#endif // ACQUAINTANCE_H
