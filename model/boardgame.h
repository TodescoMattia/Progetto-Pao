#ifndef BOARDGAME_H
#define BOARDGAME_H
#include "genre.h"
#include "item.h"

class BoardGame : public Item {
private:
  Genre bgameGenre;
  unsigned int playerNumber;

public:
  // Costruttore

  BoardGame(std::string id, std::string tit = "", bool state = false,
            Genre gen = (Genre)0, unsigned int player = 0);

  // Getter

  Genre getBGameGenre() const;
  unsigned int getPlayerNumber() const;

  // Setter

  void setBGameGenre(Genre newGameGenre);
  void setPlayerNumber(unsigned int newPlayerNumber);

  virtual void accept(Visitor &visitor);

  // Cancellami

  void print() const;
};

#endif