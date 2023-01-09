#ifndef USERINFO_H
#define USERINFO_H

#include <QWidget>
#include <QLabel>
#include "..\model\User.h"
#include "Info.h"

class UserInfo: public Info{
private:
    User& user;
    QWidget* widget;
    QLabel* nameLabel;
    QLabel* surnameLabel;
    QLabel* numberLabel;
public:
    UserInfo(User& user);
    QWidget* getWidget() const;
};

#endif // USERINFO_H
