#include "adduser.h"
#include "..\model\user.h"
#include "userinfo.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>

AddUser::AddUser()
{
    widget=new QWidget();

    QFormLayout* form = new QFormLayout(widget);

    nameLine= new QLineEdit();
    nameLine->setText("Prova");
    form->addRow(nameLine);

    surnameLine= new QLineEdit();
    surnameLine->setText("Prova");
    form->addRow(surnameLine);

    numberLine= new QLineEdit();
    numberLine->setText("Prova");
    form->addRow(numberLine);

    QHBoxLayout* button = new QHBoxLayout(widget);

    QPushButton* confirmButton = new QPushButton("Conferma");
    button->addWidget(confirmButton);

    connect(confirmButton, &QPushButton::clicked, this, &AddUser::confirm);

    QPushButton* cancelButton = new QPushButton("Annulla");
    button->addWidget(cancelButton);

    form->addRow(button);

}

QWidget* AddUser::getWidget(){
    return widget;
}


void AddUser::confirm(){
    QString name = nameLine->text();
    QString surname = surnameLine->text();
    QString number = numberLine->text();

    ListView* prova= new ListView(new UserInfo(*(new User(name.toStdString(), surname.toStdString(), number.toStdString()))));

}

void AddUser::cancel(){
}

