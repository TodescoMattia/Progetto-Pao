#include "edituser.h"
#include <QtWidgets>

EditUser::EditUser(QWidget *parent)
    : QWidget(parent)
{


    QLineEdit* Nameline = new QLineEdit;
    QLineEdit* SurnameLine = new QLineEdit;
    QLineEdit* NumberLine = new QLineEdit;



    QVBoxLayout* mainlayout = new QVBoxLayout;

        QFormLayout* FormLayout = new QFormLayout;

        FormLayout->addRow(tr("&Name:"), Nameline);
        FormLayout->addRow(tr("&Surname:"), SurnameLine);
        FormLayout->addRow(tr("&Number:"), NumberLine);




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
    setWindowTitle(tr("UserEdit"));
}
