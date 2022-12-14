#include "film.h"

// Costruttore
Film::Film(std::string id, std::string tit, bool state, std::string dir,
           unsigned int dur)
    : Item(id, tit, state), director(dir), duration(dur) {}