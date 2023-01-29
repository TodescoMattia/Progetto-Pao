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

  // Getter

  std::string getDirector() const;
  unsigned int getDuration() const;
  Genre getFilmGenre() const;

  // Setter

  void setDirector(std::string newDirector);
  void setDuration(unsigned int newDuration);
  void setFilmGenre(Genre newFilmGenre);

  virtual void accept(Visitor &visitor);

  Film *clone() const override;
};

#endif
