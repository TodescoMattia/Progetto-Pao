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
    virtual void visit(Book* book) override;
    virtual void visit(BookSerie* bookSerie) override;
    virtual void visit(Film* film) override;
    virtual void visit(Videogame* videogame) override;
    virtual void visit(BoardGame* boardGame) override;
};
#endif // ITEMEDITVISITOR_H
