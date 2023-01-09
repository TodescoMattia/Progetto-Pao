#include "loantab.h"

#include "listwidget.h"

#include<QLabel>
#include<QScrollArea>
#include <QVBoxLayout>

LoanTab::LoanTab()
{
    // Creates widgets
    QVBoxLayout* vbox = new QVBoxLayout(this);
    vbox->setAlignment(Qt::AlignHCenter | Qt::AlignTop);

    QLabel* titleLabel = new QLabel("Elenco prestiti ");
    //titleLabel->setObjectName("title");
    titleLabel->setAlignment(Qt::AlignHCenter);
    vbox->addWidget(titleLabel);

    ListWidget* loanList=new ListWidget();

    QScrollArea* scrollArea = new QScrollArea();
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    scrollArea->setWidgetResizable(true);
    scrollArea->setWidget(loanList);

    vbox->addWidget(scrollArea);

    QPushButton* addLoan= new QPushButton("Aggiungi prestito");
    vbox->addWidget(addLoan);

    QPushButton* expiredLoan= new QPushButton("Vedi prestiti scaduti");
    vbox->addWidget(expiredLoan);


}
