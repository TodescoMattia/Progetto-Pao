#include "boardgame.h"

// Costruttore
BoardGame::BoardGame(std::string id, std::string tit, bool state, Genre gen,
                     unsigned int player)
    : Item(id, tit, state), bgameGenre(gen), playerNumber(player) {}

// Metodi
void BoardGame::print() const {
  Item::print();
  std::cout << bgameGenre << playerNumber;
}