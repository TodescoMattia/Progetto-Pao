#include "editloan.h"
#include <QtWidgets>

EditLoan::EditLoan(QWidget *parent)
    : QWidget(parent)
{


    QLineEdit* ID = new QLineEdit;
    QSpinBox* EndDay  = new QSpinBox;
    QSpinBox* EndMonth = new QSpinBox;
    QSpinBox* EndYear = new QSpinBox;

    EndDay->setMinimum(1);
    EndDay->setMaximum(31);
    EndDay->setSingleStep(1);
    EndDay->setValue(1);

    EndMonth->setMinimum(1);
    EndMonth->setMaximum(12);
    EndMonth->setSingleStep(1);
    EndMonth->setValue(1);

    EndYear->setMinimum(2023);
    EndYear->setMaximum(3000);
    EndYear->setSingleStep(1);
    EndYear->setValue(2023);

    QVBoxLayout* mainlayout = new QVBoxLayout;

        QFormLayout* FormLayout = new QFormLayout;

        FormLayout->addRow(tr("&ID:"), ID);
        FormLayout->addRow(tr("&EndDay:"), EndDay);
        FormLayout->addRow(tr("&EndMonth:"), EndMonth);
        FormLayout->addRow(tr("&EndYear:"), EndYear);





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

