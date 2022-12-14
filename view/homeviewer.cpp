#include "homeviewer.h"

void Homeviewer::Schermata_principale(QVBoxLayout* MainLayout){

   QVBoxLayout* ScreenLayout = new QVBoxLayout;

   ScreenLayout->setSpacing(0);
   //ScreenLayout->setMargin(0);


   ScreenLayout->addLayout(createDescriptionLayout(tr(
                               "  DESCRIZIONE DA METTERE")));
   MainLayout->addLayout(ScreenLayout);

}

void Homeviewer::Bottoni(QVBoxLayout* MainLayout){
   QHBoxLayout* controlsLayout = new QHBoxLayout;

   QHBoxLayout* ButtonLayout = new QHBoxLayout;

   QPushButton* Nuovo = new QPushButton("Nuovo Progetto");
   QPushButton* Importa = new QPushButton("Importa Progetto");

   ButtonLayout->addWidget(Nuovo);
   ButtonLayout->addWidget(Importa);
   ButtonLayout->setSpacing(5);
   ButtonLayout->setContentsMargins(25, 0, 25, 0);


   controlsLayout->addLayout(ButtonLayout);

   controlsLayout->setSpacing(0);
   controlsLayout->setContentsMargins(0,10,0,0);

   MainLayout->addLayout(controlsLayout);
}



QLayout* Homeviewer::createDescriptionLayout(const QString& description){

   QVBoxLayout* descrLayout = new QVBoxLayout;

   //Descrizione
   QLabel* desc = new QLabel(description,this);
   QFont f("Times New Roman", 15);
   desc->setFont(f);

   descrLayout->addWidget(desc,Qt::AlignRight);

   QHBoxLayout* groupLayout = new QHBoxLayout;
  // groupLayout->setMargin(10);
   groupLayout->setSpacing(25);
   groupLayout->setContentsMargins(0, 0, 0, 0);

   QGroupBox* gruppo = new QGroupBox("Mattia Todesco -- Silvia Rovea",this);
   gruppo->setLayout(descrLayout);
   groupLayout->addWidget(gruppo);

   gruppo->setStyleSheet("background-color: #c0c0c0 ");

   return groupLayout;

}


Homeviewer::Homeviewer(QWidget *parent) : QWidget(parent){
   QVBoxLayout* MainLayout= new QVBoxLayout;

   Schermata_principale(MainLayout);

   Bottoni(MainLayout);

   MainLayout->setSpacing(0);

   resize(QSize(1024,720));

   setLayout(MainLayout);
}
