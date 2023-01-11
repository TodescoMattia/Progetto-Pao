#include <iostream>
using namespace std;
#include "boardgame.h"
#include "book.h"
#include "bookserie.h"
#include "date.h"
#include "film.h"
#include "genre.h"
#include "item.h"
#include "list.h"
#include "loan.h"
#include "user.h"
#include "videogame.h"

int main() {

  std::cout << "\n";
  std::cout << "Ora stampo Fantasy \n";
  Genre provaGen = Fantasy;
  std::cout << toString(provaGen);

  Book a("123AB6", "titoloLibro", false, "NomeAutore", 152, Fantasy);
  Book b("123AB6", "titoloLibro2", false, "NomeAutore2", 152, Fantasy);
  Book c("123AB6", "titoloLibro3", false, "NomeAutore3", 152, Fantasy);
  Book d("123AB6", "titoloLibro4", false, "NomeAutore4", 152, Fantasy);
  Book e("123AB6", "titoloLibro5", false, "NomeAutore5", 152, Fantasy);
  BookSerie f("123AB6", "titoloLibroSerie", false, "NomeAutore5", 152, Thriller,
              2);
  Videogame g("123AB6", "titoloVideogame", false, Horror);
  Film h("123AB6", "titoloFilm", false, "NomeDirettore", 60, Fantasy);
  BoardGame i("123AB6", "titoloBoardgame", false, Fantasy, 5);
  Book l("123AB6", "titoloLibro6", false, "NomeAutore6", 152, Fantasy);

  /*// Test stampa template
  List<Item *> prova;
  prova.push_front(&a);
  prova.push_front(&b);
  prova.push_front(&c);
  prova.push_front(&d);
  prova.push_front(&e);
  prova.push_front(&f);
  prova.push_front(&g);
  prova.push_front(&h);
  prova.push_front(&i);
  prova.push_front(&l);

  List<Item *>::Iterator inizio = prova.begin();
  (**inizio).print();
  std::cout << "\n";
  (*inizio)->print();
  std::cout << "\n";

  List<Item *>::Iterator fine = prova.end();
  for (; inizio != fine; ++inizio) {
    (**inizio).print();
    std::cout << "\n";
  }*/

  /*// Test costruttore copia Item
  List<Item> prova;
  prova.push_front(f);
  prova.push_front(g);
  prova.push_front(h);
  prova.push_front(i);
  prova.push_front(l);
  List<Item> prova2(prova);
  std::cout << "\n";
  std::cout << "Prova 2: \n";

  List<Item>::Iterator inizio2 = prova2.begin();
  List<Item>::Iterator fine2 = prova2.end();

  for (; inizio2 != fine2; ++inizio2) {
    (*inizio2).print();
    std::cout << "\n";
  } //*/

  /*// Test costruttore copia Item*, operator=
  List<Item *> prova;
  prova.push_front(&f);
  prova.push_front(&g);
  prova.push_front(&h);
  prova.push_front(&i);
  prova.push_front(&l);

  std::cout << "\n";
  std::cout << "Prova: \n";
  List<Item *>::Iterator inizio = prova.begin();
  List<Item *>::Iterator fine = prova.end();
  for (; inizio != fine; ++inizio) {
    (**inizio).print();
    std::cout << "\n";
    std::cout << "Dentro";
  }

  std::cout << "\n";
  std::cout << "Prova 2: \n";
  List<Item *> prova2(prova);
  List<Item *> prova3 = prova;

  List<Item *>::Iterator inizio2 = prova2.begin();
  List<Item *>::Iterator fine2 = prova2.end();

  for (inizio2 = prova2.begin(); inizio2 != fine2; ++inizio2) {
    (**inizio2).print();
    std::cout << "\n";
  }
  List<Item *>::Iterator inizio3 = prova3.begin();
  List<Item *>::Iterator fine3 = prova3.end();

  for (inizio3 = prova3.begin(); inizio3 != fine3; ++inizio3) {
    (**inizio3).print();
    std::cout << "\n";
  } //*/

  /*// Test prove is Empty, delete

  std::cout << "\n"
            << "isEmpy: ";
  cout << prova.empty();

  std::cout << "\n"
            << "isEmpy: ";
  List<Item *> prova3;
  cout << prova3.empty();

  List<Item *> *prova4 = &prova2;
  List<Item *> *prova5 = prova4;
  delete[] prova4;

  (**(*prova5).begin()).print();

  prova2.push_front(&h);
  prova2.push_front(&i);

  std::cout << "\n";
  for (inizio2 = (*prova5).begin(); inizio2 != fine2; ++inizio2) {
    (**inizio2).print();
    std::cout << "\n";
  }

  delete &prova2;

  prova2.push_front(&h);
  prova2.push_front(&i);
  std::cout << "\n";
  for (inizio2 = prova2.begin(); inizio2 != fine2; ++inizio2) {
    (**inizio2).print();
    std::cout << "\n";
  } //*/

  // Test erase
  List<Item *> prova;
  prova.push_front(&f);
  prova.push_front(&g);
  prova.push_front(&h);
  prova.push_front(&i);
  prova.push_front(&l);

  std::cout << "\n";
  std::cout << "Prova: \n";
  List<Item *>::Iterator inizio = prova.begin();
  List<Item *>::Iterator fine = prova.end();
  for (; inizio != fine; ++inizio) {
    (**inizio).print();
    std::cout << "\n";
  }

  std::cout << "\n";
  std::cout << "Prova2 cancello nodo random: \n";
  List<Item *> prova2(prova);

  List<Item *>::Iterator inizio2 = prova2.begin();
  List<Item *>::Iterator fine2 = prova2.end();

  prova2.erase(++inizio2);
  std::cout << "\n Nodo precedente: ";
  (**inizio2).print();
  std::cout << "\n";

  for (inizio2 = prova2.begin(); inizio2 != fine2; ++inizio2) {
    (**inizio2).print();
    std::cout << "\n";
  }
  std::cout << "\n";
  g.print();
  std::cout << "\n";

  std::cout << "\n";
  std::cout << "Prova 3 cancello primo nodo: \n";
  List<Item *> prova3 = prova;
  List<Item *>::Iterator inizio3 = prova3.begin();
  List<Item *>::Iterator fine3 = prova3.end();

  prova3.erase(inizio3);
  std::cout << "\n Nodo precedente: "; // nullptr
  std::cout << "\n";

  for (inizio3 = prova3.begin(); inizio3 != fine3; ++inizio3) {
    (**inizio3).print();
    std::cout << "\n";
  }

  std::cout << "\n";
  std::cout << "Prova 4 cancello ultimo nodo: \n";
  List<Item *> prova4 = prova;
  List<Item *>::Iterator inizio4 = prova4.begin();
  List<Item *>::Iterator fine4 = prova4.end();
  prova4.erase(--fine4);
  std::cout << "\n Nodo precedente: ";
  (**fine4).print();
  std::cout << "\n";

  for (inizio4 = prova4.begin(), fine4 = prova4.end(); inizio4 != fine4;
       ++inizio4) {
    (**inizio4).print();
    std::cout << "\n";
  }

  List<Item *> prova5;
  prova5.push_front(&f);
  List<Item *>::Iterator inizio5 = prova5.begin();
  List<Item *>::Iterator fine5;
  prova5.erase(inizio5);

  std::cout << "\n";
  std::cout << "Solo un nodo: \n";
  for (inizio5 = prova5.begin(), fine5 = prova5.end(); inizio5 != fine5;
       ++inizio5) {
    (**inizio5).print();
    std::cout << "\n";
  }

  std::cout << "Ok fine\n";

  //*/

  /*// Test erase2
  List<Book> prova;
  prova.push_back(a);
  prova.push_back(b);
  prova.push_back(c);
  prova.push_back(d);
  prova.push_back(e);

  List<Book>::Iterator inizio1 = prova.begin();

  prova.erase(inizio1);

  List<Book> prova2(prova);
  std::cout << "\n";
  std::cout << "Prova: \n";

  List<Book>::Iterator inizio2 = prova2.begin();
  List<Book>::Iterator fine2 = prova2.end();

  for (; inizio2 != fine2; ++inizio2) {
    (*inizio2).print();
    std::cout << "\n";
  }
  std::cout << "\n";
  e.print();
  std::cout << "\n";
  Book *ptr = &e;
  delete ptr;
  std::cout << "\n";
  e.print();
  std::cout << "\n";
  //*/

  /*// Test pop

  List<Book> prova;
  prova.push_back(a);
  prova.push_back(b);
  prova.push_back(c);
  prova.push_back(d);
  prova.push_back(e);

  List<Book>::Iterator inizio1 = prova.begin();

  List<Book> prova2(prova);
  std::cout << "\n";
  std::cout << "Prova2: \n";

  List<Book>::Iterator inizio2 = prova2.begin();
  List<Book>::Iterator fine2 = prova2.end();

  for (inizio2 = prova2.begin(); inizio2 != fine2; inizio2++) {
    (*inizio2).print();
    std::cout << "\n";
  }
  std::cout << "\n";
  std::cout << "Pop back:\n";
  prova2.pop_back();

  for (inizio2 = prova2.begin(), fine2 = prova2.end(); inizio2 != fine2;
       ++inizio2) {
    (*inizio2).print();
    std::cout << "\n";
    std::cout << "Piango \n";
  }
  std::cout << "\n";
  std::cout << "Fine \n";
  //*/
}