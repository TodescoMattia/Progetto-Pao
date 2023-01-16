#include <QVBoxLayout>
#include <QString>
#include "iteminfo.h"
#include "ItemInfoVisitor.h"

ItemInfo::ItemInfo(Item& item)
: item(item)
{
    widget= new QWidget();

    QVBoxLayout* itemInfo = new QVBoxLayout(widget);
    itemInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    idLabel = new QLabel("Id: " + QString::fromStdString(item.getId()));
    itemInfo->addWidget(idLabel);

    titleLabel = new QLabel("Titolo: " + QString::fromStdString(item.getTitle()));
    itemInfo->addWidget(titleLabel);

    isLentLabel = new QLabel("Stato: " + QString::fromStdString(toString(item.getState())));
    itemInfo->addWidget(isLentLabel);

    ItemInfoVisitor visitor;
    item.accept(visitor);
    itemInfo->addWidget(visitor.getWidget());
}

QWidget* ItemInfo::getWidget() const{
    return widget;
}

void ItemInfo::edit(){
    QWidget* prova= new QWidget();
    prova->show();

}
void ItemInfo::remove(){

}

