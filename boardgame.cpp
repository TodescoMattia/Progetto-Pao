#include "boardgame.h"

// Costruttore
BoardGame::BoardGame(std::string id, std::string tit, bool state,
                     std::string gen, unsigned int player)
    : Item(id, tit, state), bgameGenre(gen), playerNumber(player) {}