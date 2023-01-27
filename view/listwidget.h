#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QWidget>
#include <QDialogButtonBox>

#include "../model/list.h"
#include "../model/item.h"
#include "listview.h"

class ListWidget : public QWidget {
  Q_OBJECT

private:
  List<ListView*> listView;
  List<Info*> listInfo;

public:
  ListWidget(List<Info*>& lista);

};
#endif // LISTWIDGET_H
