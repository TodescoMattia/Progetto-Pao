#ifndef LOANTAB_H
#define LOANTAB_H
#include <QWidget>
#include "..\model\list.h"
#include "..\model\loan.h"
#include "..\model\loan.h"
#include "addloan.h"

class LoanTab:public QWidget{
    Q_OBJECT
private:
    List<Loan*> listLoan;
public:
    LoanTab();
public slots:
    void createLoan();
    void confirm();
};

#endif // LOANTAB_H
