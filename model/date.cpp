#include "date.h"
#include <time.h>

Date::Date(unsigned int d, unsigned int m, unsigned int y)
    : day((d >= 1 && d <= 31) ? d : 1), month((m >= 1 && m <= 12) ? m : 1),
      year(y) {}

// Metodi
void Date::print() const { std::cout << day << "/" << month << "/" << year; }

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