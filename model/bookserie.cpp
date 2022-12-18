#include "bookserie.h"

// Costruttore
BookSerie::BookSerie(std::string id, std::string tit, bool state,
                     std::string aut, unsigned int pag, Genre gen,
                     unsigned int vol)
    : Book(id, tit, state, aut, pag, gen), volumeNumber(vol) {}

// Metodi
void BookSerie::print() const {
  Book::print();
  std::cout << volumeNumber;
}