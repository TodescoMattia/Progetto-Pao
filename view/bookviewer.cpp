#include "bookviewer.h"
#include "tabdialog.h"
#include <QtWidgets>

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

    QFrame* ItemList= new QFrame;

    QHBoxLayout* ImageLayout = new QHBoxLayout;
    ImageLayout->addWidget(new QLabel(this));

    ItemList->setStyleSheet("background-color: rgb(50,50,50)");
    ItemList->setLayout(ImageLayout);
    ItemList->layout()->setSpacing(0);
    ItemList->layout()->setAlignment(Qt::AlignCenter);
    ItemList->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    ScreenLayout->addWidget(ItemList);
    ScreenLayout->setSpacing(0);
    MainLayout->addLayout(ScreenLayout);
}

void BookViewer::TabDialogViewer(QVBoxLayout* MainLayout)
{
    QVBoxLayout* TabLayout = new QVBoxLayout;

    TabDialog TabDialog;

    QTabWidget* TabWidget = new QTabWidget;
    QTabWidget->addTab(TabDialog);


     MainLayout->addLayout(TabLayout);


     }

     BookViewer::BookViewer(QWidget *parent) : QWidget(parent){
         QVBoxLayout* MainLayout= new QVBoxLayout;

         BarraDeiMenu(MainLayout);

         Schermo(MainLayout);

         TabDialogViewer(MainLayout);

         MainLayout->setSpacing(0);

         resize(QSize(1024,720));

         setLayout(MainLayout);
     }
