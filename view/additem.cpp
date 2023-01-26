#include "additem.h"

#include <QLabel>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QPushButton>
#include <QGroupBox>
#include <QLayoutItem>


AddItem::AddItem(AddItemSelector* itemSelector): itemSelector(itemSelector){

    setWindowTitle("Selezione tipo oggetto");
    int type = itemSelector->getTypeGroup();

    QLabel* idLabel = new QLabel("ID:");
    idLine= new QLineEdit();
    idLine->setPlaceholderText("Inserisci ID");

    QLabel* titleLabel = new QLabel("Titolo:");
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
    layout->addWidget(idLabel);
    layout->addWidget(idLine);
    layout->addWidget(titleLabel);
    layout->addWidget(titleLine);
    layout->addWidget(isLentBox);


    switch(type) {
    case 0: //book
    {
        QLabel* authorLabel = new QLabel("Autore:");
        QLabel* pageNumberLabel = new QLabel("Numero Pagine:");
        QLabel* genreLabel = new QLabel("Genere:");

        authorLine = new QLineEdit();
        authorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(authorLabel);
        layout->addWidget(authorLine);

        pageNumberLine = new QSpinBox();
        layout->addWidget(pageNumberLabel);
        layout->addWidget(pageNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreLabel);
        layout->addWidget(genreBox);

        break;
}

    case 1: //bookserie
    {
        QLabel* authorBookSerieLabel = new QLabel("Autore:");
        QLabel* pageNumberLabel = new QLabel("Numero Pagine:");
        QLabel* volumeNumberLabel = new QLabel("Numero Volumi:");
        QLabel* genreLabel = new QLabel("Genere:");

        authorLine = new QLineEdit();
        authorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(authorBookSerieLabel);
        layout->addWidget(authorLine);

        pageNumberLine = new QSpinBox();
        layout->addWidget(pageNumberLabel);
        layout->addWidget(pageNumberLine);

        volumeNumberLine = new QSpinBox();
        layout->addWidget(volumeNumberLabel);
        layout->addWidget(volumeNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreLabel);
        layout->addWidget(genreBox);

        break;
}

    case 2: //film
    {

        QLabel* directorLabel = new QLabel("Regista:");
        QLabel* durationLabel = new QLabel("Durata:");
        QLabel* genreLabel = new QLabel("Genere:");

        directorLine = new QLineEdit();
        directorLine->setPlaceholderText("Inserisci autore");
        layout->addWidget(directorLabel);
        layout->addWidget(directorLine);

        durationLine = new QSpinBox();
        durationLine->setSpecialValueText(tr("Inserisci durata"));
        layout->addWidget(durationLabel);
        layout->addWidget(durationLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreLabel);
        layout->addWidget(genreBox);

        break;
}
    case 3: //board game
    {
        QLabel* playerNumberLabel = new QLabel("Numero Giocatori:");
        QLabel* genreLabel = new QLabel("Genere:");

        playerNumberLine = new QSpinBox();
        layout->addWidget(playerNumberLabel);
        layout->addWidget(playerNumberLine);

        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreLabel);
        layout->addWidget(genreBox);

        break;
}

    case 4: //videogame
    {
        QLabel* genreLabel = new QLabel("Genere:");
        genreBox = new QComboBox;
            genreBox->insertItem(0, "Fantasy");
            genreBox->insertItem(1, "Horror");
            genreBox->insertItem(2, "Romance");
            genreBox->insertItem(3, "Comedy");
            genreBox->insertItem(4, "Thriller");
        layout->addWidget(genreLabel);
        layout->addWidget(genreBox);

        break;
    }

    default:
        return;
    }

    buttonBox = new QDialogButtonBox();

    confirmButton = new QPushButton("Conferma");
    confirmButton->setObjectName("confirmButton");

    cancelButton = new QPushButton("Annulla");
    cancelButton->setObjectName("cancelButton");

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
