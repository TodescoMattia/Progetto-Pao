#include "book.h"

// Costruttore

Book::Book(std::string id, std::string tit, bool state, std::string aut,
           unsigned int pag, Genre gen)
    : Item(id, tit, state), author(aut), pageNumber(pag), bookGenre(gen) {}

// Getter
std::string Book::getAuthor() const { return author; }
unsigned int Book::getPageNumber() const { return pageNumber; }
Genre Book::getGenre() const { return bookGenre; }

// Setter
std::string Book::setAuthor(std::string NewAuthor) { author = NewAuthor; }
unsigned int Book::setPageNumber(unsigned int NewPageNumber) {
  pageNumber = NewPageNumber;
}
Genre Book::setGenre(Genre NewGenre) { bookGenre = NewGenre; }

// Metodi
void Book::print() const { // overriding di Item::print()
  Item::print();           // invocazione statica di Item::print()
  std::cout << author << pageNumber << bookGenre;
}

void Book::accept(Visitor &visitor) { visitor.visit(*this); }