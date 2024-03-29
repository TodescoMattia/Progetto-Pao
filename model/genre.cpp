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

std::string toString(const Genre &g) {
  switch (g) {
  case Fantasy:
    return "Fantasy";
  case Horror:
    return "Horror";
  case Romance:
    return "Romance";
  case Comedy:
    return "Comedy";
  case Thriller:
    return "Thriller";
  default:
    return "(invalid genre)";
  }
}

Genre toGenre(int num) {
  switch (num) {
  case 0:
    return Fantasy;
  case 1:
    return Horror;
  case 2:
    return Romance;
  case 3:
    return Comedy;
  case 4:
    return Thriller;
  }
}
