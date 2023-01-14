#include "itemtab.h"
#include "listwidget.h"
#include "iteminfo.h"
#include "..\model\book.h"
#include "additem.h"

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

  QPushButton *addItemButton = new QPushButton("Aggiungi oggetto");
  vbox->addWidget(addItemButton);

  connect(addItemButton, &QPushButton::clicked, this, ItemTab::createItem);
}


void ItemTab::createItem(){
    AddItem* dialog= new AddItem();

    connect(dialog,SIGNAL(accepted()),this,SLOT(confirm()));

    dialog->setModal(true);
    dialog->show();
}

void ItemTab::confirm(){
    AddItem* dialog=dynamic_cast<AddItem*>(sender());
    if(dialog==nullptr) return;

    QWidget* provo= new QWidget();

    QVBoxLayout* provo3 = new QVBoxLayout(provo);
    QLabel* provo2= new QLabel("yohohohhoho");
    provo3->addWidget(provo2);

    provo->show();

    //std::string name = dialog->getName().toStdString();
   // std::string surname = dialog->getName().toStdString();
   // std::string number = dialog->getName().toStdString();

    //momentaneo
    //listUser.push_front(new User(name, surname, number));

}
