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

  //Getter

  std::string getName() const;
  std::string getSurname() const;

  //Setter

  std::string setName(std::string NewName);
  std::string setSurname(std::string NewSurname);

  // Metodi
  void print() const;
};
#endif