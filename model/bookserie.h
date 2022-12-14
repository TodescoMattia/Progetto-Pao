#ifndef BOOKSERIE
#define BOOKSERIE
#include "book.h"

class BookSerie : public Book {
private:
  unsigned int volumeNumber;

public:
  // Costruttore
  BookSerie(std::string id, std::string tit = "", bool state = false,
            std::string aut = "", unsigned int pag = 0, std::string gen = "",
            unsigned int vol = 0);
};

#endif