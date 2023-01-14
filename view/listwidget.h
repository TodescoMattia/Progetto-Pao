#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QWidget>

#include "listview.h"
#include "..\model\list.h"
//#include "info.h"


class ListWidget: public QWidget{
    Q_OBJECT
private:
    List<ListView> list;
public:
    ListWidget();
    /*virtual ~ListItemWidget();
    virtual ListItemWidget& add(const Item* item);
    virtual ListItemWidget& remove(const Item* item);
    virtual ListItemWidget& clear();
*/

/*public slots:
    void addUser();
    void addItem();
    void addLoan();*/
};
#endif // LISTWIDGET_H
