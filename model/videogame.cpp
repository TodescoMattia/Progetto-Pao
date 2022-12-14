#include "videogame.h"

// Costruttore
Videogame::Videogame(std::string id, std::string tit, bool state, Genre gen)
    : Item(id, tit, state), vgameGenre(gen) {}

// Metodi
void Videogame::print() const {
  Item::print();
  std::cout << vgameGenre;
}