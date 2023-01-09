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



class MainWindow: public QWidget{
    Q_OBJECT
private:
    void Schermo(QVBoxLayout* MainLayout);
    void TabDialogViewer (QVBoxLayout* MainLayout);
    void BarraDeiMenu(QVBoxLayout* MainLayout);

public:
    explicit MainWindow(QWidget *parent =nullptr);

signals:
};

#endif // MAINWINDOW_H
