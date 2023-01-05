#ifndef ITEMINFO_H
#define ITEMINFO_H


class ItemInfo: public QWidget{
    Q_OBJECT
public:
    ItemInfo(Item& item, QWidget* parent=0);
};

#endif // ITEMINFO_H
