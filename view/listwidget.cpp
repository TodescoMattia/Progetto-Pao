#include "listwidget.h"
#include "../model/book.h"
#include "../model/bookSerie.h"
#include "../model/film.h"
#include "../model/list.h"
#include "../model/user.h"
#include "adduser.h"
#include "iteminfo.h"
#include "userinfo.h"

#include <QVBoxLayout>

ListWidget::ListWidget(List<Info*>& lista): listInfo(lista) {
  // lista esempio, cancellami

    /*listView.push_front(*(new ListView(new ItemInfo(*(
        new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller))))));
    listView.push_front(*(new ListView(new ItemInfo(*(new BookSerie(
        "111AB6", "Harry Potter", true, "NomeAutore2", 352, Fantasy, 2))))));
    listView.push_front(*(new ListView(new ItemInfo(*(new Film(
        "563AB6", "Interstellar", false, "NomeDirettore", 160, Thriller))))));
    listView.push_front(
        *(new ListView(new UserInfo(*(new User("Mario", "Bianchi", "3458746715"))))));*/

    List<ListView>::Iterator inizio = listView.begin();
    List<ListView>::Iterator fine = listView.end();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    ListView* diocane = new ListView(new ItemInfo(*(
          new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller))));
    layout->addWidget(diocane->getWidget());

    for (inizio = listView.begin(), fine = listView.end(); inizio != fine; inizio++) {

      ListView* diocane = new ListView(new ItemInfo(*(
            new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller))));
      layout->addWidget(diocane);
    }
}

/*


  listInfo.push_front(new ItemInfo(*(
      new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller))));
  listInfo.push_front(new ItemInfo(*(new BookSerie(
      "111AB6", "Harry Potter", true, "NomeAutore2", 352, Fantasy, 2))));
  listInfo.push_front(new ItemInfo(*(new Film(
      "563AB6", "Interstellar", false, "NomeDirettore", 160, Thriller))));
  listInfo.push_front(
      (new UserInfo(*(new User("Mario", "Bianchi", "3458746715")))));

  List<Info*>::Iterator inizio = listInfo.begin();
  List<Info*>::Iterator fine = listInfo.end();

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  for (inizio = listInfo.begin(), fine = listInfo.end(); inizio != fine; inizio++) {

    QHBoxLayout *hbox = new QHBoxLayout();

    hbox->addWidget((*inizio)->getWidget());
    hbox->addStretch();

    editButton = new QPushButton("Modifica");
    deleteButton= new QPushButton("Elimina");

    //buttonBox->addButton(editButton, QDialogButtonBox::ActionRole);
    //buttonBox->addButton(deleteButton, QDialogButtonBox::ActionRole);


    //connect(buttonBox, SIGNAL(rejected()), this, SLOT(cancel()));

    //layout->addWidget(buttonBox);
    Info* info = *(inizio--);

    connect(editButton, &QPushButton::clicked, this,  clickEdit);
    connect(deleteButton, &QPushButton::clicked, this, clickDelete);

    hbox->addWidget(editButton);
    hbox->addWidget(deleteButton);

    layout->addLayout(hbox);*/


