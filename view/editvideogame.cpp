#include "editvideogame.h"

#include <QLabel>
#include <QVBoxLayout>
#include <QRadioButton>

EditVideogame::EditVideogame(Videogame* videogame): EditItem(videogame), videogame(videogame)
{
    QLayout* layout = this->layout();

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

    switch(toInt(videogame->getVGameGenre())){
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
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setVideogame()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout->addWidget(genreLabel);
    layout->addWidget(fantasyButton);
    layout->addWidget(horrorButton);
    layout->addWidget(romanceButton);
    layout->addWidget(comedyButton);
    layout->addWidget(thrillerButton);
    layout->addWidget(buttonBox);

}

void EditVideogame::setVideogame(){
    this->set();
    videogame->setVGameGenre(toGenre(genreGroup->checkedId()));
    accept();
}
