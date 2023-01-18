#include "editfilm.h"
#include <QVBoxLayout>
#include <QRadioButton>

EditFilm::EditFilm(Film* film): EditItem(film), film(film)
{
    QLayout* layout = this->layout();

    directorLine= new QLineEdit();
    directorLine->setText(QString::fromStdString(film->getDirector()));

    durationLine = new QSpinBox();
    durationLine->setValue(film->getDuration());

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

    switch(toInt(film->getFilmGenre())){
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

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setFilm()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    layout->addWidget(directorLine);
    layout->addWidget(durationLine);
    layout->addWidget(fantasyButton);
    layout->addWidget(horrorButton);
    layout->addWidget(romanceButton);
    layout->addWidget(comedyButton);
    layout->addWidget(thrillerButton);
    layout->addWidget(buttonBox);

}

void EditFilm::setFilm(){
    this->set();
    film->setDirector(directorLine->text().toStdString());
    film->setDuration(durationLine->value());
    film->setFilmGenre(toGenre(genreGroup->checkedId()));
    accept();
}
