#include "listwidget.h"
#include "../utils/list.h"

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

