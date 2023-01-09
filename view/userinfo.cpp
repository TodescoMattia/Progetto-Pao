#include "userinfo.h"

#include <QString>
#include <QVBoxLayout>

UserInfo::UserInfo(User &user) : user(user) {
  widget = new QWidget();

  QVBoxLayout *userInfo = new QVBoxLayout(widget);
  userInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  nameLabel = new QLabel("Nome: " + QString::fromStdString(user.getName()));
  userInfo->addWidget(nameLabel);

  surnameLabel =
      new QLabel("Cognome: " + QString::fromStdString(user.getSurname()));
  userInfo->addWidget(surnameLabel);

  numberLabel =
      new QLabel("Numero: " + QString::fromStdString(user.getNumber()));
  userInfo->addWidget(numberLabel);
}

QWidget *UserInfo::getWidget() const { return widget; }
