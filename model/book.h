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
  Genre getBookGenre() const;

  // Setter

  void setAuthor(std::string newAuthor);
  void setPageNumber(unsigned int newPageNumber);
  void setBookGenre(Genre newGenre);

  virtual void accept(Visitor &visitor) override;

  Book *clone() const override;
};

#endif
