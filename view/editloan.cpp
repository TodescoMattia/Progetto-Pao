#include "editloan.h"
#include <QtWidgets>

EditLoan::EditLoan(QWidget *parent)
    : QWidget(parent)
{


    QLineEdit* ID = new QLineEdit;
    QLineEdit* EndDate = new QLineEdit;




    QVBoxLayout* mainlayout = new QVBoxLayout;

        QFormLayout* FormLayout = new QFormLayout;

        FormLayout->addRow(tr("&ID:"), ID);
        FormLayout->addRow(tr("&EndDate:"), EndDate);




    QHBoxLayout* ButtonLayout = new QHBoxLayout;

    QPushButton* Salva = new QPushButton("Salva");
    QPushButton* Annulla = new QPushButton("Annulla");

    ButtonLayout->addWidget(Salva);
    ButtonLayout->addWidget(Annulla);
    ButtonLayout->setSpacing(5);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);


    mainlayout->addLayout(FormLayout);
    mainlayout->addLayout(ButtonLayout);


    setLayout(mainlayout);
    setWindowTitle(tr("LoanEdit"));
}

