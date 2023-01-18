
#include "itemeditvisitor.h"
#include "..\model\BoardGame.h"
#include "..\model\Book.h"
#include "..\model\BookSerie.h"
#include "..\model\Film.h"
#include "..\model\Videogame.h"
#include "qlineedit.h"
#include <QtWidgets>
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

#include "editbook.h"
#include "editbookserie.h"
#include "editfilm.h"
#include "editboardgame.h"
#include "editvideogame.h"

ItemEditVisitor::ItemEditVisitor(MainWindow* mainWindow): mainWindow(mainWindow){}

void ItemEditVisitor::visit(Book *book) {
    EditBook * edit= new EditBook(book);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));

 /* widget = new QWidget();

  QVBoxLayout* Book = new QVBoxLayout(widget);
  QFormLayout* BookForm = new QFormLayout(widget);
  Book->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLineEdit* Author = new QLineEdit;
  Author->setText(QString::fromStdString(book.getAuthor()));
  BookForm->addRow(("&Autore::"), Author);

  QLineEdit* PageNumber = new QLineEdit;
  Author->setText(QString::number(book.getPageNumber()));
  BookForm->addRow(("&Numero pagine:"), PageNumber);

  QLineEdit* Genre = new QLineEdit;
  Author->setText(QString::fromStdString(toString(book.getBookGenre())));
  BookForm->addRow(("&Genere:"), Genre);

  Book->addLayout(BookForm);*/

}

void ItemEditVisitor::visit(BookSerie *bookSerie) {
    EditBookSerie * edit= new EditBookSerie(bookSerie);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
  /*widget = new QWidget();

  QVBoxLayout *BookSerie = new QVBoxLayout(widget);
  QFormLayout* BookSeriesForm = new QFormLayout(widget);
  BookSerie->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLineEdit* VolumeNumber = new QLineEdit;
  VolumeNumber->setText(QString::number(bookSerie.getVolumeNumber()));
  BookSeriesForm->addRow(("&VolumeNumber:"), VolumeNumber);

  BookSerie->addLayout(BookSeriesForm);*/


}
void ItemEditVisitor::visit(Film *film) {
    EditFilm * edit= new EditFilm(film);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));

   /* widget = new QWidget();

    QVBoxLayout *Film = new QVBoxLayout(widget);
    QFormLayout* FilmForm = new QFormLayout(widget);
    Film->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    QLineEdit* Director = new QLineEdit;
    Director->setText(QString::fromStdString(film.getDirector()));
    FilmForm->addRow(("&Director:"), Director);

    QLineEdit* Duration = new QLineEdit;
    Duration->setText(QString::number(film.getDuration()));
    FilmForm->addRow(("&Duration:"), Duration);

    QLineEdit* FilmGenre = new QLineEdit;
    FilmGenre->setText(QString::fromStdString(toString(film.getFilmGenre())));
    FilmForm->addRow(("&Genere:"), FilmGenre);

    Film->addLayout(FilmForm);

*/
}

void ItemEditVisitor::visit(Videogame *videogame) {
    EditVideogame * edit= new EditVideogame(videogame);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
/*
  widget = new QWidget();

  QVBoxLayout *Videogame = new QVBoxLayout(widget);
  QFormLayout* VideoGameForm = new QFormLayout(widget);
  Videogame->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLineEdit* VideoGameGenre = new QLineEdit;
  VideoGameGenre->setText(QString::fromStdString(toString(videogame.getVGameGenre())));
  VideoGameForm->addRow(("&Genere:"), VideoGameGenre);

  Videogame->addLayout(VideoGameForm);
*/
}

void ItemEditVisitor::visit(BoardGame *boardGame) {
    EditBoardGame * edit= new EditBoardGame(boardGame);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
/*
  widget = new QWidget();

  QVBoxLayout *BoardGame = new QVBoxLayout(widget);
  QFormLayout* BoardGameForm = new QFormLayout(widget);
  BoardGame->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLineEdit* BGameGenre = new QLineEdit;
  BGameGenre->setText(QString::fromStdString(toString(boardGame.getBGameGenre())));
  BoardGameForm->addRow(("&Genere:"), BGameGenre);

  QLineEdit* PlayerNumber = new QLineEdit;
  PlayerNumber->setText(QString::number(boardGame.getPlayerNumber()));
  BoardGameForm->addRow(("&PlayerNumber:"), PlayerNumber);

  BoardGame->addLayout(BoardGameForm);

*/
}



QWidget *ItemEditVisitor::getWidget() { return widget; }

