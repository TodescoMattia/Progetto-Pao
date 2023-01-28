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

int toInt(const Genre &g) {
  switch (g) {
  case Fantasy:
    return 0;
  case Horror:
    return 1;
  case Romance:
    return 2;
  case Comedy:
    return 3;
  case Thriller:
    return 4;
  default:
    return 0;
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
  default:
    return Fantasy;
  }
}
