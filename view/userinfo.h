#ifndef USERINFO_H
#define USERINFO_H

#include "../model/user.h"
#include "info.h"
#include "../model/list.h"
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>

class UserInfo : public Info {
private:
  User *user;
  MainWindow* mainWindow;
  List<User*>* listUser;
  QWidget *widget;
  QLabel *nameLabel;
  QLabel *surnameLabel;
  QLabel *numberLabel;

public:
  UserInfo(User *user, MainWindow *mainWindow);
  QWidget *getWidget() const;
  void edit();
  void remove();

public slots:
  void confirm();
};

#endif // USERINFO_H
