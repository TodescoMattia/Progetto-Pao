#include "itemtab.h"
#include "listwidget.h"

#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

ItemTab::ItemTab() {

  // Creates widgets
  QVBoxLayout *vbox = new QVBoxLayout(this);
  vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

  QLabel *titleLabel = new QLabel("Elenco oggetti ");
  // titleLabel->setObjectName("title");
  titleLabel->setAlignment(Qt::AlignHCenter);
  vbox->addWidget(titleLabel);

  ListWidget *itemList = new ListWidget();

  QScrollArea *scrollArea = new QScrollArea();
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
  scrollArea->setWidgetResizable(true);
  scrollArea->setWidget(itemList);

  vbox->addWidget(scrollArea);

  QPushButton *addItem = new QPushButton("Aggiungi oggetto");
  vbox->addWidget(addItem);


}
