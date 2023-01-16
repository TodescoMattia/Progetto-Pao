#ifndef GENRE_H
#define GENRE_H
#include <ostream>

enum Genre { Fantasy, Horror, Romance, Comedy, Thriller };

std::string toString(const Genre &g);

std::ostream &operator<<(std::ostream &os, const Genre &g);

Genre toGenre(int num = 0);
#endif

// overloading operatore di =?