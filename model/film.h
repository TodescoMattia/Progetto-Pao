#ifndef FILM
#define FILM
#include "item.h"

class Film : public Item {
private:
  std::string director;
  unsigned int duration;

public:
  // Costruttore
  Film(std::string id, std::string tit = "", bool state = false,
       std::string dir = "", unsigned int dur = 0);
};

#endif