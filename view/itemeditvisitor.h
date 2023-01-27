#ifndef ITEMEDITVISITOR_H
#define ITEMEDITVISITOR_H


#include <QWidget>
#include "../model/visitor.h"
#include "mainwindow.h"

class ItemEditVisitor: public Visitor{

private:
    QWidget* widget;
    MainWindow* mainWindow;

public:
    ItemEditVisitor(MainWindow* mainWindow);
    QWidget* getWidget();
    virtual void visit(Book* book);
    virtual void visit(BookSerie* bookSerie);
    virtual void visit(Film* film);
    virtual void visit(Videogame* videogame);
    virtual void visit(BoardGame* boardGame);
};
#endif // ITEMEDITVISITOR_H
