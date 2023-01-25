#include "edititem.h"

#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>

EditItem::EditItem(Item* item): item(item)
{
    QLabel* idLabel = new QLabel("ID:");
    idLine = new QLineEdit();
    idLine->setText(QString::fromStdString(item->getId()));

    QLabel* titleLabel = new QLabel("Titolo:");
    titleLine = new QLineEdit();
    titleLine->setText(QString::fromStdString(item->getTitle()));

    QLabel* isLentLabel = new QLabel("In Prestito:");
    isLentCheck = new QCheckBox();
    if(item->getState()){
        isLentCheck->setChecked(true);
    }

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(idLabel);
    layout->addWidget(idLine);
    layout->addWidget(titleLabel);
    layout->addWidget(titleLine);
    layout->addWidget(isLentLabel);
    layout->addWidget(isLentCheck);


    /*ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);*/

    setWindowTitle("Modifica oggetto");
    layout->setContentsMargins(20,20,20,20);
    this->setMaximumWidth(350);
}

void EditItem::set(){
    item->setId(idLine->text().toStdString());
    item->setTitle(titleLine->text().toStdString());
    item->setState(isLentCheck->isChecked());

}
