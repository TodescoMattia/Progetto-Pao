#include "adduser.h"
#include "..\model\user.h"
#include "userinfo.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>

AddUser::AddUser()
{
    QFormLayout* form = new QFormLayout(this);

    nameLine= new QLineEdit();
    nameLine->setText("");
    form->addRow(nameLine);

    surnameLine= new QLineEdit();
    surnameLine->setText("");
    form->addRow(surnameLine);

    numberLine= new QLineEdit();
    numberLine->setText("");
    form->addRow(numberLine);

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    form->addRow(buttonBox);


    //connect(buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    //connect(buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

QString AddUser::getName() const{
    QString name = nameLine->text();
    return name;
}
QString AddUser::getSurname() const{
    QString surname = surnameLine->text();
    return surname;
}
QString AddUser::getNumber() const{
    QString number = numberLine->text();
    return number;
}


