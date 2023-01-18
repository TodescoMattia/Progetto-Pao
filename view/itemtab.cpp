#include "itemtab.h"

#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/film.h"
#include "../model/genre.h"
#include "../model/videogame.h"
#include "../model/boardgame.h"
#include "additem.h"
#include "iteminfo.h"
#include "listwidget.h"

#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>

ItemTab::ItemTab(List<Item *>* lista, MainWindow * mainWindow) : listItem(lista), mainWindow(mainWindow) {

    // Creates widgets
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel *titleLabel = new QLabel("Elenco oggetti ");

    titleLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(titleLabel);

    //Creo Info

    List<Item*>::Iterator start = listItem->begin();
    List<Item*>::Iterator end = listItem->end();

    List<Info*> listInfo = *(new List<Info *>);

    for (start = listItem->begin(), end = listItem->end(); start != end; start++) {
        Info* info= new ItemInfo(*start, mainWindow);
        listInfo.push_front(info);
    }

    ListWidget *itemList = new ListWidget(listInfo);

    QScrollArea *scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(itemList);

    vbox->addWidget(scrollArea);

    QPushButton *addItemButton = new QPushButton("Aggiungi oggetto");
    vbox->addWidget(addItemButton);

    connect(addItemButton, &QPushButton::clicked, this, &ItemTab::selectItem);
}

void ItemTab::selectItem() {
    itemSelector = new AddItemSelector();

    itemSelector->setModal(true);
    itemSelector->show();

    connect(itemSelector, SIGNAL(accepted()), this, SLOT(createItem()));

    // connect(dialog, &AddItem::refreshItemTab, this, &ItemTab::refreshItemTab);
    }

void ItemTab::createItem() {
    AddItem *dialog = new AddItem(itemSelector);
    connect(dialog, SIGNAL(accepted()), this, SLOT(confirm()));

    dialog->setModal(true);
    dialog->show();
}

void ItemTab::confirm() {
    AddItem *dialog = dynamic_cast<AddItem *>(sender());
    if (dialog == nullptr)
    return;

    std::string id = dialog->getId().toStdString();
    std::string title = dialog->getTitle().toStdString();
    bool isLent = static_cast<bool>(dialog->getIsLent());

    switch (dialog->getSelectedType()) {
    case 0: {

        std::string authorBook = dialog->getAuthor().toStdString();
        int pageNumberBook = dialog->getPageNumber();
        Genre genreBook = toGenre(dialog->getGenre());
        listItem->push_front(new Book(id, title, isLent, authorBook, pageNumberBook, genreBook));

        break;
    }
    case 1: {

        std::string authorBookSerie = dialog->getAuthor().toStdString();
        int pageNumber = dialog->getPageNumber();
        Genre genreBookSerie = toGenre(dialog->getGenre());
        int volume = dialog->getVolumeNumber();
        listItem->push_front(new BookSerie(id, title, isLent, authorBookSerie, pageNumber, genreBookSerie, volume));

        break;
    }
    case 2: {

        std::string director = dialog->getDirector().toStdString();
        int duration = dialog->getDuration();
        Genre genreFilm = toGenre(dialog->getGenre());
        listItem->push_front(new Film(id, title, isLent, director, duration, genreFilm));

        break;
    }
    case 3: {

        Genre genreBoardGame = toGenre(dialog->getGenre());
        int playerNumber = dialog->getPlayerNumber();
        listItem->push_front(new BoardGame(id, title, isLent, genreBoardGame, playerNumber));

        break;
    }
    case 4: {

        Genre genreVideogame = toGenre(dialog->getGenre());
        listItem->push_front(new Videogame(id, title, isLent, genreVideogame));

        break;
    }
    }

    emit reload();

}

/*void ItemTab::refreshItemTab(){
    this->reloadData();
}*/

/*ItemTab& ItemTab::reloadData(){


    List<Item*> listItem2=*(new List<Item*>(listItem));
    listItem.clear();
    listItem=listItem2;

    return *this;
}*/
