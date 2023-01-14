#ifndef ADDUSER_H
#define ADDUSER_H
#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include "usertab.h"

class AddUser: public QDialog{
    Q_OBJECT
private:
    QLineEdit *nameLine;
    QLineEdit *surnameLine;
    QLineEdit *numberLine;
    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;
public:
    AddUser();
    QString getName() const;
    QString getSurname() const;
    QString getNumber() const;
};

#endif // ADDUSER_H
