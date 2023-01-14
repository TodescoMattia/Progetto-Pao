#include "addloan.h"

#include "..\model\loan.h"
#include "loaninfo.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>

AddLoan::AddLoan()
{
    QFormLayout* form = new QFormLayout(this);

    idLine= new QLineEdit();
    idLine->setText("");
    form->addRow(idLine);

    startDateDay= new QLineEdit();
    startDateDay->setText("");
    form->addRow(startDateDay);

    startDateMonth= new QLineEdit();
    startDateMonth->setText("");
    form->addRow(startDateMonth);

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

QString AddLoan::getId() const{
    QString id = idLine->text();
    return id;
}
QString AddLoan::getStartDateDay() const{
    QString startDay = startDateDay->text();
    return startDay;
}
QString AddLoan::getStartDateMonth() const{
    QString startMonth = startDateMonth->text();
    return startMonth;
}
