#ifndef BOOK_H
#define BOOK_H
#include "genre.h"
#include "item.h"

class Book : public Item {
private:
  std::string author;
  unsigned int pageNumber;
  Genre bookGenre;

public:
  // Costruttore

  Book(std::string id, std::string tit = "", bool state = false,
       std::string aut = "", unsigned int pag = 0, Genre gen = (Genre)0);

  // Getter

  std::string getAuthor() const;
  unsigned int getPageNumber() const;
  Genre getGenre() const;

  //setter
  
  std::string setAuthor(std::string NewAuthor);
  unsigned int setPageNumber(unsigned int NewPageNumber);
  Genre setGenre(Genre NewGenre);

  // Metodi
  virtual void print() const; // overriding di Item::print()
};

#endif