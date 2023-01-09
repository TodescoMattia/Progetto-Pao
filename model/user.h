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
  int getNumber() const;

  // Setter

  void setName(std::string newName);
  void setSurname(std::string newSurname);
  void setNumber(int newNumber);

  // Cancellami

  void print() const;
};
#endif