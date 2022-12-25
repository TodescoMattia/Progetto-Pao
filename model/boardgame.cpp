#include "boardgame.h"

// Costruttore
BoardGame::BoardGame(std::string id, std::string tit, bool state, Genre gen,
                     unsigned int player)
    : Item(id, tit, state), bgameGenre(gen), playerNumber(player) {}

//Getter

Genre BoardGame::getBGameGenre() const {return bgameGenre;}
unsigned int BoardGame::getPlayerNumber() const {return playerNumber;}

//Setter

Genre BoardGame::setBGameGenre(Genre NewGameGenre) {bgameGenre=NewGameGenre;}
unsigned int BoardGame::setPlayerNumber(unsigned int NewPlayerNumber) {playerNumber=NewPlayerNumber;}

// Metodi

void BoardGame::print() const {
  Item::print();
  std::cout << bgameGenre << playerNumber;
}




