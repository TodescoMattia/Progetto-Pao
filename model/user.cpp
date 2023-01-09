#include "user.h"

// Costruttore

User::User(std::string name, std::string surname, int num)
    : name(name), surname(surname), number(num) {}

// Getter

std::string User::getName() const { return name; }
std::string User::getSurname() const { return surname; }
int User::getNumber() const { return number; }

// Setter

void User::setName(std::string newName) { name = newName; }
void User::setSurname(std::string newSurname) { surname = newSurname; }
void User::setNumber(int newNumber) { number = newNumber; }

// Cancellami

void User::print() const {
  std::cout << name;
  std::cout << surname;
}