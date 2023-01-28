#include "boardgame.h"

// Costruttore
BoardGame::BoardGame(std::string id, std::string tit, bool state, Genre gen,
                     unsigned int player)
    : Item(id, tit, state), bgameGenre(gen), playerNumber(player) {}

// Getter

Genre BoardGame::getBGameGenre() const { return bgameGenre; }
unsigned int BoardGame::getPlayerNumber() const { return playerNumber; }

// Setter

void BoardGame::setBGameGenre(Genre newGameGenre) { bgameGenre = newGameGenre; }
void BoardGame::setPlayerNumber(unsigned int newPlayerNumber) {
  playerNumber = newPlayerNumber;
}

void BoardGame::accept(Visitor &visitor) { visitor.visit(this); }

BoardGame* BoardGame::clone() const {
    return new BoardGame(*this);
}


// Cancellami

void BoardGame::print() const {
  Item::print();
  std::cout << bgameGenre << playerNumber;
}
