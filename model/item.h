#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

#include "Visitor.h"

class Item {
private:
  std::string id;
  std::string title;
  bool isLent;

public:
  // Costruttore

  Item(std::string id = "", std::string tit = "", bool state = 0);

  // Distruttore

  virtual ~Item() = 0;

  // Getter

  std::string getId() const;
  std::string getTitle() const;
  bool getState() const;

  // Setter

  void setId(std::string newId);
  void setTitle(std::string newTitle);
  void setState(bool newState);

  virtual void accept(Visitor &visitor) = 0;

  // Cancellami

  virtual void print() const; // metodo virtuale
};

std::string toString(const bool &state);
#endif
