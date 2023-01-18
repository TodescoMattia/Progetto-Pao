#ifndef VISITOR_H
#define VISITOR_H

class Book;
class BookSerie;
class Film;
class BoardGame;
class Videogame;

class Visitor {
public:
  virtual ~Visitor(){};
  virtual void visit(Book *book) = 0;
  virtual void visit(BookSerie *bookSerie) = 0;
  virtual void visit(Film *film) = 0;
  virtual void visit(BoardGame *boardGame) = 0;
  virtual void visit(Videogame *videogame) = 0;
};

#endif
