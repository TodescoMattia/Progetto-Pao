#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QWidget>
#include <QDialogButtonBox>

#include "../model/list.h"
#include "../model/item.h"
#include "listview.h"
// #include "info.h"

class ListWidget : public QWidget {
  Q_OBJECT
private:
  List<ListView*> listView;
  List<Info*> listInfo;
  QPushButton* editButton;
  QPushButton* deleteButton;

public:
  ListWidget(List<Info*>& lista);
  /*virtual ~ListItemWidget();
  virtual ListItemWidget& add(const Item* item);
  virtual ListItemWidget& remove(const Item* item);
  virtual ListItemWidget& clear();
*/

};
#endif // LISTWIDGET_H
