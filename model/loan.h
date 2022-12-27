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

  // Getter

  std::string getCodLoan() const;
  Date getStartDate() const;
  Date getEndDate() const;
  const User *getUser() const;
  const Item *getItem() const;

  // Setter

  std::string setCodLoan(std::string NewCodLoan);
  Date setStartDate(Date NewStartDate);
  Date setEndDate(Date NewEndDate);
  const User *setUser(const User *NewUser);
  const Item *setItem(const Item *NewItem);
};

#endif
