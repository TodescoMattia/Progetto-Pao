#include "edituser.h"
#include <QtWidgets>

EditUser::EditUser(User *user): user(user){

    QLabel* nameLabel= new QLabel("Nome:");
    nameLine = new QLineEdit();
    nameLine->setText(QString::fromStdString(user->getName()));

    QLabel* surnameLabel= new QLabel("Cognome:");
    surnameLine = new QLineEdit();
    surnameLine->setText(QString::fromStdString(user->getSurname()));

    QLabel* numberLabel= new QLabel("Numero Telefonico:");
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
    layout->addWidget(nameLabel);
    layout->addWidget(nameLine);
    layout->addWidget(surnameLabel);
    layout->addWidget(surnameLine);
    layout->addWidget(numberLabel);
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

