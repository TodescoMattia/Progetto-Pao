#include "editboardgame.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>

EditBoardGame::EditBoardGame(BoardGame* boardGame): EditItem(boardGame), boardGame(boardGame)
{
    QLayout* layout = this->layout();

    QLabel* playerNumberLabel = new QLabel("Numero Giocatori:");
    playerNumberLine = new QSpinBox();
    playerNumberLine->setRange(0,99999);
    playerNumberLine->setValue(boardGame->getPlayerNumber());

    QLabel* genreLabel = new QLabel("Genere:");
    QRadioButton* fantasyButton = new QRadioButton("Fantasy");
    QRadioButton* horrorButton = new QRadioButton("Horror");
    QRadioButton* romanceButton = new QRadioButton("Romance");
    QRadioButton* comedyButton = new QRadioButton("Comedy");
    QRadioButton* thrillerButton = new QRadioButton("Thriller");

    genreGroup = new QButtonGroup();
        genreGroup->addButton(fantasyButton, 0);
        genreGroup->addButton(horrorButton, 1);
        genreGroup->addButton(romanceButton, 2);
        genreGroup->addButton(comedyButton, 3);
        genreGroup->addButton(thrillerButton, 4);

    switch(toInt(boardGame->getBGameGenre())){
    case 0:
        fantasyButton->setChecked(true);
        break;
    case 1:
        horrorButton->setChecked(true);
        break;
    case 2:
        romanceButton->setChecked(true);
        break;
    case 3:
        comedyButton->setChecked(true);
        break;
    case 4:
        thrillerButton->setChecked(true);
        break;
    }

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    confirmButton->setObjectName("confirmButton");

    cancelButton = new QPushButton("Annulla");
    cancelButton->setObjectName("cancelButton");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setBoardGame()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    layout->addWidget(playerNumberLabel);
    layout->addWidget(playerNumberLine);
    layout->addWidget(genreLabel);
    layout->addWidget(fantasyButton);
    layout->addWidget(horrorButton);
    layout->addWidget(romanceButton);
    layout->addWidget(comedyButton);
    layout->addWidget(thrillerButton);
    layout->addWidget(buttonBox);

    this->setMaximumWidth(300);
}

void EditBoardGame::setBoardGame(){
    this->set();
    boardGame->setBGameGenre(toGenre(genreGroup->checkedId()));
    boardGame->setPlayerNumber(playerNumberLine->value());
    accept();
}
