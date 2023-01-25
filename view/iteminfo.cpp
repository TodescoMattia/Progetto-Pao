#include "iteminfo.h"
#include "edititem.h"
#include "iteminfovisitor.h"
#include "itemeditvisitor.h"
#include <QString>
#include <QVBoxLayout>

ItemInfo::ItemInfo(Item *item, MainWindow * mainWindow, List<Item*>::Iterator it, List<Item*>* listItem) : item(item), mainWindow(mainWindow), it(it), listItem(listItem) {
    widget = new QWidget();

    QVBoxLayout *itemInfo = new QVBoxLayout(widget);
    itemInfo->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    idLabel = new QLabel("Id: " + QString::fromStdString(item->getId()));
    itemInfo->addWidget(idLabel);

    titleLabel = new QLabel("Titolo: " + QString::fromStdString(item->getTitle()));
    itemInfo->addWidget(titleLabel);

    isLentLabel =
      new QLabel("Stato: " + QString::fromStdString(toString(item->getState())));
    itemInfo->addWidget(isLentLabel);

    ItemInfoVisitor visitor;
    item->accept(visitor);
    itemInfo->addWidget(visitor.getWidget());
}

QWidget *ItemInfo::getWidget() const { return widget; }

void ItemInfo::edit() {
    ItemEditVisitor visitor(mainWindow);
    item->accept(visitor);
}

void ItemInfo::remove() {
    listItem->erase(it);
    mainWindow->refreshData();
}

void ItemInfo::confirm(){



}
