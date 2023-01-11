#include "edititem.h"
#include <QtWidgets>

EditItem::EditItem(QWidget *parent)
    : QWidget(parent)
{


    QLineEdit* ID = new QLineEdit;
    QLineEdit* Title = new QLineEdit;
    QCheckBox* IsLent = new QCheckBox;



    QVBoxLayout* mainlayout = new QVBoxLayout;

        QFormLayout* FormLayout = new QFormLayout;

        FormLayout->addRow(tr("&ID:"), ID);
        FormLayout->addRow(tr("&Title:"), Title);
        FormLayout->addRow(tr("&IsLent:"), IsLent);




    QHBoxLayout* ButtonLayout = new QHBoxLayout;

    QPushButton* Salva = new QPushButton("Salva");
    QPushButton* Annulla = new QPushButton("Annulla");

    ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);


    mainlayout->addLayout(FormLayout);
    mainlayout->addLayout(ButtonLayout);


    setLayout(mainlayout);
    setWindowTitle(tr("ItemEdit"));
}

