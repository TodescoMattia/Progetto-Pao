#ifndef LIST_H
#define LIST_H
#include <iostream>

/* DA CANCELLARE ALLA FINE
 * - costruttore    //TODO
 *
 * - iterator    //TODO
 *      - operator*() con ritorno T&    //TODO
 *
 * - const_iterator     //TODO
 *
 * - size_type (rappresenta la distanza tra due iteratori)    //TODO
 *
 * - list(const list&) costruttore di copia    //TODO
 *
 * - list& operator=(const list&) ridefinizione assegnazione    //TODO
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
 * - iterator begin()    //TODO
 * - iterator end()    //TODO
 *
 * - iterator& operator++()    //TODO
 * - iterator& operator++(int)    //TODO
 *
 * - iterator& operator--()    //TODO
 * - iterator& operator--(int)    //TODO
 *
 * - List(n,t) contenitore con n copie di t    //TODO
 * - List(n) contenitore con n elementi di default    //TODO
 *
 * - insert(x,t) inserisce t nel posto x,
 * ritorna l'iteratore all'elemento inserito    //TODO
 * - insert(it, n, t) inserisce n copie di t nelle posizioni prima di it //TODO
 *
 * - erase(it)  rimuove l'elemento puntato da it    //TODO
 * - erase(it, it) distrugge l'intervallo tra i due it e
 * ritorna l'it successivo      //TODO
 *
 * - clear() rimuove tutti gli elementi    //TODO
 *
 * - push_back(t) inserisce in coda    //TODO
 * - push_front(t) inserisce in testa    //TODO
 *
 * - pop_back() rimuove in coda    //TODO
 * - pop_front() rimuove in testa    //TODO
 *

*/

template <class T> class List {
private:
  Node *first; // puntatore al primo Node della lista
  class Node {
  public:
    T info;
    Node *next;
    Node() : next(0) {}
    Node(const T &t, Node *n = 0) : info(t), next(n) {}
  };
  // lista vuota IFF first == nullptr

public:
  // Costruttore
  List() : first(0) {}
};

#endif