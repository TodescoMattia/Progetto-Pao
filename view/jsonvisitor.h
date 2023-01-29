#ifndef JSONVISITOR_H
#define JSONVISITOR_H

#include "../model/visitor.h"
#include <QJsonObject>

class JsonVisitor: public Visitor{
private:
    QJsonObject object;

public:
    QJsonObject getObject() const;
    void visit(Book* book) override;
    void visit(BookSerie* bookserie) override;
    void visit(Film* film) override;
    void visit(BoardGame* boardgame) override;
    void visit(Videogame* videogame) override;
};

#endif // JSONVISITOR_H
