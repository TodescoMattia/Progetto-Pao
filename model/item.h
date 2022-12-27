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

  // Distruttore
  virtual ~Item() = 0;

  // Getter
  std::string getId() const;
  std::string getTitle() const;
  bool getState() const;

  // Metodi
  virtual void print() const; // metodo virtuale
};

#endif