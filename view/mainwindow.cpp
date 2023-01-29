#include "mainwindow.h"
#include "itemtab.h"
#include "usertab.h"

#include <QtWidgets>
#include <QApplication>
#include <QAction>
#include <QFileDialog>
#include <QIcon>

MainWindow::MainWindow(QWidget *parent) : QWidget(parent) {

    mainLayout = new QVBoxLayout;

    menuBar(mainLayout);

    tabWidget = new QTabWidget();

    tabViewer(mainLayout);

    mainLayout->setSpacing(0);
    resize(QSize(1024, 720));

    setLayout(mainLayout);
}

void MainWindow::menuBar(QVBoxLayout *MainLayout) {

    QMenuBar *Menu = new QMenuBar(this);

    QMenu *file = new QMenu("File", Menu);

    Menu->addMenu(file);

    QAction* load = new QAction(
        QIcon(QPixmap(":/assets/icons/open.svg")), "Carica");

    QAction* save = new QAction(
        QIcon(QPixmap(":/assets/icons/save.svg")), "Salva");

    QAction* saveAs = new QAction(
        QIcon(QPixmap(":/assets/icons/save_as.svg")), "Salva con nome");

    file->addAction(load);
    file->addAction(save);
    file->addAction(saveAs);

    load->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_C));
    save->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_S));
    saveAs->setShortcut(QKeySequence(Qt::CTRL | Qt::SHIFT | Qt::Key_S));

    connect(load, &QAction::triggered, this, &MainWindow::load);
    connect(save, &QAction::triggered, this, &MainWindow::save);
    connect(saveAs, &QAction::triggered, this, &MainWindow::saveAs);

    MainLayout->addWidget(Menu);

    QGroupBox *horizontalGroupBox = new QGroupBox();

    QPushButton* loadButton = new QPushButton(
                QIcon(QPixmap(":/assets/icons/open.svg")), "Carica");

    connect(loadButton, &QPushButton::clicked, this, &MainWindow::load);

    QPushButton* saveAsButton = new QPushButton(
                QIcon(QPixmap(":/assets/icons/save_as.svg")), "Salva con nome");

    connect(saveAsButton, &QPushButton::clicked, this, &MainWindow::saveAs);

    QPushButton* saveButton = new QPushButton(
                QIcon(QPixmap(":/assets/icons/save.svg")), "Salva");

    connect(saveButton, &QPushButton::clicked, this, &MainWindow::save);

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(loadButton);
    layout->addWidget(saveAsButton);
    layout->addWidget(saveButton);

    horizontalGroupBox->setLayout(layout);

    MainLayout->addWidget(horizontalGroupBox);

}

void MainWindow::tabViewer(QVBoxLayout *MainLayout, int index) {

    QVBoxLayout *tabLayout = new QVBoxLayout;

    ItemTab *itemTab = new ItemTab(&listItem, this);
    UserTab *userTab = new UserTab(&listUser, this);

    tabWidget->insertTab(0, itemTab, "&Oggetti");
    tabWidget->insertTab(1, userTab, "&Utenti");
    tabWidget->setCurrentIndex(index);

    tabLayout->addWidget(tabWidget);

    MainLayout->addLayout(tabLayout);
}


void MainWindow::refreshItem(){
    tabWidget->clear();
    this->tabViewer(mainLayout,0);
}

void MainWindow::refreshUser(){
    tabWidget->clear();
    this->tabViewer(mainLayout,1);
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
    QString pathTemp = QFileDialog::getOpenFileName(
        this,
        "Creates new Dataset",
        "./",
        "JSON files *.json"
    );

    if (pathTemp.isEmpty()) {
        return;
    }

    path = pathTemp;

    listItem.clear();
    listUser.clear();

    json->load(path.toStdString(), &listItem, &listUser);
    this->refreshItem();
}
