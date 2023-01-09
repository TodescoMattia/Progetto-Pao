#include "usertab.h"
#include "listwidget.h"

#include<QLabel>
#include<QScrollArea>
#include <QVBoxLayout>

UserTab::UserTab()
{
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("Elenco utenti ");
    //titleLabel->setObjectName("title");
    titleLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(titleLabel);

    ListWidget* userList=new ListWidget();

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(userList);

    vbox->addWidget(scrollArea);

    QPushButton* addUser= new QPushButton("Aggiungi utente");
    vbox->addWidget(addUser);

}
