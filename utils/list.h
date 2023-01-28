#ifndef LIST_H
#define LIST_H
#include <iostream>

/* DA CANCELLARE ALLA FINE
 * - costruttore    //ok
 *
 * - Iterator    //ok
 *      - operator*() con ritorno T&    //ok
 *
 * - const_Iterator     //ok
 *
 * - size_type (rappresenta la distanza tra due Iteratori)    //TODO
 *
 * - List(const T &t) {} costruttore di copia    //ok
 *
 * - T& operator=(const T&) ridefinizione assegnazione    //ok
 *
 * - ~List    //ok
 *
 * - bool empty     //ok
 *
 * - size_type size() ritorna la dimensione del contenitore    //TODO
 * - size_type max size() ritorna la massima dimensione del contenitore //TODO
 *
 * - operator==    //ok
 * - operator<    //TODO
 *
 * - Iterator begin()    //ok
 * - Iterator end()    //ok
 *
 * - Iterator& operator++()    //ok
 * - Iterator& operator++(int)    //ok
 *
 * - Iterator& operator--()    //ok
 * - Iterator& operator--(int)    //ok
 *
 * - List(n,t) contenitore con n copie di t    //TODO
 * - List(n) contenitore con n elementi di default    //TODO
 *
 * - insert(x,t) inserisce t nel posto x,
 * ritorna l'Iteratore all'elemento inserito    //TODO
 * - insert(it, n, t) inserisce n copie di t nelle posizioni prima di it //TODO
 *
 * - erase(it)  rimuove l'elemento puntato da it    //ok
 * - erase(it, it) distrugge l'intervallo tra i due it e
 * ritorna l'it successivo      //TODO
 *
 * - clear() rimuove tutti gli elementi    //ok
 *
 * - push_back(t) inserisce in coda    //ok
 * - push_front(t) inserisce in testa    //ok
 *
 * - pop_back() rimuove in coda    //ok
 * - pop_front() rimuove in testa    //ok
 *

*/

