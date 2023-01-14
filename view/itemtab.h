#ifndef ITEMTAB_H
#define ITEMTAB_H
#include <QWidget>
#include "..\model\list.h"
#include "..\model\item.h"

class ItemTab:public QWidget{
    Q_OBJECT
private:
    List<Item*> listItem;
public:
    ItemTab();
public slots:
    void createItem();
    void confirm();
};

#endif // ITEMTAB_H
