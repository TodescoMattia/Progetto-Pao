#include "usertab.h"
#include "adduser.h"


#include "../model/user.h"
#include "userinfo.h"

#include "listwidget.h"

#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

UserTab::UserTab(List<User*>* lista, MainWindow * mainWindow) : listUser(lista), mainWindow(mainWindow) {

  // Creates widgets
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
      Info* info= new UserInfo(*start, mainWindow);
      listInfo.push_front(info);
  }

  ListWidget *userList = new ListWidget(listInfo);

  QScrollArea *scrollArea = new QScrollArea();
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setWidgetResizable(true);
  scrollArea->setWidget(userList);

  vbox->addWidget(scrollArea);

  QPushButton *addUserButton = new QPushButton("Aggiungi utente");
  vbox->addWidget(addUserButton);

  //dr
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

  // momentaneo
  listUser->push_front(new User(name, surname, number));

  mainWindow->refreshData();
}
/*
void UserTab::cancel(){
    //AddUser* dialog=(sender());

    QWidget* provo= new QWidget();

    QVBoxLayout* provo3 = new QVBoxLayout(provo);
    QLabel* provo2= new QLabel("yohohohhohocattivo");
    provo3->addWidget(provo2);

    provo->show();
   //return;
}*/
