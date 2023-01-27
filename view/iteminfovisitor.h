#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include <QWidget>
#include "../model/visitor.h"

class ItemInfoVisitor: public Visitor{

private:
    QWidget* widget;

public:
    QWidget* getWidget();
    virtual void visit(Book* book);
    virtual void visit(BookSerie* bookSerie);
    virtual void visit(Film* film);
    virtual void visit(Videogame* videogame);
    virtual void visit(BoardGame* boardGame);
};

#endif // ITEMINFOVISITOR_H
