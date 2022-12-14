#include "genre.h"

std::ostream &operator<<(std::ostream &os, const Genre &g) {
  switch (g) {
  case Fantasy:
    return os << "Fantasy";
  case Horror:
    return os << "Horror";
  case Romance:
    return os << "Romance";
  case Comedy:
    return os << "Comedy";
  case Thriller:
    return os << "Thriller";
  default:
    return os << "(invalid genre)";
  }
}