#ifndef ITEMINFO_H
#define ITEMINFO_H

#include "..\model\Item.h"
#include "Info.h"
#include <QLabel>
#include <QWidget>

class ItemInfo : public Info {
private:
  Item &item;
  QWidget *widget;
  QLabel *idLabel;
  QLabel *titleLabel;
  QLabel *isLentLabel;

public:
  ItemInfo(Item &item);
  QWidget *getWidget() const;
};

#endif // ITEMINFO_H