template <class T> class List {
private:
  class Node {
  public:
    T info;
    Node *prev, *next;
    Node() : next(0) {}
    Node(const T &t, Node *p = 0, Node *n = 0) : info(t), prev(p), next(n) {}
  };
  Node *first, *last; // lista vuota IFF first == last == nullptr

  // Copia profonda

  static void copy(Node *src, Node *&first, Node *&last) {
    if (src) {
      first = last = new Node(src->info);
      Node *it = src->next;
      while (it != nullptr) {
        last = new Node(it->info, last);
        last->prev->next = last;
        it = it->next;
      }
    } else { // lista vuota
      first = last = nullptr;
    }
  }

  // Distruzione profonda

  static void destroy(Node *n) {
    if (n != nullptr) {
      destroy(n->next);
      delete n;
    }
  }

public:
  // Costruttore

  List() : first(0), last(0) {}

  // Costruttore di copia

  List(const List &l) { copy(l.first, first, last); }

  // Distruttore

  ~List() { destroy(first); }

  // Operatore di assegnazione

  List &operator=(const List &l) {
    if (this != &l) {
      destroy(first);
      copy(l.first, first, last);
    }
    return *this;
  }

  void clear() {
    destroy(first);
    first = nullptr;
    last = nullptr;
  }

  void push_front(const T &t) {
    first = new Node(t, nullptr, first);
    if (first->next == nullptr) { // lista invocazione vuota
      last = first;
    } else { // lista invocazione non vuota
      (first->next)->prev = first;
    }
  }

  void push_back(const T &t) {
    last = new Node(t, last, nullptr);
    if (last->prev == nullptr) { // lista invocazione vuota
      first = last;
    } else { // lista invocazione non vuota
      (last->prev)->next = last;
    }
  }

  void pop_front() {
    if (first) {
      if (first == last) { // unico nodo
        delete first;
        first = last = nullptr;
      } else { // più di un nodo
        Node *ptr = first->next;
        delete first;
        first = ptr;
        first->prev = nullptr;
      }
    }
  }

  void pop_back() {
    if (last) {
      if (first == last) { // unico nodo
        delete last;
        first = last = nullptr;
      } else { // più di un nodo
        Node *ptr = last->prev;
        delete last;
        last = ptr;
        last->next = nullptr;
      }
    }
  }

  bool empty() { return first == nullptr && last == nullptr; }

  class Iterator {
    friend class List<T>;

  private:
    Node *ptr;
    bool pastTheEnd;

    Iterator(Node *p, bool pte = false) : ptr(p), pastTheEnd(pte) {}

  public:
    // Costruttore

    Iterator() : ptr(nullptr), pastTheEnd(false) {}

    Iterator &operator++() {
      if (ptr != nullptr) {
        if (!pastTheEnd) {
          if (ptr->next == nullptr) {
            ptr++;
            pastTheEnd = true;
          } else {
            ptr = ptr->next;
          }
        }
      }
      return *this;
    }

    Iterator &operator--() {
      if (ptr != nullptr) {
        if (ptr->prev == nullptr)
          ptr = nullptr;
        else if (!pastTheEnd)
          ptr = ptr->prev;
        else {
          ptr = ptr - 1;
          pastTheEnd = false;
        }
      }
      return *this;
    }

    Iterator operator++(int) {
      Iterator aux(*this);
      ++(*this);
      return aux;
    }

    Iterator operator--(int) {
      Iterator aux(*this);
      --(*this);
      return aux;
    }

    T &operator*() { return ptr->info; }
    T *operator->() { return &(ptr->info); }
    bool operator!=(const Iterator &x) const { return ptr != x.ptr; }
    bool operator==(const Iterator &x) const { return ptr == x.ptr; }
  };

  class CIterator {
    friend class List<T>;

  private:
    const Node *ptr;
    bool pastTheEnd;

    CIterator(const Node *p, bool pte = false) : ptr(p), pastTheEnd(pte) {}

  public:
    // Costruttore

    CIterator() : ptr(nullptr), pastTheEnd(false) {}

    CIterator &operator++() {
      if (ptr != nullptr) {
        if (!pastTheEnd) {
          if (ptr->next == nullptr) {
            ptr++;
            pastTheEnd = true;
          } else {
            ptr = ptr->next;
          }
        }
      }
      return *this;
    }

    CIterator &operator--() {
      if (ptr != nullptr) {
        if (ptr->prev == nullptr)
          ptr = nullptr;
        else if (!pastTheEnd)
          ptr = ptr->prev;
        else {
          ptr = ptr - 1;
          pastTheEnd = false;
        }
      }
      return *this;
    }

    CIterator operator++(int) {
      CIterator aux(*this);
      ++(*this);
      return aux;
    }

    CIterator operator--(int) {
      CIterator aux(*this);
      --(*this);
      return aux;
    }

    const T &operator*() const { return ptr->info; }
    const T *operator->() const { return &(ptr->info); }
    bool operator!=(const CIterator &x) const { return ptr != x.ptr; }
    bool operator==(const CIterator &x) const { return ptr == x.ptr; }
  };

  Iterator begin() { return Iterator(first); }

  Iterator end() {
    if (last == nullptr)
      return Iterator();

    return Iterator(last + 1, true);
  }

  CIterator begin() const { return CIterator(first); }

  CIterator end() const {
    if (last == nullptr)
      return CIterator();

    return CIterator(last + 1, true);
  }

  // metodo cancellazione

  void erase(Iterator &it) {
    if (it.ptr) {
      if (!it.pastTheEnd) {
        if (it.ptr == first && it.ptr == last) { // unico nodo
          first = last = nullptr;
          delete it.ptr;
          it.ptr = nullptr;
        } else {                 // più di un nodo
          if (it.ptr == first) { // primo nodo
            first = first->next;
            first->prev = nullptr;
            delete it.ptr;
            it.ptr = nullptr;
          } else if (it.ptr == last) { // ultimo nodo
            last = last->prev;
            last->next = nullptr;
            delete it.ptr;
            it.ptr = last;
          } else { // nodo in mezzo
            Node *tmp = it.ptr->prev;
            it.ptr->next->prev = it.ptr->prev;
            it.ptr->prev->next = it.ptr->next;
            delete it.ptr;
            it.ptr = tmp;
          }
        }
      }
    }
  }

  // metodi ricerca

  bool contains(const T &t) const {
    for (auto it = this->begin(); it != this->end(); it++) {
      if (*it == t) {
        return true;
      }
    }
    return false;
  }

  int find_position(const T &t) const {
    int pos = 0;
    for (auto it = this->begin(); it != this->end(); it++, pos++) {
      if (*it == t) {
        return pos;
      }
    }
    return -1;
  }

  Iterator find_iterator(const T &t) {
    for (auto it = this->begin(); it != this->end(); it++) {
      if (*it == t) {
        return it;
      }
    }
    return this->end();
  }

  CIterator find_iterator(const T &t) const {
    for (auto it = this->begin(); it != this->end(); it++) {
      if (*it == t) {
        return it;
      }
    }
    return this->end();
  }

  // metodi lettura

  T *get_element(int position) {
    for (auto it = this->begin(); it != this->end(); it++, position--) {
      if (position == 0) {
        return &(*it);
      }
    }
    return nullptr;
  }

  const T *get_element(int position) const {
    for (auto it = this->begin(); it != this->end(); it++, position--) {
      if (position == 0) {
        return &(*it);
      }
    }
    return nullptr;
  }
};

template <class T>
// PRE: il tipo T deve disporre dell'operator <<
std::ostream &operator<<(std::ostream &os, const List<T> &list) {
  for (auto it = list.begin(); it != list.end(); it++) {
    os << *it;
  }
  return os;
}

#endif
