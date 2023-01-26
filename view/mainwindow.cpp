#include "mainwindow.h"
#include "itemtab.h"
#include "usertab.h"

#include <QtWidgets>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

  MainLayout = new QVBoxLayout;

  BarraDeiMenu(MainLayout);

  listItem = *(new List<Item*>());

  tabWidget = new QTabWidget();

  TabDialogViewer(MainLayout);

  MainLayout->setSpacing(0);

  resize(QSize(1024, 720));

  setLayout(MainLayout);
}

void MainWindow::BarraDeiMenu(QVBoxLayout *MainLayout) {

    QGroupBox* buttonGroupBox = new QGroupBox;

    QPushButton* saveAsButton = new QPushButton("Salva con nome");
    connect(saveAsButton, &QPushButton::clicked, this, &MainWindow::saveAs);

    QPushButton* saveButton = new QPushButton("Salva");
    connect(saveButton, &QPushButton::clicked, this, &MainWindow::save);

    QPushButton* loadButton = new QPushButton("Carica");
    connect(loadButton, &QPushButton::clicked, this, &MainWindow::load);

        QHBoxLayout *layout = new QHBoxLayout;

            layout->addWidget(saveAsButton);
            layout->addWidget(saveButton);
            layout->addWidget(loadButton);

    buttonGroupBox->setLayout(layout);

    MainLayout->addWidget(buttonGroupBox);
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

    ItemTab *itemTab = new ItemTab(&listItem, this);
    UserTab *userTab = new UserTab(&listUser, this);


    tabWidget->insertTab(0, itemTab, "&Oggetti");
    tabWidget->insertTab(1, userTab, "&Utenti");

    tabLayout->addWidget(tabWidget);

    MainLayout->addLayout(tabLayout);

    connect(itemTab, SIGNAL(reload()), this, SLOT(refreshData()));
}

void MainWindow::refreshData(){
    tabWidget->clear();

    //momentaneo

    List<Item*> listItem2 = List<Item*>(listItem);
    listItem.clear();
    listItem = listItem2;

    List<User*> listUser2 = List<User*>(listUser);
    listUser.clear();
    listUser = listUser2;


    this->TabDialogViewer(MainLayout);

   //return *this;
}

void MainWindow::save(){
    if (path.isEmpty()){
        saveAs();
        return;
    }

    json->save(path.toStdString(), &listItem, &listUser);
}

void MainWindow::saveAs(){
    QString pathTemp = QFileDialog::getSaveFileName(
        this,
        "Creates new Dataset",
        "./" + path,
        "JSON files *.json"
    );

    if(pathTemp.isEmpty()){
        return;
    }

    path = pathTemp;

    json->save(path.toStdString(), &listItem, &listUser);
}

void MainWindow::load(){
    path = QFileDialog::getOpenFileName(
        this,
        "Creates new Dataset",
        "./",
        "JSON files *.json"
    );

    if (path.isEmpty()) {
        return;
    }

    listItem.clear();
    listUser.clear();

    json->load(path.toStdString(), &listItem, &listUser);

    this->refreshData();
}
