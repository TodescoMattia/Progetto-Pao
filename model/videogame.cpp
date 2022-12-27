#include "videogame.h"

// Costruttore
Videogame::Videogame(std::string id, std::string tit, bool state, Genre gen)
    : Item(id, tit, state), vgameGenre(gen) {}

// Getter

Genre Videogame::getVGameGenre() const { return vgameGenre; }

// Setter

void Videogame::setVGameGenre(Genre newVGameGenre) {
  vgameGenre = newVGameGenre;
}

// Metodi
void Videogame::print() const {
  Item::print();
  std::cout << vgameGenre;
}

void Videogame::accept(Visitor &visitor) { visitor.visit(*this); }