#ifndef USERINFO_H
#define USERINFO_H

#include "../model/user.h"
#include "info.h"
#include "../utils/list.h"
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include "../utils/deepptr.h"

class UserInfo : public Info {

private:
  DeepPtr<User>& user;
  List<DeepPtr<User>>* listUser;
  MainWindow* mainWindow;

  QWidget *widget;
  QLabel *nameLabel;
  QLabel *surnameLabel;
  QLabel *numberLabel;

public:
  UserInfo(DeepPtr<User>& user, List<DeepPtr<User>>* listUser, MainWindow *mainWindow);
  QWidget *getWidget() const;
  void edit() override;
  void remove() override;
  UserInfo* clone() const override;

};

#endif // USERINFO_H
