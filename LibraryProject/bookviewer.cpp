#include "bookviewer.h"

void BookViewer::BarraDeiMenu(QVBoxLayout* MainLayout)
{
    QMenuBar* Menu= new QMenuBar(this);

    QMenu* file= new QMenu("File", Menu);
    Menu->addMenu(file);

    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Importa", file));
    file->addAction(new QAction("Salva con nome", file));

    MainLayout->addWidget(Menu);
}

void BookViewer::Schermo(QVBoxLayout* MainLayout)
{
    QVBoxLayout* ScreenLayout = new QVBoxLayout;

    QFrame* listadeilibri= new QFrame;

    QHBoxLayout* ImageLayout = new QHBoxLayout;
    ImageLayout->addWidget(new QLabel(this));

    listadeilibri->setStyleSheet("background-color: rgb(50,50,50)");
    listadeilibri->setLayout(ImageLayout);
    listadeilibri->layout()->setSpacing(0);
    listadeilibri->layout()->setAlignment(Qt::AlignCenter);
    listadeilibri->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ScreenLayout->addWidget(listadeilibri);
    ScreenLayout->setSpacing(0);
    MainLayout->addLayout(ScreenLayout);
}

void BookViewer::Pulsanti(QVBoxLayout* MainLayout)
{
    QHBoxLayout* controlsLayout = new QHBoxLayout;

    QHBoxLayout* ButtonLayout = new QHBoxLayout;

    QPushButton* Aggiungi = new QPushButton("Aggiungi");
    QPushButton* Elimina = new QPushButton("Elimina");
    QPushButton* Cerca = new QPushButton("Cerca");
    QPushButton* Prestiti = new QPushButton("Prestiti");


    ButtonLayout->addWidget(Aggiungi);
    ButtonLayout->addWidget(Elimina);
    ButtonLayout->addWidget(Cerca);
    ButtonLayout->addWidget(Prestiti);
    ButtonLayout->setSpacing(50);
    ButtonLayout->setContentsMargins(25, 0, 25, 0);

    controlsLayout->addLayout(ButtonLayout);

    controlsLayout->setSpacing(150);
        controlsLayout->setContentsMargins(150, 25, 150, 25);

        MainLayout->addLayout(controlsLayout);
}

BookViewer::BookViewer(QWidget *parent) : QWidget(parent){
    QVBoxLayout* MainLayout= new QVBoxLayout;

    BarraDeiMenu(MainLayout);

    Schermo(MainLayout);

    Pulsanti(MainLayout);

    MainLayout->setSpacing(0);

    resize(QSize(1024,720));

    setLayout(MainLayout);
}
