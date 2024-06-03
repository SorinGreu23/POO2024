#ifndef CONTACT_H
#define CONTACT_H

#include <string>

enum class ContactType { Friend, Acquaintance, Colleague };

class Contact {
protected:
    std::string name;

public:
    Contact(const std::string& n);
    virtual ~Contact() = default;
    virtual ContactType getType() const = 0;
    std::string getName() const;
};

#endif // CONTACT_H