#include "user.h"

// Costruttore

User::User(std::string name, std::string surname, std::string num)
    : name(name), surname(surname), number(num) {}

// Getter

std::string User::getName() const { return name; }
std::string User::getSurname() const { return surname; }
std::string User::getNumber() const { return number; }

// Setter

void User::setName(std::string newName) { name = newName; }
void User::setSurname(std::string newSurname) { surname = newSurname; }
void User::setNumber(std::string newNumber) { number = newNumber; }

User* User::clone() const {
    return new User(*this);
}


// Cancellami

void User::print() const {
  std::cout << name;
  std::cout << surname;
}
