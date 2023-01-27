#include "iteminfo.h"
#include "edititem.h"
#include "iteminfovisitor.h"
#include "itemeditvisitor.h"
#include <QString>
#include <QVBoxLayout>

ItemInfo::ItemInfo(Item *item, List<Item*>* listItem, MainWindow * mainWindow) : item(item), listItem(listItem), mainWindow(mainWindow) {
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
    List<Item*>::Iterator it = listItem->find_iterator(item);
    listItem->erase(it);
    mainWindow->refreshData();
}

void ItemInfo::confirm(){



}
