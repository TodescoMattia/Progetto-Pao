#include "mainwindow.h"
#include "itemtab.h"
#include "usertab.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {
  QVBoxLayout *MainLayout = new QVBoxLayout;

  BarraDeiMenu(MainLayout);

  // Schermo(MainLayout);
  // A cosa serviva questa?

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

  listItem = *(new List<Item*>());

  ItemTab *itemTab = new ItemTab(listItem);
  UserTab *userTab = new UserTab();

  tabWidget = new QTabWidget();
  tabWidget->insertTab(0, itemTab, "&Oggetti");
  tabWidget->insertTab(1, userTab, "&Utenti");

  tabLayout->addWidget(tabWidget);

  MainLayout->addLayout(tabLayout);

  connect(itemTab, SIGNAL(reload()), this, SLOT(refreshData()));
}

MainWindow& MainWindow::refreshData(){
    tabWidget->clear();

    //momentaneo

    List<Item*> listItem2=*(new List<Item*>(listItem));
    listItem.clear();
    listItem=listItem2;

    QVBoxLayout *tabLayout = new QVBoxLayout();

    ItemTab * itemTab = new ItemTab(listItem);
    UserTab *userTab = new UserTab();

   // tabWidget = new QTabWidget();
    tabWidget->insertTab(0, itemTab, "&Oggetti");
    tabWidget->insertTab(1, userTab, "&Utenti");

    tabLayout->addWidget(tabWidget);

   return *this;
}


