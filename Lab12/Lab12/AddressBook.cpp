#include "AddressBook.h"

AddressBook::~AddressBook() {
    for (Contact* c : contacts)
        delete c;
}

Contact* AddressBook::searchByName(const std::string& name) {
    for (Contact* c : contacts)
        if (c->getName() == name)
            return c;
    return nullptr;
}

std::vector<Friend*> AddressBook::getFriends() {
    std::vector<Friend*> friends;
    for (Contact* c : contacts)
        if (c->getType() == ContactType::Friend)
            friends.push_back(static_cast<Friend*>(c));
    return friends;
}

bool AddressBook::deleteContact(const std::string& name) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if ((*it)->getName() == name) {
            delete* it;
            contacts.erase(it);
            return true;
        }
    }
    return false;
}

bool AddressBook::addContact(Contact* contact) {
    contacts.push_back(contact);
    return true;
}
