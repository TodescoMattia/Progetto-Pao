#ifndef BOOKVIEWER_H
#define BOOKVIEWER_H

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



class BookViewer: public QWidget{
    Q_OBJECT

    void Schermo(QVBoxLayout* MainLayout);

    void TabDialogViewer (QVBoxLayout* MainLayout);

    void BarraDeiMenu(QVBoxLayout* MainLayout);

public:
    explicit BookViewer(QWidget *parent =nullptr);


signals:
};

#endif // BOOKVIEWER_H
