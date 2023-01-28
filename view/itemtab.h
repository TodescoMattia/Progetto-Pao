#ifndef ITEMTAB_H
#define ITEMTAB_H
#include <QWidget>
#include "../utils/list.h"
#include "../model/item.h"
#include "additemselector.h"
#include "mainwindow.h"
#include "../utils/deepptr.h"

class ItemTab:public QWidget{
    Q_OBJECT

private:
    List<DeepPtr<Item>>* listItem;
    AddItemSelector *itemSelector;
    MainWindow * mainWindow;

public:
    ItemTab(List<DeepPtr<Item>>* lista, MainWindow * mainWindow);

public slots:
    void selectItem();
    void createItem();
    void confirm();
};

#endif // ITEMTAB_H
