#include <iostream>
#include "AddressBook.h"

int main() {
    AddressBook addressBook;

    addressBook.addContact(new Friend("Ion Popescu", "1990-05-15", "0123456789", "Str. Principala 123"));
    addressBook.addContact(new Friend("Ioana Popescu", "1991-04-25", "0123456780", "Str. Principala 234"));
    addressBook.addContact(new Acquaintance("Andreea Ionescu", "0987654321"));
    addressBook.addContact(new Acquaintance("Marius Neagu", "0987653421"));
    addressBook.addContact(new Colleague("Alex Georgescu", "0456789123", "Info Inc.", "Str. Unirii 456"));

    std::cout << "Cautare - 'Ion Popescu'..." << "\n";
    Contact* contact = addressBook.searchByName("Ion Popescu");
    if (contact)
        std::cout << "Am gasit: " << contact->getName() << "\n";
    else
        std::cout << "Contactul nu a fost gasit!" << "\n";

    std::cout << "Prieteni:" << std::endl;
    std::vector<Friend*> friends = addressBook.getFriends();
    for (Friend* f : friends)
        std::cout << f->getName() << "\n";

    std::cout << "Stergere - 'Andreea Ionescu'..." << "\n";
    if (addressBook.deleteContact("Andreea Ionescu"))
        std::cout << "Contact sters cu succes - Andreea Ionescu." << "\n";
    else
        std::cout << "Contactul nu a fost gasit!" << "\n";

    return 0;
}
