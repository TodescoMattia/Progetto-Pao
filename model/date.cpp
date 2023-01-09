#include "date.h"
#include <sstream>
#include <time.h>

// Costruttore

Date::Date(unsigned int d, unsigned int m, unsigned int y)
    : day((d >= 1 && d <= 31) ? d : 1), month((m >= 1 && m <= 12) ? m : 1),
      year(y) {}

// Metodi

bool Date::isBeforeToday() const {
  time_t today;
  time(&today); // get current time; same as: today = time(NULL)

  struct tm t;
  t.tm_year = year - 1900; // years since 1900
  t.tm_mon = month - 1;    // months since January
  t.tm_mday = day + 1;
  t.tm_hour = 0;
  t.tm_min = 0;
  t.tm_sec = 0;
  t.tm_isdst = -1;

  return mktime(&t) < today; // mktime convert tm structure to time_t
}

// Getter

unsigned int Date::getDay() const { return day; }
unsigned int Date::getMonth() const { return month; }
unsigned int Date::getYear() const { return year; }

// Setter

void Date::setDay(unsigned int newDay) { day = newDay; }
void Date::setMonth(unsigned int newMonth) { month = newMonth; }
void Date::setYear(unsigned int newYear) { year = newYear; }

std::string toString(const Date &date) {
  std::stringstream ss;
  ss << date.getDay() << "/" << date.getMonth() << "/" << date.getYear();
  std::string myString = ss.str();
  return myString;
}

// Cancellami

void Date::print() const { std::cout << day << "/" << month << "/" << year; }
