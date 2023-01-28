#ifndef LISTWIDGET_H
#define LISTWIDGET_H
#include <QWidget>
#include <QDialogButtonBox>

#include "../utils/list.h"
#include "listview.h"
#include "../utils/deepptr.h"

class ListWidget : public QWidget {
  Q_OBJECT

private:
  List<ListView*> listView;
  List<DeepPtr<Info>> listInfo;

public:
  ListWidget(const List<DeepPtr<Info>> &lista);

};
#endif // LISTWIDGET_H
