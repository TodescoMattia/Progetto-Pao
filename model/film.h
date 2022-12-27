#ifndef FILM_H
#define FILM_H
#include "genre.h"
#include "item.h"

class Film : public Item {
private:
  std::string director;
  unsigned int duration;
  Genre filmGenre;

public:
  // Costruttore
  Film(std::string id, std::string tit = "", bool state = false,
       std::string dir = "", unsigned int dur = 0, Genre gen = (Genre)0);

  // Metodi
  void print() const;

  // getter

  std::string getDirector() const;
  unsigned int getDuration() const;
  Genre getFilmGenre() const;

  // setter

  void setDirector(std::string NewDirector);
  void setDuration(unsigned int NewDuration);
  void setFilmGenre(Genre NewFilmGenre);

  virtual void accept(Visitor &visitor);
};

#endif