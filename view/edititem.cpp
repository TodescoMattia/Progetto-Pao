#include "edititem.h"
#include "itemeditvisitor.h"

#include <QLineEdit>
#include <QVBoxLayout>
#include <QFormLayout>

EditItem::EditItem(Item* item): item(item)
{
    idLine = new QLineEdit();
    idLine->setText(QString::fromStdString(item->getId()));

    titleLine = new QLineEdit();
    titleLine->setText(QString::fromStdString(item->getTitle()));

    isLentCheck = new QCheckBox();
    if(item->getState()){
        isLentCheck->setChecked(true);
    }

    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->addWidget(idLine);
    layout->addWidget(titleLine);
    layout->addWidget(isLentCheck);


    /*ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);*/

    setWindowTitle("Modifica oggetto");
}

void EditItem::set(){
    item->setId(idLine->text().toStdString());
    item->setTitle(titleLine->text().toStdString());
    item->setState(isLentCheck->isChecked());

}
