
#include "itemeditvisitor.h"
#include "../model/boardgame.h"
#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/film.h"
#include "../model/videogame.h"
#include <QLineEdit>
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
}

void ItemEditVisitor::visit(BookSerie *bookSerie) {
    EditBookSerie * edit= new EditBookSerie(bookSerie);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
}

void ItemEditVisitor::visit(Film *film) {
    EditFilm * edit= new EditFilm(film);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
}

void ItemEditVisitor::visit(Videogame *videogame) {
    EditVideogame * edit= new EditVideogame(videogame);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
}

void ItemEditVisitor::visit(BoardGame *boardGame) {
    EditBoardGame * edit= new EditBoardGame(boardGame);
    edit->setModal(true);
    edit->show();
    QObject::connect(edit, SIGNAL(accepted()), mainWindow, SLOT(refreshData()));
}

QWidget *ItemEditVisitor::getWidget() { return widget; }

