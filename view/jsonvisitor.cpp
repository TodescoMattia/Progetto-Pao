#include "jsonvisitor.h"

#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/boardgame.h"
#include "../model/film.h"
#include "../model/videogame.h"

#include <QString>

QJsonObject JsonVisitor::getObject() const{
    return object;
}

void JsonVisitor::visit(Book* book) {

    QJsonObject bookObject;
    bookObject["type"] = "Book";
    bookObject["id"] = QString::fromStdString(book->getId());
    bookObject["title"] = QString::fromStdString(book->getTitle());
    bookObject["isLent"] = book->getState();
    bookObject["author"] = QString::fromStdString(book->getAuthor());
    bookObject["pageNumber"] = (int)book->getPageNumber();
    bookObject["genre"] = toInt(book->getBookGenre());

    object = bookObject;
}

void JsonVisitor::visit(BookSerie* bookSerie) {

    QJsonObject bookSerieObject;
    bookSerieObject["type"] = "BookSerie";
    bookSerieObject["id"] = QString::fromStdString(bookSerie->getId());
    bookSerieObject["title"] = QString::fromStdString(bookSerie->getTitle());
    bookSerieObject["isLent"] = (int)bookSerie->getState();
    bookSerieObject["author"] = QString::fromStdString(bookSerie->getAuthor());
    bookSerieObject["pageNumber"] = (int)bookSerie->getPageNumber();
    bookSerieObject["genre"] = toInt(bookSerie->getBookGenre());
    bookSerieObject["volumeNumber"] = (int)bookSerie->getVolumeNumber();

    object = bookSerieObject;
}

void JsonVisitor::visit(Film* film) {

    QJsonObject filmObject;
    filmObject["type"] = "Film";
    filmObject["id"] = QString::fromStdString(film->getId());
    filmObject["title"] = QString::fromStdString(film->getTitle());
    filmObject["isLent"] = (int)film->getState();
    filmObject["director"] = QString::fromStdString(film->getDirector());
    filmObject["duration"] = (int)film->getDuration();
    filmObject["genre"] = toInt(film->getFilmGenre());

    object = filmObject;
}

void JsonVisitor::visit(Videogame* videogame) {

    QJsonObject videogameObject;
    videogameObject["type"] = "Videogame";
    videogameObject["id"] = QString::fromStdString(videogame->getId());
    videogameObject["title"] = QString::fromStdString(videogame->getTitle());
    videogameObject["isLent"] = (int)videogame->getState();
    videogameObject["genre"] = toInt(videogame->getVGameGenre());

    object = videogameObject;
}

void JsonVisitor::visit(BoardGame* boardGame) {

    QJsonObject boardGameObject;
    boardGameObject["type"] = "BoardGame";
    boardGameObject["id"] = QString::fromStdString(boardGame->getId());
    boardGameObject["title"] = QString::fromStdString(boardGame->getTitle());
    boardGameObject["isLent"] = (int)boardGame->getState();
    boardGameObject["genre"] = toInt(boardGame->getBGameGenre());
    boardGameObject["playerNumber"] = (int)boardGame->getPlayerNumber();

    object = boardGameObject;
}
