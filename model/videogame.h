#ifndef VIDEOGAME
#define VIDEOGAME
#include "item.h"

class Videogame : public Item {
private:
  std::string vgameGenre;

public:
  // Costruttore
  Videogame(std::string id, std::string tit = "", bool state = false,
            std::string gen = "");
};

#endif