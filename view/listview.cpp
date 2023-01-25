#include "listview.h"
#include "deleteview.h"

#include <QHBoxLayout>
#include <QPushButton>

ListView::ListView(Info *infoAb) : info(infoAb) {

    widget = new QWidget();
    widget->setObjectName("list-item");

    QHBoxLayout *layout = new QHBoxLayout(widget);

    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    layout->addWidget(info->getWidget());

    layout->addStretch();

    editButton = new QPushButton("Modifica");
    layout->addWidget(editButton);

    deleteButton = new QPushButton("Elimina");
    layout->addWidget(deleteButton);

    connect(editButton, &QPushButton::clicked, this, &ListView::clickEdit);
    connect(deleteButton, &QPushButton::clicked, this, &ListView::clickDelete);
}

QWidget *ListView::getWidget() { return widget; }

void ListView::clickEdit() { info->edit(); }
void ListView::clickDelete() { info->remove(); }
