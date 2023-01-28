#include "book.h"

// Costruttore

Book::Book(std::string id, std::string tit, bool state, std::string aut,
           unsigned int pag, Genre gen)
    : Item(id, tit, state), author(aut), pageNumber(pag), bookGenre(gen) {}

// Getter

std::string Book::getAuthor() const { return author; }
unsigned int Book::getPageNumber() const { return pageNumber; }
Genre Book::getBookGenre() const { return bookGenre; }

// Setter

void Book::setAuthor(std::string newAuthor) { author = newAuthor; }
void Book::setPageNumber(unsigned int newPageNumber) {
  pageNumber = newPageNumber;
}
void Book::setBookGenre(Genre newGenre) { bookGenre = newGenre; }

void Book::accept(Visitor &visitor) { visitor.visit(this); }

Book* Book::clone() const {
    return new Book(*this);
}


// Cancellami

void Book::print() const { // overriding di Item::print()
  Item::print();           // invocazione statica di Item::print()
  std::cout << author << pageNumber << bookGenre;
}
