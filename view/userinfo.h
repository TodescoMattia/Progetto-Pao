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
  List<User*>* listUser;
  MainWindow* mainWindow;

  QWidget *widget;
  QLabel *nameLabel;
  QLabel *surnameLabel;
  QLabel *numberLabel;

public:
  UserInfo(User *user, List<User*>* listUser, MainWindow *mainWindow);
  QWidget *getWidget() const;
  void edit();
  void remove();

};

#endif // USERINFO_H
