#ifndef LOANINFO_H
#define LOANINFO_H

#include <QWidget>
#include <QLabel>
#include "..\model\Loan.h"
#include "Info.h"

class LoanInfo: public Info{
private:
    Loan& loan;
    QWidget* widget;
    QLabel* idLabel;
    QLabel* startDateLabel;
    QLabel* endDateLabel;
    QLabel* userLabel;
    QLabel* itemLabel;

public:
    LoanInfo(Loan& loan);
    QWidget* getWidget() const;
};

#endif // LOANINFO_H
