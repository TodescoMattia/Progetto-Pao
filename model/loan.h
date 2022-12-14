#ifndef LOAN
#define LOAN
#include "item.h"
#include "user.h"
#include <string>
#include <time.h>

class Loan {
private:
  std::string codLoan;
  time_t startDate;
  time_t endDate;
  const User *ptrUser;
  const Item *ptrItem;

public:
  // Costruttore
  Loan(std::string cod = "", time_t = NULL, time_t = NULL,
       const User *user = NULL, const Item *ptr = NULL);

  // Metodi
  void print() const;
  // bool expiredLoan() const;
};

#endif
