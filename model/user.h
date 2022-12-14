#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

class User {
private:
  std::string name;
  std::string surname;

public:
  // Costruttore
  User(std::string name = "", std::string surname = "");

  // Metodi
  void print() const;
};
#endif