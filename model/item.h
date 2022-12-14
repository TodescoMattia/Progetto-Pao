#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <string>

class Item {
private:
  std::string id;
  std::string title;
  bool isLent;

public:
  // Costruttore
  Item(std::string id = "", std::string tit = "", bool state = 0);
  //~Item();

  // Getter
  std::string getId() const;
  std::string getTitle() const;
  bool getState() const;

  // Metodi
  virtual void print() const; // metodo virtuale
  // virtual void create();
  // virtual void edit();
  // virtual void delete();
};

#endif