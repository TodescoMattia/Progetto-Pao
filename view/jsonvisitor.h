#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "../model/visitor.h"
#include <QJsonObject>

class JsonVisitor: public Visitor{
private:
    QJsonObject object;

public:
    QJsonObject getObject() const;
    void visit(Book* book);
    void visit(BookSerie* bookserie);
    void visit(Film* film);
    void visit(BoardGame* boardgame);
    void visit(Videogame* videogame);
};

#endif // JSONVISITOR_H
