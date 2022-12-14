#include "videogame.h"

// Costruttore
Videogame::Videogame(std::string id, std::string tit, bool state,
                     std::string gen)
    : Item(id, tit, state), vgameGenre(gen) {}