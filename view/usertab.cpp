#include "usertab.h"
#include "adduser.h"


#include "../model/user.h"
#include "userinfo.h"

#include "listwidget.h"

#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

UserTab::UserTab(List<User*>* lista, MainWindow * mainWindow) : listUser(lista), mainWindow(mainWindow) {

  QVBoxLayout *vbox = new QVBoxLayout(this);
  vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

  QLabel *titleLabel = new QLabel("Elenco utenti ");

  titleLabel->setAlignment(Qt::AlignHCenter);
  vbox->addWidget(titleLabel);

  //Creo Info

  List<User*>::Iterator start = listUser->begin();
  List<User*>::Iterator end = listUser->end();

  List<Info*> listInfo = *(new List<Info *>);

  for (start = listUser->begin(), end = listUser->end(); start != end; start++) {
      Info* info= new UserInfo(*start, listUser, mainWindow);
      listInfo.push_front(info);
  }

  ListWidget *userList = new ListWidget(listInfo);

  QScrollArea *scrollArea = new QScrollArea();
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setWidgetResizable(true);
  scrollArea->setWidget(userList);

  vbox->addWidget(scrollArea);

  QPushButton *addUserButton = new QPushButton(QIcon(QPixmap(":/assets/icons/add.svg")), "Aggiungi utente");
  vbox->addWidget(addUserButton);

  connect(addUserButton, &QPushButton::clicked, this, &UserTab::createUser);
}

void UserTab::createUser() {
  AddUser *dialog = new AddUser();
  connect(dialog, SIGNAL(accepted()), this, SLOT(confirm()));

  dialog->setModal(true);
  dialog->show();
}

void UserTab::confirm() {
  AddUser *dialog = dynamic_cast<AddUser *>(sender());
  if (dialog == nullptr)
    return;

  std::string name = dialog->getName().toStdString();
  std::string surname = dialog->getSurname().toStdString();
  std::string number = dialog->getNumber().toStdString();

  listUser->push_front(new User(name, surname, number));

  mainWindow->refreshData();
}

