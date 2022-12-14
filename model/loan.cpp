#include "loan.h"

// Costruttore
Loan::Loan(std::string cod, unsigned int d1, unsigned int m1, unsigned int y1,
           unsigned int d2, unsigned int m2, unsigned int y2, const User *user,
           const Item *ptr)
    : codLoan(cod), startDate(d1, m1, y1), endDate(d2, m2, y2), ptrUser(user),
      ptrItem(ptr) {}

// Metodi
void Loan::print() const {
  std::cout << codLoan;
  startDate.print();
  endDate.print();
  ptrUser->print();
  ptrItem->print();
}

bool Loan::isExpired() const { return endDate.isBeforeToday(); }