#include "userinfo.h"
#include "edituser.h"

#include <QString>
#include <QVBoxLayout>

UserInfo::UserInfo(DeepPtr<User>& user, List<DeepPtr<User>>* listUser, MainWindow *mainWindow) : user(user), listUser(listUser), mainWindow(mainWindow) {
  widget = new QWidget();

  QVBoxLayout *userInfo = new QVBoxLayout(widget);
  userInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  nameLabel = new QLabel("Nome: " + QString::fromStdString(user->getName()));
  userInfo->addWidget(nameLabel);

  surnameLabel =
      new QLabel("Cognome: " + QString::fromStdString(user->getSurname()));
  userInfo->addWidget(surnameLabel);

  numberLabel =
      new QLabel("Numero: " + QString::fromStdString(user->getNumber()));
  userInfo->addWidget(numberLabel);
}

QWidget *UserInfo::getWidget() const { return widget; }

void UserInfo::edit(){
    EditUser * edit= new EditUser(&*user);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshUser()));
}

void UserInfo::remove(){
    List<DeepPtr<User>>::Iterator it = listUser->find_iterator(user);
    listUser->erase(it);
    mainWindow->refreshUser();

}

UserInfo* UserInfo::clone() const {
    return new UserInfo(*this);
}

