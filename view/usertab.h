#ifndef USERTAB_H
#define USERTAB_H
#include <QWidget>
#include "listwidget.h"
#include "../model/list.h"
#include "../model/user.h"

class UserTab: public QWidget{
    Q_OBJECT
private:
    List<User*> listUser;
public:
    UserTab();

public slots:
    void createUser();
    void confirm();
    //void cancel();
};

#endif // USERTAB_H
