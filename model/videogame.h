#ifndef VIDEOGAME_H
#define VIDEOGAME_H
#include "genre.h"
#include "item.h"

class Videogame : public Item {
private:
  Genre vgameGenre;

public:
  // Costruttore

  Videogame(std::string id, std::string tit = "", bool state = false,
            Genre gen = (Genre)0);

  // Getter

  Genre getVGameGenre() const;

  // Setter

  void setVGameGenre(Genre newVGameGenre);

  virtual void accept(Visitor &visitor);

  Videogame * clone() const override;

  // Cancellami

  void print() const;
};

#endif
