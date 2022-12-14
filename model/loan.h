#ifndef LOAN_H
#define LOAN_H
#include "date.h"
#include "item.h"
#include "user.h"
#include <string>

class Loan {
private:
  std::string codLoan;
  Date startDate;
  Date endDate;
  const User *ptrUser;
  const Item *ptrItem;

public:
  // Costruttore
  Loan(std::string cod = "", unsigned int d1 = 1, unsigned int m1 = 1,
       unsigned int y1 = 1970, unsigned int d2 = 1, unsigned int m2 = 1,
       unsigned int y2 = 1970, const User *user = NULL, const Item *ptr = NULL);

  // Metodi
  void print() const;
  bool isExpired() const;
};

#endif
