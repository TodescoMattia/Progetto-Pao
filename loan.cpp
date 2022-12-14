#include "loan.h"

// Costruttore
Loan::Loan(std::string cod, time_t startD, time_t endD, const User *user,
           const Item *ptr)
    : codLoan(cod), startDate(startD), endDate(endD), ptrUser(user),
      ptrItem(ptr) {}

// Metodi
void Loan::print() const {
  std::cout << codLoan;
  std::cout << startDate;
  std::cout << endDate;
  ptrUser->print();
  ptrItem->print();
}