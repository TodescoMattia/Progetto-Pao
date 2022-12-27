#include "user.h"

// Costruttore
User::User(std::string name, std::string surname, int num)
    : name(name), surname(surname), number(num) {}

// Getter

std::string User::getName() const { return name; }
std::string User::getSurname() const { return surname; }

// Setter

void User::setName(std::string NewName) { name = NewName; }
void User::setSurname(std::string NewSurname) { surname = NewSurname; }
void User::setNumber(int newNumber) { number = newNumber; }

// Metodi
void User::print() const {
  std::cout << name;
  std::cout << surname;
}