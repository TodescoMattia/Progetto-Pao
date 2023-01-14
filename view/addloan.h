#ifndef ADDLOAN_H
#define ADDLOAN_H

#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include "loantab.h"

class AddLoan: public QDialog{
    Q_OBJECT
private:
    QLineEdit *idLine;
    QLineEdit *startDateDay;
    QLineEdit *startDateMonth;
    QLineEdit *startDateYear;
    QLineEdit *endDateDay;
    QLineEdit *endDateMonth;
    QLineEdit *endDateYear;
    QLineEdit *ptrUser;
    QLineEdit *ptrItem;
    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;
public:
    AddLoan();
    QString getId() const;
    QString getStartDateDay() const;
    QString getStartDateMonth() const;
};

#endif // ADDLOAN_H
