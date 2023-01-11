#ifndef ADDUSER_H
#define ADDUSER_H
#include <QLineEdit>
#include "usertab.h"

class AddUser: public QWidget{
    Q_OBJECT
private:
    QWidget* widget;
    QLineEdit *nameLine;
    QLineEdit *surnameLine;
    QLineEdit *numberLine;
public:
    AddUser();
    QWidget* getWidget();

public slots:
    void confirm();
    void cancel();
};

#endif // ADDUSER_H
