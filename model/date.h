#ifndef DATE_H
#define DATE_H
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

  // Getter

  unsigned int getDay() const;
  unsigned int getMonth() const;
  unsigned int getYear() const;

  // Setter

  void setDay(unsigned int newDay);
  void setMonth(unsigned int newMonth);
  void setYear(unsigned int newYear);

  // Cancellami

  void print() const;
};

std::string toString(const Date &date);

#endif