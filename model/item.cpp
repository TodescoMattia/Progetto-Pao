#include "item.h"

// Costruttore

Item::Item(std::string id, std::string tit, bool state)
    : id(id), title(tit), isLent(state) {}

// Distruttore

Item::~Item() {}

// Getter

std::string Item::getId() const { return id; }
std::string Item::getTitle() const { return title; }
bool Item::getState() const { return isLent; }

// Setter

void Item::setId(std::string newId) { id = newId; }
void Item::setTitle(std::string newTitle) { title = newTitle; }
void Item::setState(bool newState) { isLent = newState; }

// Cancellami

void Item::print() const { std::cout << id << title << isLent; }

std::string toString(const bool &state) {
  if (state)
    return "In prestito";
  return "Libero";
}
