#ifndef USERINFO_H
#define USERINFO_H

#include "../model/user.h"
#include "info.h"
#include <QLabel>
#include <QWidget>

class UserInfo : public Info {
private:
  User &user;
  QWidget *widget;
  QLabel *nameLabel;
  QLabel *surnameLabel;
  QLabel *numberLabel;

public:
  UserInfo(User &user);
  QWidget *getWidget() const;
  void edit();
  void remove();
};

#endif // USERINFO_H
