#include "adduser.h"
#include "../model/user.h"
#include "userinfo.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>

AddUser::AddUser()
{
    setWindowTitle("Nuovo utente");

    nameLine= new QLineEdit();
    nameLine->setPlaceholderText("Inserisci nome");

    surnameLine= new QLineEdit();
    surnameLine->setPlaceholderText("Inserisci cognome");

    numberLine= new QLineEdit();
    numberLine->setPlaceholderText("Inserisci numero");

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    QFormLayout* form = new QFormLayout(this);
    form->addRow(nameLine);
    form->addRow(surnameLine);
    form->addRow(numberLine);
    form->addRow(buttonBox);

}

QString AddUser::getName() const{ return nameLine->text(); }
QString AddUser::getSurname() const{ return surnameLine->text(); }
QString AddUser::getNumber() const{ return numberLine->text(); }


