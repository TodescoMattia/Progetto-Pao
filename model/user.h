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

  // Getter

  std::string getName() const;
  std::string getSurname() const;

  // Setter

  void setName(std::string NewName);
  void setSurname(std::string NewSurname);

  // Metodi
  void print() const;
};
#endif