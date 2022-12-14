#ifndef BOARDGAME
#define BOARDGAME
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

  // Metodi
  void print() const;
};

#endif