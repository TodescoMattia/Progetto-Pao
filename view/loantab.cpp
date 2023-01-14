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

    QPushButton* addLoanButton= new QPushButton("Aggiungi prestito");
    vbox->addWidget(addLoanButton);

    QPushButton* expiredLoan= new QPushButton("Vedi prestiti scaduti");
    vbox->addWidget(expiredLoan);

    connect(addLoanButton, &QPushButton::clicked, this, LoanTab::createLoan);
}

void LoanTab::createLoan(){
    AddLoan* dialog= new AddLoan();

    connect(dialog,SIGNAL(accepted()),this,SLOT(confirm()));

    dialog->setModal(true);
    dialog->show();
}

void LoanTab::confirm(){
    AddLoan* dialog=dynamic_cast<AddLoan*>(sender());
    if(dialog==nullptr) return;

    QWidget* provo= new QWidget();

    QVBoxLayout* provo3 = new QVBoxLayout(provo);
    QLabel* provo2= new QLabel("yohohohhoho");
    provo3->addWidget(provo2);

    provo->show();

    //std::string name = dialog->getName().toStdString();
    //std::string surname = dialog->getName().toStdString();
    //std::string number = dialog->getName().toStdString();

    //momentaneo
    //listLoan.push_front(new Loan(name, surname, number));

}
