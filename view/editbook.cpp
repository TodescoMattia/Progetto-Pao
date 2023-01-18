#include "editbook.h"
#include <QVBoxLayout>
#include <QRadioButton>

EditBook::EditBook(Book* book): EditItem(book), book(book)
{
    QLayout* layout = this->layout();

    authorLine= new QLineEdit();
    authorLine->setText(QString::fromStdString(book->getAuthor()));

    pageNumberLine = new QSpinBox();
    pageNumberLine->setValue(book->getPageNumber());

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

    switch(toInt(book->getBookGenre())){
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

    connect(buttonBox, SIGNAL(accepted()), this, SLOT(setBook()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));


    layout->addWidget(authorLine);
    layout->addWidget(pageNumberLine);
    layout->addWidget(fantasyButton);
    layout->addWidget(horrorButton);
    layout->addWidget(romanceButton);
    layout->addWidget(comedyButton);
    layout->addWidget(thrillerButton);
    layout->addWidget(buttonBox);

}

void EditBook::setBook(){
    this->set();
    book->setAuthor(authorLine->text().toStdString());
    book->setPageNumber(pageNumberLine->value());
    book->setBookGenre(toGenre(genreGroup->checkedId()));
    accept();
}

