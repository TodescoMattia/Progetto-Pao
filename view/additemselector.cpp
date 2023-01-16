#include "additemselector.h"
#include <QtWidgets>

AddItemSelector::AddItemSelector(){

    layout = new QVBoxLayout(this);

    QRadioButton* bookButton = new QRadioButton("Libro singolo");
    QRadioButton* bookSerieButton = new QRadioButton("Libro di una serie");
    QRadioButton* filmButton = new QRadioButton("Film");
    QRadioButton* videogameButton = new QRadioButton("Videogame");
    QRadioButton* boardGameButton = new QRadioButton("Gioco da tavolo");

    bookButton->setChecked(true);

    selectTypeGroup = new QButtonGroup();

    selectTypeGroup->addButton(bookButton, 0);
    selectTypeGroup->addButton(bookSerieButton, 1);
    selectTypeGroup->addButton(filmButton, 2);
    selectTypeGroup->addButton(videogameButton, 3);
    selectTypeGroup->addButton(boardGameButton, 4);

    QVBoxLayout* selectTypeLayout = new QVBoxLayout();
    selectTypeLayout->addWidget(bookButton);
    selectTypeLayout->addWidget(bookSerieButton);
    selectTypeLayout->addWidget(filmButton);
    selectTypeLayout->addWidget(videogameButton);
    selectTypeLayout->addWidget(boardGameButton);

    QGroupBox* selectTypeBox = new QGroupBox("Tipo di oggetto:");
    selectTypeBox->setLayout(selectTypeLayout);

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    //connect(selectTypeGroup, SIGNAL(idPressed(int)), this, SLOT(AddItemSelector::enableConfirm(int)));

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout->addWidget(selectTypeBox);
    layout->addWidget(buttonBox);


    /*ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);

    mainlayout->addLayout(DropDownMenuLayout);
    mainlayout->addLayout(ButtonLayout);


    setLayout(mainlayout);
    setMinimumWidth(300);
    setWindowTitle(tr("Choose your Item"));*/
}

int AddItemSelector::getTypeGroup(){
    return selectTypeGroup->checkedId();
}


