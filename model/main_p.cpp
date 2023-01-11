#include <iostream>
using namespace std;
#include "book.h"
#include "date.h"
#include "item.h"
#include "loan.h"
#include "user.h"

int main() {
  Book a("123AB6", "titoloLibro", false, "NomeAutore", 152, Fantasy);
  /*cout << a.getId();
  cout << a.getTitle();
  cout << a.getState();
  cout << a.getAuthor();
  cout << a.getPageNumber();
  cout << a.getGenre();*/

  /*Item f("235sdde", "Harry Potter", false);
  f.print();
  cout << "\n";
  a.print();*/

  User utente1("Silvia", "Rovea");
  utente1.print();
  std::cout << "\n";
  Loan prest("5265sd8", 12, 05, 2006, 13, 12, 2022, &utente1, &a);
  prest.print();
  std::cout << "\n";
  Date data1(14, 12, 2022);
  std::cout << "\n";
  std::cout << data1.isBeforeToday();
  std::cout << prest.isExpired();
}