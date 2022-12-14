#ifndef BOARDGAME
#define BOARDGAME
#include "item.h"

class BoardGame : public Item {
private:
  std::string bgameGenre;
  unsigned int playerNumber;

public:
  // Costruttore
  BoardGame(std::string id, std::string tit = "", bool state = false,
            std::string gen = "", unsigned int player = 0);
};

#endif