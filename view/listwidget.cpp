#include "listwidget.h"
#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/film.h"
#include "../utils/list.h"
#include "../model/user.h"
#include "adduser.h"
#include "iteminfo.h"
#include "userinfo.h"

#include <QVBoxLayout>

ListWidget::ListWidget(const List<DeepPtr<Info>> & lista) : listInfo(lista) {

    List<DeepPtr<Info>>::Iterator start = listInfo.begin();
    List<DeepPtr<Info>>::Iterator end = listInfo.end();

    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setAlignment(Qt::AlignLeft | Qt::AlignTop);

    for (start = listInfo.begin(), end = listInfo.end(); start != end; start++) {
        ListView* singleElement = new ListView(&**start);
        listView.push_front(singleElement);
        layout->addWidget(singleElement->getWidget());
    }

}

