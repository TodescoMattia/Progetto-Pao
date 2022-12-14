#ifndef BOOK
#define BOOK
#include "item.h"

class Book : public Item {
private:
  std::string author;
  unsigned int pageNumber;
  std::string bookGenre;

public:
  // Costruttore
  Book(std::string id, std::string tit = "", bool state = false,
       std::string aut = "", unsigned int pag = 0, std::string gen = "");

  // Getter
  std::string getAuthor() const;
  unsigned int getPageNumber() const;
  std::string getGenre() const;

  // Metodi
  virtual void print() const; // overriding di Item::print()
};

#endif