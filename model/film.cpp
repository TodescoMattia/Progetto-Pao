#include "film.h"

// Costruttore
Film::Film(std::string id, std::string tit, bool state, std::string dir,
           unsigned int dur, Genre gen)
    : Item(id, tit, state), director(dir), duration(dur), filmGenre(gen) {}

// Metodi
void Film::print() const {
  Item::print();
  std::cout << director << duration << filmGenre;
}