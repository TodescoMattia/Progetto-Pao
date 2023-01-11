#include <iostream>
using namespace std;
#include "book.h"
#include "film.h"
#include "genre.h"

int main() {
  Book a("123AB6", "titoloLibro", false, "NomeAutore", 152, Fantasy);
  cout << a.getId();
  cout << a.getTitle();
  cout << a.getState();
  cout << a.getAuthor();
  cout << a.getPageNumber();
  cout << a.getGenre();

  Item f("235sdde", "Harry Potter", false);
  f.print();
  cout << "\n";
  a.print();

  Item *ptr = &a;
  ptr->print();

  Film r("123AB6", "titoloFilm", false, "NomeDirettore", 65, Fantasy);
  r.print();
}