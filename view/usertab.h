#ifndef USERTAB_H
#define USERTAB_H
#include <QWidget>
#include "listwidget.h"
#include "../model/list.h"
#include "../model/user.h"
#include "mainwindow.h"

class UserTab: public QWidget{
    Q_OBJECT
private:
    List<User*>* listUser;
    MainWindow * mainWindow;
public:
    UserTab(List<User*>* lista, MainWindow * mainWindow);

public slots:
    void createUser();
    void confirm();
    //void cancel();
};

#endif // USERTAB_H
