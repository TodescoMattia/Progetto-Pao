#ifndef JSON_H
#define JSON_H

#include "../utils/list.h"
#include "../model/item.h"
#include "../model/user.h"
#include "../utils/deepptr.h"

#include <QJsonObject>
#include <QJsonDocument>

class Json{

public:
    Json();

    //a json
    static void save(std::string path, List<DeepPtr<Item>>* items, List<DeepPtr<User>>* users);

    //da json
    QString selectJsonDialog();
    QJsonDocument* getData(const QString& path);

    void load(std::string path, List<DeepPtr<Item>>* items, List<DeepPtr<User>>* users);
    void loadItem(QJsonDocument* data, List<DeepPtr<Item>>* items);
    void loadUser(QJsonDocument* data, List<DeepPtr<User>>* users);
    DeepPtr<Item> loadBook(QJsonObject bookObj);
    DeepPtr<Item> loadBookSerie(QJsonObject bookSerieObj);
    DeepPtr<Item> loadFilm(QJsonObject filmObj);
    DeepPtr<Item> loadVideogame(QJsonObject videogameObj);
    DeepPtr<Item> loadBoardGame(QJsonObject boardGameObj);

};

#endif // JSON_H
