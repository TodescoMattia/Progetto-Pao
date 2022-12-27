#include "bookserie.h"

// Costruttore
BookSerie::BookSerie(std::string id, std::string tit, bool state,
                     std::string aut, unsigned int pag, Genre gen,
                     unsigned int vol)
    : Book(id, tit, state, aut, pag, gen), volumeNumber(vol) {}

// getter

unsigned int BookSerie::getVolumeNumber() const { return volumeNumber; }

// setter

void BookSerie::setVolumeNumber(unsigned int NewVolumeNumber) {
  volumeNumber = NewVolumeNumber;
}

// Metodi
void BookSerie::print() const {
  Book::print();
  std::cout << volumeNumber;
}

void BookSerie::accept(Visitor &visitor) { visitor.visit(*this); }
