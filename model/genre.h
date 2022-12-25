#ifndef GENRE_H
#define GENRE_H
#include <ostream>

enum Genre { Fantasy, Horror, Romance, Comedy, Thriller };
std::ostream &operator<<(std::ostream &os, const Genre &g);
#endif

//overloading operatore di =?