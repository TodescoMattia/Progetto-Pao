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

  // getter

  Genre getBGameGenre() const;
  unsigned int getPlayerNumber() const;

  // setter

  void setBGameGenre(Genre NewGameGenre);
  void setPlayerNumber(unsigned int NewPlayerNumber);

  // Metodi
  void print() const;

  virtual void accept(Visitor &visitor);
};

#endif