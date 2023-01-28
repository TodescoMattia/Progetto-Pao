#ifndef USER_H
#define USER_H
#include <iostream>
#include <string>
#include "../utils/clonable.h"

class User: public Clonable {
private:
  std::string name;
  std::string surname;
  std::string number;

public:
  // Costruttore

  User(std::string name = "", std::string surname = "", std::string num = "0");

  // Getter

  std::string getName() const;
  std::string getSurname() const;
  std::string getNumber() const;

  // Setter

  void setName(std::string newName);
  void setSurname(std::string newSurname);
  void setNumber(std::string newNumber);

  User* clone() const override;

  // Cancellami

  void print() const;
};
#endif
