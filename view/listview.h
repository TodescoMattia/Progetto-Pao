#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "info.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class ListView : public QWidget {
  Q_OBJECT
private:
  Info *info;
  QWidget *widget;
  QPushButton *editButton;
  QPushButton *deleteButton;

public:
  ListView(Info *infoab);
  QWidget *getWidget();

public slots:
  void clickEdit();
  void clickDelete();
};

#endif // LISTVIEW_H
