#include "film.h"

// Costruttore

Film::Film(std::string id, std::string tit, bool state, std::string dir,
           unsigned int dur, Genre gen)
    : Item(id, tit, state), director(dir), duration(dur), filmGenre(gen) {}

// Getter

std::string Film::getDirector() const { return director; }
unsigned int Film::getDuration() const { return duration; }
Genre Film::getFilmGenre() const { return filmGenre; }

// Setter

void Film::setDirector(std::string newDirector) { director = newDirector; }
void Film::setDuration(unsigned int newDuration) { duration = newDuration; }
void Film::setFilmGenre(Genre newFilmGenre) { filmGenre = newFilmGenre; }

void Film::accept(Visitor &visitor) { visitor.visit(*this); }

// Cancellami

void Film::print() const {
  Item::print();
  std::cout << director << duration << filmGenre;
}
