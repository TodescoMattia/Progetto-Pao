#include "item.h"

// Costruttore
Item::Item(std::string id, std::string tit, bool state)
    : id(id), title(tit), isLent(state) {}

// Getter
std::string Item::getId() const { return id; }
std::string Item::getTitle() const { return title; }
bool Item::getState() const { return isLent; }

// Metodi
void Item::print() const { std::cout << id << title << isLent; }