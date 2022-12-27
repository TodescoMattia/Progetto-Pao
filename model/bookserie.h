#ifndef BOOKSERIE_H
#define BOOKSERIE_H
#include "book.h"

class BookSerie : public Book {
private:
  unsigned int volumeNumber;

public:
  // Costruttore

  BookSerie(std::string id, std::string tit = "", bool state = false,
            std::string aut = "", unsigned int pag = 0, Genre gen = (Genre)0,
            unsigned int vol = 0);

  // Getter

  unsigned int getVolumeNumber() const;

  // Setter

  void setVolumeNumber(unsigned int newVolumeNumber);

  virtual void accept(Visitor &visitor);

  // Cancellami

  void print() const;
};

#endif