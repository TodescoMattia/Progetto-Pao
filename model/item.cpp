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
void Item::setId(std::string NewId) { id = NewId; }
void Item::setTitle(std::string NewTitle) { title = NewTitle; }
void Item::setState(bool NewState) { isLent = NewState; }

// Metodi
void Item::print() const { std::cout << id << title << isLent; }