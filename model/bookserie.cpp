#include "bookserie.h"

// Costruttore

BookSerie::BookSerie(std::string id, std::string tit, bool state,
                     std::string aut, unsigned int pag, Genre gen,
                     unsigned int vol)
    : Book(id, tit, state, aut, pag, gen), volumeNumber(vol) {}

// Getter

unsigned int BookSerie::getVolumeNumber() const { return volumeNumber; }

// Setter

void BookSerie::setVolumeNumber(unsigned int newVolumeNumber) {
  volumeNumber = newVolumeNumber;
}

void BookSerie::accept(Visitor &visitor) { visitor.visit(this); }

BookSerie* BookSerie::clone() const {
    return new BookSerie(*this);
}


// Cancellami

void BookSerie::print() const {
  Book::print();
  std::cout << volumeNumber;
}
