#include "edituser.h"
#include <QtWidgets>

EditUser::EditUser(User *user): user(user){

    nameLine = new QLineEdit();
    nameLine->setText(QString::fromStdString(user->getName()));

    surnameLine = new QLineEdit();
    surnameLine->setText(QString::fromStdString(user->getSurname()));

    numberLine = new QLineEdit();
    numberLine->setText(QString::fromStdString(user->getNumber()));

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setUser()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(nameLine);
    layout->addWidget(surnameLine);
    layout->addWidget(numberLine);
    layout->addWidget(buttonBox);

    setWindowTitle("Modifica utente");

}

void EditUser::setUser(){
    user->setName(nameLine->text().toStdString());
    user->setSurname(surnameLine->text().toStdString());
    user->setNumber(numberLine->text().toStdString());
    accept();
}

