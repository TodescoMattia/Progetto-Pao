#ifndef ITEMINFO_H
#define ITEMINFO_H

#include "../model/item.h"
#include "info.h"
#include "../utils/list.h"
#include "mainwindow.h"
#include <QLabel>
#include <QWidget>
#include "../utils/deepptr.h"


class ItemInfo : public Info {
private:
  DeepPtr<Item>& item;
  List<DeepPtr<Item>>* listItem;
  MainWindow* mainWindow;

  QWidget *widget;
  QLabel *idLabel;
  QLabel *titleLabel;
  QLabel *isLentLabel;

public:
  ItemInfo(DeepPtr<Item>& item, List<DeepPtr<Item>>* listItem, MainWindow * mainWindow);
  QWidget *getWidget() const;
  void edit();
  void remove();
  ItemInfo* clone() const override;

};

#endif // ITEMINFO_H
