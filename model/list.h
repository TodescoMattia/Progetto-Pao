#ifndef LIST_H
#define LIST_H
#include <iostream>

/* DA CANCELLARE ALLA FINE
 * - costruttore    //TODO
 *
 * - Iterator    //TODO
 *      - operator*() con ritorno T&    //TODO
 *
 * - const_Iterator     //TODO
 *
 * - size_type (rappresenta la distanza tra due Iteratori)    //TODO
 *
 * - List(const T &t) {} costruttore di copia    //ok
 *
 * - T& operator=(const T&) ridefinizione assegnazione    //TODO
 *
 * - ~List    //TODO
 *
 * - bool empty     //TODO
 *
 * - size_type size() ritorna la dimensione del contenitore    //TODO
 * - size_type max size() ritorna la massima dimensione del contenitore //TODO
 *
 * - operator==    //TODO
 * - operator<    //TODO
 *
 * - Iterator begin()    //ok
 * - Iterator end()    //ok
 *
 * - Iterator& operator++()    //TODO
 * - Iterator& operator++(int)    //TODO
 *
 * - Iterator& operator--()    //TODO
 * - Iterator& operator--(int)    //TODO
 *
 * - List(n,t) contenitore con n copie di t    //TODO
 * - List(n) contenitore con n elementi di default    //TODO
 *
 * - insert(x,t) inserisce t nel posto x,
 * ritorna l'Iteratore all'elemento inserito    //TODO
 * - insert(it, n, t) inserisce n copie di t nelle posizioni prima di it //TODO
 *
 * - erase(it)  rimuove l'elemento puntato da it    //TODO
 * - erase(it, it) distrugge l'intervallo tra i due it e
 * ritorna l'it successivo      //TODO
 *
 * - clear() rimuove tutti gli elementi    //TODO
 *
 * - push_back(t) inserisce in coda    //TODO
 * - push_front(t) inserisce in testa    //ok
 *
 * - pop_back() rimuove in coda    //TODO
 * - pop_front() rimuove in testa    //TODO
 *

*/

template <class T> class List {
private:
  class Node {
  public:
    T info;
    Node *next;
    Node() : next(0) {}
    Node(const T &t, Node *n = 0) : info(t), next(n) {}
  };
  Node *first; // puntatore al primo Node della lista
  // lista vuota IFF first == nullptr

  static Node *copy(Node *src) {
    if (src) {
      Node *fst = new Node(src->info, src->next);
      Node *fst_sc = fst;
      Node *src_sc = src->next;
      while (src_sc != nullptr) {
        fst_sc->next = new Node(src_sc->info, src_sc->next);
        fst_sc = fst_sc->next;
        src_sc = src_sc->next;
      }
      return fst;
    } else { // lista vuota
      return nullptr;
    }
  }

public:
  // Costruttore
  List() : first(0) {}

  // Costruttore di copia
  List(const List &l) : first(copy(l.first)) {}

  void push_front(const T &t) { first = new Node(t, first); }

  class Iterator {
    friend class List<T>;

  private:
    Node *ptr;
    bool pastTheEnd;

    Iterator(Node *p, bool pte = false) : ptr(p), pastTheEnd(pte) {}

  public:
    Iterator() : ptr(nullptr), pastTheEnd(false) {}

    T &operator*() const { return ptr->info; }

    T *operator->() const { return &(ptr->info); }

    Iterator &operator++() {
      if (ptr != nullptr) {
        if (!pastTheEnd) {
          if (ptr->next == nullptr) {
            ++ptr;
            pastTheEnd = true;
          } else {
            ptr = ptr->next;
          }
        }
      }
      return *this;
    }

    bool operator!=(const Iterator &x) const { return ptr != x.ptr; }
  };

  Iterator begin() const { return Iterator(first); }

  Iterator end() const {
    if (first == nullptr)
      return nullptr;
    else {
      Node *last = first;
      while (last->next != nullptr) {
        last = last->next;
      }
      return Iterator(last + 1, true);
    }
  }
};

#endif
