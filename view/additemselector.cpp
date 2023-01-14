#include "additemselector.h"
#include <QtWidgets>

EditItemSelector::EditItemSelector(QWidget *parent)
    : QWidget(parent)
{
    QVBoxLayout* mainlayout = new QVBoxLayout;

    QFormLayout* DropDownMenuLayout = new QFormLayout;

    QComboBox *comboBox = new QComboBox;
        comboBox->addItem(tr("BoardGame"));
        comboBox->addItem(tr("Book"));
        comboBox->addItem(tr("BookSerie"));
        comboBox->addItem(tr("Film"));
        comboBox->addItem(tr("Videogame"));


    DropDownMenuLayout->addWidget(comboBox);



    QHBoxLayout* ButtonLayout = new QHBoxLayout;

    QPushButton* Salva = new QPushButton("Salva");
    QPushButton* Annulla = new QPushButton("Annulla");

    ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);



    mainlayout->addLayout(DropDownMenuLayout);
    mainlayout->addLayout(ButtonLayout);


    setLayout(mainlayout);
    setMinimumWidth(300);
    setWindowTitle(tr("Choose your Item"));
}

