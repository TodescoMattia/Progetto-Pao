#include "editbookserie.h"
#include <QVBoxLayout>
#include <QRadioButton>

EditBookSerie::EditBookSerie(BookSerie* bookSerie): EditItem(bookSerie), bookSerie(bookSerie)
{
    QLayout* layout = this->layout();

    authorLine= new QLineEdit();
    authorLine->setText(QString::fromStdString(bookSerie->getAuthor()));

    pageNumberLine = new QSpinBox();
    pageNumberLine->setValue(bookSerie->getPageNumber());

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

    switch(toInt(bookSerie->getBookGenre())){
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

    volumeLine = new QSpinBox();
    volumeLine->setValue(bookSerie->getVolumeNumber());

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setBookSerie()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    layout->addWidget(authorLine);
    layout->addWidget(pageNumberLine);
    layout->addWidget(fantasyButton);
    layout->addWidget(horrorButton);
    layout->addWidget(romanceButton);
    layout->addWidget(comedyButton);
    layout->addWidget(thrillerButton);
    layout->addWidget(volumeLine);
    layout->addWidget(buttonBox);

}

void EditBookSerie::setBookSerie(){
    this->set();
    bookSerie->setAuthor(authorLine->text().toStdString());
    bookSerie->setPageNumber(pageNumberLine->value());
    bookSerie->setBookGenre(toGenre(genreGroup->checkedId()));
    bookSerie->setVolumeNumber(volumeLine->value());
    accept();
}