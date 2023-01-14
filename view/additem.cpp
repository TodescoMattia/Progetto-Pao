#include "additem.h"
#include "..\model\item.h"
#include "iteminfo.h"
#include <QFormLayout>
#include <QHBoxLayout>
#include <QPushButton>

AddItem::AddItem()
{
    QFormLayout* form = new QFormLayout(this);

    idLine= new QLineEdit();
    idLine->setText("");
    form->addRow(idLine);

    titleLine= new QLineEdit();
    titleLine->setText("");
    form->addRow(titleLine);

    isLentLine= new QLineEdit();
    isLentLine->setText("");
    form->addRow(isLentLine);

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

QString AddItem::getId() const{
    QString id = idLine->text();
    return id;
}
QString AddItem::getTitle() const{
    QString title = titleLine->text();
    return title;
}
QString AddItem::getIsLent() const{
    QString isLent = isLentLine->text();
    return isLent;
}
