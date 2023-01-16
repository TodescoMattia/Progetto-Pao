#include "listwidget.h"
#include "..\model\book.h"
#include "..\model\bookSerie.h"
#include "..\model\film.h"
#include "..\model\list.h"
#include "..\model\user.h"
#include "adduser.h"
#include "iteminfo.h"
#include "userinfo.h"

#include <QVBoxLayout>

ListWidget::ListWidget(List<Info*>& lista): listInfo(lista) {

  // lista esempio, cancellami

  listView.push_front(ListView(new ItemInfo(*(
      new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller)))));
  listView.push_front(ListView(new ItemInfo(*(new BookSerie(
      "111AB6", "Harry Potter", true, "NomeAutore2", 352, Fantasy, 2)))));
  listView.push_front(ListView(new ItemInfo(*(new Film(
      "563AB6", "Interstellar", false, "NomeDirettore", 160, Thriller)))));
  listView.push_front(
      ListView(new UserInfo(*(new User("Mario", "Bianchi", "3458746715")))));

  List<ListView>::Iterator inizio = listView.begin();
  List<ListView>::Iterator fine = listView.end();

  QVBoxLayout *layout = new QVBoxLayout(this);
  layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

  for (inizio = listView.begin(), fine = listView.end(); inizio != fine; inizio++) {

    layout->addWidget((*inizio).getWidget());
  }
}

/*
void ListWidget::addUser(){
    QWidget* addUserWindow = new QWidget;

    QVBoxLayout* addUserLayout = new QVBoxLayout(addUserWindow);

    /*AddUser* addUserWidget= new AddUser();

    addUserLayout->addWidget(addUserWidget->getWidget());

    addUserWindow->show();
}

void ListWidget::addItem(){
    QWidget* addUserWindow = new QWidget;



    addUserWindow->show();
}
*/
