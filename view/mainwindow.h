#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <Qstring>
#include <QTabWidget>
#include "..\model\list.h"
#include "..\model\item.h"



class MainWindow: public QWidget{
    Q_OBJECT
private:
    List<Item*> listItem;
    QTabWidget *tabWidget;
    void Schermo(QVBoxLayout* MainLayout);
    void TabDialogViewer (QVBoxLayout* MainLayout);
    void BarraDeiMenu(QVBoxLayout* MainLayout);

public:
    explicit MainWindow(QWidget *parent =nullptr);

public slots:
    MainWindow& refreshData();
signals:
};

#endif // MAINWINDOW_H
