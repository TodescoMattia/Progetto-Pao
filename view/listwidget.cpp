#include "listwidget.h"
#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/film.h"
#include "../model/list.h"
#include "../model/user.h"
#include "adduser.h"
#include "iteminfo.h"
#include "userinfo.h"

#include <QVBoxLayout>

ListWidget::ListWidget(const List<Info*> & lista) : listInfo(lista) {

    List<Info*>::Iterator start = listInfo.begin();
    List<Info*>::Iterator end = listInfo.end();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    for (start = listInfo.begin(), end = listInfo.end(); start != end; start++) {
        ListView* singleElement = new ListView(*start);
        listView.push_front(singleElement);
        layout->addWidget(singleElement->getWidget());
    }

}

