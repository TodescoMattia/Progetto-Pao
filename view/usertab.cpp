#include "usertab.h"
#include "adduser.h"

#include "listwidget.h"


#include<QLabel>
#include<QScrollArea>
#include <QVBoxLayout>

UserTab::UserTab()
{
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("Elenco utenti ");
    //titleLabel->setObjectName("title");
    titleLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(titleLabel);

    listUser = *(new List<User*>);
    listUser.push_front(new User("Mario", "Bianchi", "3458746715"));
    listUser.push_front(new User("Luigi", "Bianchi", "3458746715"));

    ListWidget* userListWidget=new ListWidget();

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(userListWidget);

    vbox->addWidget(scrollArea);

    QPushButton* addUserButton= new QPushButton("Aggiungi utente");
    vbox->addWidget(addUserButton);


    connect(addUserButton, &QPushButton::clicked, this, UserTab::createUser);

}

void UserTab::createUser(){
    AddUser* dialog= new AddUser();

    connect(dialog,SIGNAL(accepted()),this,SLOT(confirm()));
   // connect(dialog,SIGNAL(rejected()),this,SLOT(cancel()));

    dialog->setModal(true);
    dialog->show();
}

void UserTab::confirm(){
    AddUser* dialog=dynamic_cast<AddUser*>(sender());
    if(dialog==nullptr) return;

    /*QWidget* provo= new QWidget();

    QVBoxLayout* provo3 = new QVBoxLayout(provo);
    QLabel* provo2= new QLabel("yohohohhoho");
    provo3->addWidget(provo2);

    provo->show();*/

    std::string name = dialog->getName().toStdString();
    std::string surname = dialog->getName().toStdString();
    std::string number = dialog->getName().toStdString();

    //momentaneo
    listUser.push_front(new User(name, surname, number));

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
