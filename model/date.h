#ifndef DATE
#define DATE
#include <iostream>

class Date {
private:
  unsigned int day;
  unsigned int month;
  unsigned int year;

public:
  // Costruttore
  Date(unsigned int d = 1, unsigned int m = 1, unsigned int y = 1900);

  // Metodi
  bool isBeforeToday() const;
  void print() const;
};

#endif