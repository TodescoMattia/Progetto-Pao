#include "additemselector.h"
#include <QtWidgets>

AddItemSelector::AddItemSelector(){

    layout = new QVBoxLayout(this);

    QRadioButton* bookButton = new QRadioButton("Libro singolo");
    QRadioButton* bookSerieButton = new QRadioButton("Libro di una serie");
    QRadioButton* filmButton = new QRadioButton("Film");
    QRadioButton* boardGameButton = new QRadioButton("Gioco da tavolo");
    QRadioButton* videogameButton = new QRadioButton("Videogame");

    bookButton->setChecked(true);

    selectTypeGroup = new QButtonGroup();

    selectTypeGroup->addButton(bookButton, 0);
    selectTypeGroup->addButton(bookSerieButton, 1);
    selectTypeGroup->addButton(filmButton, 2);
    selectTypeGroup->addButton(boardGameButton, 3);
    selectTypeGroup->addButton(videogameButton, 4);


    QVBoxLayout* selectTypeLayout = new QVBoxLayout();
    selectTypeLayout->addWidget(bookButton);
    selectTypeLayout->addWidget(bookSerieButton);
    selectTypeLayout->addWidget(filmButton);
    selectTypeLayout->addWidget(boardGameButton);
    selectTypeLayout->addWidget(videogameButton);


    QGroupBox* selectTypeBox = new QGroupBox("Tipo di oggetto:");
    selectTypeBox->setLayout(selectTypeLayout);

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    confirmButton->setObjectName("confirmButton");

    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);
    cancelButton->setObjectName("cancelButton");

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout->addWidget(selectTypeBox);
    layout->addWidget(buttonBox);

    this->setFixedSize(250,250);

    setWindowTitle("Selezione tipo oggetto");
}

int AddItemSelector::getTypeGroup(){
    return selectTypeGroup->checkedId();
}


