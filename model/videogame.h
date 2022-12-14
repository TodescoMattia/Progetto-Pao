#ifndef VIDEOGAME
#define VIDEOGAME
#include "genre.h"
#include "item.h"

class Videogame : public Item {
private:
  Genre vgameGenre;

public:
  // Costruttore
  Videogame(std::string id, std::string tit = "", bool state = false,
            Genre gen = (Genre)0);

  // Metodi
  void print() const;
};

#endif