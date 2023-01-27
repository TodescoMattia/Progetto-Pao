#ifndef ITEMINFO_H
#define ITEMINFO_H

#include "../model/item.h"
#include "info.h"
#include "../model/list.h"
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>

class ItemInfo : public Info {
private:
  Item *item;
  List<Item*>* listItem;
  MainWindow* mainWindow;

  QWidget *widget;
  QLabel *idLabel;
  QLabel *titleLabel;
  QLabel *isLentLabel;

public:
  ItemInfo(Item *item, List<Item*>* listItem, MainWindow * mainWindow);
  QWidget *getWidget() const;
  void edit();
  void remove();

public slots:
  void confirm();
};

#endif // ITEMINFO_H
