#include "additem.h"
#include "../model/item.h"
#include "iteminfo.h"

#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QLayoutItem>



AddItem::AddItem(AddItemSelector* itemSelector): itemSelector(itemSelector){

    setWindowTitle("Selezione tipo oggetto");
    int type = itemSelector->getTypeGroup();

    idLine= new QLineEdit();
    idLine->setPlaceholderText("Inserisci ID");

    titleLine= new QLineEdit();
    titleLine->setPlaceholderText("Inserisci titolo");


    QRadioButton* isLentButton = new QRadioButton("Sì");
    QRadioButton* isNotLentButton = new QRadioButton("No");
    isNotLentButton->setChecked(true);

    isLentGroup = new QButtonGroup();
    isLentGroup->addButton(isLentButton, 1);
    isLentGroup->addButton(isNotLentButton, 0);

    QHBoxLayout* isLentLayout = new QHBoxLayout();
    isLentLayout->addWidget(isLentButton);
    isLentLayout->addWidget(isNotLentButton);

    QGroupBox* isLentBox = new QGroupBox("È in prestito:");
    isLentBox->setLayout(isLentLayout);
    isLentBox->setAlignment(Qt::AlignLeft);

    layout = new QVBoxLayout(this);
    layout->addWidget(idLine);
    layout->addWidget(titleLine);
    layout->addWidget(isLentBox);

    switch(type) {
    case 0: //book
        authorLine = new QLineEdit();
        authorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(authorLine);

        pageNumberLine = new QSpinBox();
        layout->addWidget(pageNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreBox);

        break;

    case 1: //bookserie
        authorLine = new QLineEdit();
        authorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(authorLine);

        pageNumberLine = new QSpinBox();
        layout->addWidget(pageNumberLine);

        volumeNumberLine = new QSpinBox();

        layout->addWidget(volumeNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreBox);

        break;

    case 2: //film
        directorLine = new QLineEdit();
        directorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(directorLine);

        durationLine = new QSpinBox();
        durationLine->setSpecialValueText(tr("Inserisci durata"));
        layout->addWidget(durationLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreBox);

        break;

    case 3: //board game

        playerNumberLine = new QSpinBox();
        layout->addWidget(playerNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreBox);

        break;

    case 4: //videogame

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreBox);

        break;

    default:
        return;
    }

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    cancelButton = new QPushButton("Annulla");

    buttonBox->addButton(confirmButton, QDialogButtonBox::AcceptRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::RejectRole);

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));

    layout->addWidget(buttonBox);
    layout->addStretch();
    this->setMaximumHeight(500);
    this->setMaximumWidth(300);
}


QString AddItem::getId() const{ return idLine->text();}
QString AddItem::getTitle() const{ return titleLine->text();}
int AddItem::getIsLent() const{ return isLentGroup->checkedId(); }
QString AddItem::getAuthor() const{ return authorLine->text(); }
int AddItem::getPageNumber() const{ return pageNumberLine->value(); }
int AddItem::getVolumeNumber() const{ return volumeNumberLine->value(); }
int AddItem::getGenre() const{return genreBox->currentIndex(); }
QString AddItem::getDirector() const{ return directorLine->text(); }
int AddItem::getDuration() const{ return durationLine->value(); }
int AddItem::getPlayerNumber() const{ return playerNumberLine->value();}
int AddItem::getSelectedType() const{ return itemSelector->getTypeGroup();}
