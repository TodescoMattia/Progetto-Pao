#include "mainwindow.h"
#include "itemtab.h"
#include "loantab.h"
#include "usertab.h"
#include <QTabWidget>
#include <QtWidgets>

void MainWindow::BarraDeiMenu(QVBoxLayout* MainLayout)
{
    QMenuBar* Menu= new QMenuBar(this);

    QMenu* file= new QMenu("File", Menu);
    Menu->addMenu(file);

    file->addAction(new QAction("Nuovo", file));
    file->addAction(new QAction("Importa", file));
    file->addAction(new QAction("Salva con nome", file));

    MainLayout->addWidget(Menu);
}

void MainWindow::Schermo(QVBoxLayout* MainLayout)
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

void MainWindow::TabDialogViewer(QVBoxLayout* MainLayout)
{
    QVBoxLayout* tabLayout = new QVBoxLayout;

    ItemTab* itemTab = new ItemTab();
    LoanTab* loanTab = new LoanTab();
    UserTab* userTab = new UserTab();

    QTabWidget* tabWidget = new QTabWidget();
    tabWidget->addTab(itemTab, "&Oggetti");
    tabWidget->addTab(loanTab, "&Prestiti");
    tabWidget->addTab(userTab, "&Utenti");

    tabLayout->addWidget(tabWidget);

    MainLayout->addLayout(tabLayout);


}

MainWindow::MainWindow(QWidget *parent) : QWidget(parent){
    QVBoxLayout* MainLayout= new QVBoxLayout;

    BarraDeiMenu(MainLayout);

    //Schermo(MainLayout);
    //A cosa serviva questa?

    TabDialogViewer(MainLayout);

    MainLayout->setSpacing(0);

    resize(QSize(1024,720));

    setLayout(MainLayout);
}
