#ifndef USERTAB_H
#define USERTAB_H
#include <QWidget>
#include "../utils/list.h"
#include "../model/user.h"
#include "mainwindow.h"
#include "../utils/deepptr.h"

class UserTab: public QWidget{
    Q_OBJECT

private:
    List<DeepPtr<User>>* listUser;
    MainWindow * mainWindow;

public:
    UserTab(List<DeepPtr<User>>* lista, MainWindow * mainWindow);

public slots:
    void createUser();
    void confirm();
};

#endif // USERTAB_H
