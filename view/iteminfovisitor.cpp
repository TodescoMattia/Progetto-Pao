#include "iteminfovisitor.h"
#include "..\model\BoardGame.h"
#include "..\model\Book.h"
#include "..\model\BookSerie.h"
#include "..\model\Film.h"
#include "..\model\Videogame.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QString>

QWidget *ItemInfoVisitor::getWidget() { return widget; }

void ItemInfoVisitor::visit(Book &book) {

  widget = new QWidget();

  QHBoxLayout *infoBook = new QHBoxLayout(widget);
  infoBook->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLabel *authorLabel =
      new QLabel("Autore: " + QString::fromStdString(book.getAuthor()));
  infoBook->addWidget(authorLabel);

  QLabel *pageLabel =
      new QLabel("Pagine: " + QString::number(book.getPageNumber()));
  infoBook->addWidget(pageLabel);

  QLabel *genreLabel = new QLabel(
      "Genere: " + QString::fromStdString(toString(book.getBookGenre())));
  infoBook->addWidget(genreLabel);
}

void ItemInfoVisitor::visit(BookSerie &bookSerie) {

  widget = new QWidget();

  QHBoxLayout *infoBookSerie = new QHBoxLayout(widget);
  infoBookSerie->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLabel *volumeLabel = new QLabel(
      "Numero volume: " + QString::number(bookSerie.getVolumeNumber()));
  infoBookSerie->addWidget(volumeLabel);
}

void ItemInfoVisitor::visit(Film &film) {
  widget = new QWidget();

  QHBoxLayout *infoFilm = new QHBoxLayout(widget);
  infoFilm->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLabel *directorLabel =
      new QLabel("Regista: " + QString::fromStdString(film.getDirector()));
  infoFilm->addWidget(directorLabel);

  QLabel *durationLabel =
      new QLabel("Durata: " + QString::number(film.getDuration()));
  infoFilm->addWidget(durationLabel);

  QLabel *genreLabel = new QLabel(
      "Genere: " + QString::fromStdString(toString(film.getFilmGenre())));
  infoFilm->addWidget(genreLabel);
}

void ItemInfoVisitor::visit(Videogame &videogame) {

  widget = new QWidget();

  QHBoxLayout *infoVideogame = new QHBoxLayout(widget);
  infoVideogame->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLabel *genreLabel = new QLabel(
      "Genere: " + QString::fromStdString(toString(videogame.getVGameGenre())));
  infoVideogame->addWidget(genreLabel);
}

void ItemInfoVisitor::visit(BoardGame &boardGame) {

  widget = new QWidget();

  QHBoxLayout *infoBoardGame = new QHBoxLayout(widget);
  infoBoardGame->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  QLabel *genreLabel = new QLabel(
      "Genere: " + QString::fromStdString(toString(boardGame.getBGameGenre())));
  infoBoardGame->addWidget(genreLabel);
}
