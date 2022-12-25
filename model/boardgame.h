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

  //getter

Genre getBGameGenre() const;
unsigned int getPlayerNumber() const;

  //setter

Genre setBGameGenre(Genre NewGameGenre);
unsigned int setPlayerNumber(unsigned int NewPlayerNumber);

  // Metodi
  void print() const;
};

#endif