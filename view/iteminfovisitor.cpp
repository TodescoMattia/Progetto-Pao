#include "iteminfovisitor.h"
#include <QLabel>
#include <QString>
#include "..\model\Book.h"
#include "..\model\BookSerie.h"
#include "..\model\Film.h"
#include "..\model\BoardGame.h"
#include "..\model\Videogame.h"

QWidget* ItemInfoVisitor::getWidget(){
    return widget;
}

void ItemInfoVisitor::visit(Book &book){
    widget=new QLabel("Autore: " + QString::fromStdString(book.getAuthor()));
    widget=new QLabel("Pagine: " + QString::number(book.getPageNumber()));
    widget=new QLabel("Genere: " + QString::fromStdString(toString(book.getBookGenre())));
}

void ItemInfoVisitor::visit(BookSerie &bookSerie){
    widget=new QLabel("Numero volume: " + QString::number(bookSerie.getVolumeNumber()));
}

void ItemInfoVisitor::visit(Film &film){
    widget=new QLabel("Regista: " + QString::fromStdString(film.getDirector()));
    widget=new QLabel("Durata: " + QString::number(film.getDuration()));
    widget=new QLabel("Genere: " + QString::fromStdString(toString(film.getFilmGenre())));
}

void ItemInfoVisitor::visit(Videogame &videogame){
    widget=new QLabel("Genere: " + QString::fromStdString(toString(videogame.getVGameGenre())));
}

void ItemInfoVisitor::visit(BoardGame &boardGame){
    widget=new QLabel("Genere: " + QString::fromStdString(toString(boardGame.getBGameGenre())));
}
