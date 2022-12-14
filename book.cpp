#include "book.h"

// Costruttore
Book::Book(std::string id, std::string tit, bool state, std::string aut,
           unsigned int pag, std::string gen)
    : Item(id, tit, state), author(aut), pageNumber(pag), bookGenre(gen) {}

// Getter
std::string Book::getAuthor() const { return author; }
unsigned int Book::getPageNumber() const { return pageNumber; }
std::string Book::getGenre() const { return bookGenre; }

// Metodi
void Book::print() const { // overriding di Item::print()
  Item::print();           // invocazione statica di Item::print()
  std::cout << author << pageNumber << bookGenre;
}