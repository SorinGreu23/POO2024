#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <vector>
#include "Contact.h"
#include "Friend.h"
#include "Acquaintance.h"
#include "Colleague.h"

class AddressBook {
    std::vector<Contact*> contacts;

public:
    ~AddressBook();
    Contact* searchByName(const std::string& name);
    std::vector<Friend*> getFriends();
    bool deleteContact(const std::string& name);
    bool addContact(Contact* contact);
};

#endif // ADDRESSBOOK_H
