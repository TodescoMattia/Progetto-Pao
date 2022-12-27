#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>

class User {
private:
  std::string name;
  std::string surname;
  int number;

public:
  // Costruttore
  User(std::string name = "", std::string surname = "", int num = 0);

  // Getter

  std::string getName() const;
  std::string getSurname() const;

  // Setter

  void setName(std::string NewName);
  void setSurname(std::string NewSurname);
  void setNumber(int NewNumber);

  // Metodi
  void print() const;
};
#endif