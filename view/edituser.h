#ifndef EDITUSER_H
#define EDITUSER_H

#include "../model/user.h"

#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>
#include <QPushButton>

class EditUser: public QDialog{
     Q_OBJECT

private:
    User* user;

    QLineEdit* nameLine;
    QLineEdit* surnameLine;
    QLineEdit* numberLine;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
   EditUser(User* user);

public slots:
    void setUser();
};

#endif // EDITUSER_H
