#include "listview.h"
#include "deleteview.h"

#include <QHBoxLayout>
#include <QPushButton>

ListView::ListView(Info *infoAb): info(infoAb)
{
    widget = new QWidget();
    widget->setObjectName("list-item");

    QHBoxLayout* layout = new QHBoxLayout(widget);

    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    layout->addWidget(info->getWidget());

    layout->addStretch();

    editButton = new QPushButton("Modifica");
    layout->addWidget(editButton);


    //provs edit collegamento
    connect(editButton, &QPushButton::pressed, this, &ListView::editL);

    deleteButton= new QPushButton("Elimina");
    layout->addWidget(deleteButton);

    //prova delete collegamento

    //connect(deleteButton, &QPushButton::pressed, std::bind(&DeleteView), &ListView::deleteL);

}

QWidget* ListView::getWidget(){
    return widget;
}
