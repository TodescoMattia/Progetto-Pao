#include "user.h"

// Costruttore
User::User(std::string name, std::string surname)
    : name(name), surname(surname) {}

// Metodi
void User::print() const {
  std::cout << name;
  std::cout << surname;
}