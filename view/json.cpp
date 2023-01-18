#include "json.h"


#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/boardgame.h"
#include "../model/film.h"
#include "../model/videogame.h"
#include "jsonvisitor.h"

#include <QFileDialog>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QFile>
#include <QString>
#include <QIODevice>

Json::Json()
{

}

QString Json::selectJsonDialog(){
    QFileDialog dialog;
    dialog.setFileMode(QFileDialog::ExistingFile);
    dialog.setNameFilter("JSON File (*.json)");
    QString fileName;

    if (dialog.exec())
        fileName = dialog.selectedFiles().at(0);
    return fileName;
}

QJsonDocument* Json::getData(const QString& path){
    if(path.isNull()) return new QJsonDocument();

    QString fileData;
    QFile file;

    file.setFileName(path);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileData = file.readAll();
    file.close();

    //Controllo validità documento
    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(fileData.toLocal8Bit()));
    QJsonObject dataObj = doc->object();
    if(!dataObj.contains("user") || !dataObj.contains("item")){
        delete doc;
        return new QJsonDocument();
    }
    return doc;
}

void Json::load(std::string path, List<Item*>* items, List<User*>* users){

    QString fileData;
    QFile file;

    file.setFileName(QString::fromStdString(path));
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    fileData = file.readAll();
    file.close();

    QJsonDocument* doc = new QJsonDocument(QJsonDocument::fromJson(fileData.toLocal8Bit()));

    loadItem(doc, items);

    //loadUser(doc, users);

}
void Json::save(std::string path, List<Item*>* items, List<User*>* users){

    if (items) {

        QJsonArray itemArray;

        List<Item*>::Iterator start= items->begin();

        for(start = items->begin(); start!=items->end();start++){
            JsonVisitor visitor;
            (*start)->accept(visitor);
            itemArray.push_back(visitor.getObject());
        }
        QJsonObject itemsObj;
        itemsObj ["Item"] = itemArray;

        QJsonDocument saveDoc(itemsObj);

        QFile saveFile(path.c_str());
        if (saveFile.open(QIODevice::WriteOnly)) {
            saveFile.write(saveDoc.toJson());
        }
    }


}

void Json::loadItem(QJsonDocument* data, List<Item*>* items){
    //List<Item*> items;
    QJsonObject dataObj = data->object();

    QJsonArray itemObj =dataObj["Item"].toArray();

    QJsonArray::Iterator start = itemObj.begin();

    for(start=itemObj.begin(); start!=itemObj.end();start++){

        QJsonObject obj= start->toObject();

        if (obj["type"].toString() == QString("Book")){
            items->push_back(loadBook(obj));

        }else if (obj["type"].toString() == QString("BookSerie")){
            items->push_back(loadBookSerie(obj));

        }else if (obj["type"].toString() == QString("Film")){
            items->push_back(loadFilm(obj));

        }else if (obj["type"].toString() == QString("BoardGame")){
            items->push_back(loadBoardGame(obj));

        }else if (obj["type"].toString() == QString("Videogame")){
            items->push_back(loadVideogame(obj));
        }
    }
}

void Json::loadUser(QJsonDocument* data, List<User*>* users){

    //List<User*> users;
    QJsonObject dataObj = data->object();
    QJsonObject userObj = dataObj["User"].toObject();

    QJsonObject::Iterator start = userObj.begin();
    for(start=userObj.begin(); start!=userObj.end();start++){

        User* user= new User(
            userObj.value("name").toString().toStdString(),
            userObj.value("surname").toString().toStdString(),
            userObj.value("number").toString().toStdString()
        );

        users->push_back(user);
    }
}


Item* Json::loadBook(QJsonObject bookObj){

    Book* book= new Book(
        bookObj.value("id").toString().toStdString(),
        bookObj.value("title").toString().toStdString(),
        bookObj.value("isLent").toBool(),
        bookObj.value("author").toString().toStdString(),
        bookObj.value("pageNumber").toInt(),
        toGenre(bookObj.value("genre").toInt())
    );
    return book;
}

Item* Json::loadBookSerie(QJsonObject bookSerieObj){

    BookSerie* bookseries= new BookSerie(
        bookSerieObj.value("id").toString().toStdString(),
        bookSerieObj.value("title").toString().toStdString(),
        bookSerieObj.value("isLent").toBool(),
        bookSerieObj.value("author").toString().toStdString(),
        bookSerieObj.value("pageNumber").toInt(),
        toGenre(bookSerieObj.value("genre").toInt()),
        bookSerieObj.value("volumeNumber").toInt()
    );
    return bookseries;
}

Item* Json::loadFilm(QJsonObject filmObj){
    Film* film= new Film(
        filmObj.value("id").toString().toStdString(),
        filmObj.value("title").toString().toStdString(),
        filmObj.value("isLent").toBool(),
        filmObj.value("director").toString().toStdString(),
        filmObj.value("duration").toInt(),
        toGenre(filmObj.value("genre").toInt())
    );
    return film;
}

Item* Json::loadVideogame(QJsonObject videogameObj){
    Videogame* videoGame= new Videogame(
        videogameObj.value("id").toString().toStdString(),
        videogameObj.value("title").toString().toStdString(),
        videogameObj.value("isLent").toBool(),
        toGenre(videogameObj.value("genre").toInt())
    );
    return videoGame;
}

Item* Json::loadBoardGame(QJsonObject boardGameObj){
    BoardGame* boardGame= new BoardGame(
        boardGameObj.value("id").toString().toStdString(),
        boardGameObj.value("title").toString().toStdString(),
        boardGameObj.value("isLent").toBool(),
        toGenre(boardGameObj.value("genre").toInt()),
        boardGameObj.value("pageNumber").toInt()
    );
    return boardGame;
}
