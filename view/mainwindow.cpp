#include "mainwindow.h"
#include "itemtab.h"
#include "usertab.h"
#include "../model/book.h"
#include "../model/genre.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  MainLayout = new QVBoxLayout;

  BarraDeiMenu(MainLayout);

  // Schermo(MainLayout);
  // A cosa serviva questa? cancellami

  listItem = *(new List<Item*>());

  tabWidget = new QTabWidget();

  TabDialogViewer(MainLayout);

  MainLayout->setSpacing(0);

  resize(QSize(1024, 720));

  setLayout(MainLayout);
}

void MainWindow::BarraDeiMenu(QVBoxLayout *MainLayout) {
    QMenuBar *Menu = new QMenuBar(this);

    QMenu *file = new QMenu("File", Menu);
    Menu->addMenu(file);

    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Importa", file));
    file->addAction(new QAction("Salva con nome", file));



    MainLayout->addWidget(Menu);
}

void MainWindow::Schermo(QVBoxLayout *MainLayout) {
    QVBoxLayout *ScreenLayout = new QVBoxLayout;

    QFrame *ItemList = new QFrame;

    QHBoxLayout *ImageLayout = new QHBoxLayout;
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

void MainWindow::TabDialogViewer(QVBoxLayout *MainLayout) {
    QVBoxLayout *tabLayout = new QVBoxLayout;

    //listItem.push_front(new Book("123AB6", "Fight Club", false, "NomeAutore", 582, Thriller));

    ItemTab *itemTab = new ItemTab(&listItem, this);
    UserTab *userTab = new UserTab();


    tabWidget->insertTab(0, itemTab, "&Oggetti");
    tabWidget->insertTab(1, userTab, "&Utenti");

    tabLayout->addWidget(tabWidget);

    MainLayout->addLayout(tabLayout);

    connect(itemTab, SIGNAL(reload()), this, SLOT(refreshData()));
}

void MainWindow::refreshData(){
    tabWidget->clear();

    //momentaneo

    List<Item*> listItem2= List<Item*>(listItem);
    listItem.clear();
    listItem=listItem2;


    this->TabDialogViewer(MainLayout);

   //return *this;
}


