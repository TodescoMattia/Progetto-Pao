#ifndef JSON_H
#define JSON_H

#include "../model/list.h"
#include "../model/item.h"
#include "../model/user.h"

#include <QJsonObject>
#include <QJsonDocument>

class Json{

public:
    Json();

    //a json
    static void save(std::string path, List<Item*>* items, List<User*>* users);

    //da json
    QString selectJsonDialog();
    QJsonDocument* getData(const QString& path);

    void load(std::string path, List<Item*>* items, List<User*>* users);
    void loadItem(QJsonDocument* data, List<Item*>* items);
    void loadUser(QJsonDocument* data, List<User*>* users);
    Item* loadBook(QJsonObject bookObj);
    Item* loadBookSerie(QJsonObject bookSerieObj);
    Item* loadFilm(QJsonObject filmObj);
    Item* loadVideogame(QJsonObject videogameObj);
    Item* loadBoardGame(QJsonObject boardGameObj);

};

#endif // JSON_H
