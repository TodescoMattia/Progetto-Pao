#ifndef LISTVIEW_H
#define LISTVIEW_H

#include "Info.h"
#include <QLabel>
#include <QPushButton>
#include <QWidget>

class ListView: public QWidget {
    Q_OBJECT
private:
  Info *info;
  QWidget *widget;
  QPushButton *editButton;
  QPushButton *deleteButton;

public:
  ListView(Info *infoab);
  QWidget *getWidget();

signals:
  void editL();
  void deleteL();
};

#endif // LISTVIEW_H
