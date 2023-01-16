#ifndef ITEMTAB_H
#define ITEMTAB_H
#include <QWidget>
#include "../model/list.h"
#include "../model/item.h"
#include "additemselector.h"

class ItemTab:public QWidget{
    Q_OBJECT
private:
    List<Item*> listItem;
    AddItemSelector *itemSelector;

public:
    ItemTab(List<Item*>& lista);
   // ItemTab& reloadData();

signals:
    void reload();

public slots:
    void selectItem();
    void createItem();
    void confirm();
};

#endif // ITEMTAB_H
