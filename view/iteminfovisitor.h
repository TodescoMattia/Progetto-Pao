#ifndef ITEMINFOVISITOR_H
#define ITEMINFOVISITOR_H

#include <QWidget>
#include "../model/visitor.h"

class ItemInfoVisitor: public Visitor{

private:
    QWidget* widget;

public:
    QWidget* getWidget();
    virtual void visit(Book* book) override;
    virtual void visit(BookSerie* bookSerie) override;
    virtual void visit(Film* film) override;
    virtual void visit(Videogame* videogame) override;
    virtual void visit(BoardGame* boardGame) override;
};

#endif // ITEMINFOVISITOR_H
