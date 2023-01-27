#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../model/item.h"
#include "../model/user.h"
#include "../model/list.h"
#include <QAction>
#include <QFrame>
#include <QHBoxLayout>
#include <QLabel>
#include <QMenu>
#include <QMenuBar>
#include <QPushButton>
#include <QString>
#include <QTabWidget>
#include <QVBoxLayout>
#include <QWidget>
#include "json.h"

class MainWindow : public QWidget {
  Q_OBJECT

private:
    QString path;
    Json * json;
    QVBoxLayout *MainLayout;
    List<Item *> listItem;
    List<User *> listUser;
    QTabWidget *tabWidget;

    void TabDialogViewer(QVBoxLayout *MainLayout);
    void BarraDeiMenu(QVBoxLayout *MainLayout);

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void refreshData();
    void save();
    void saveAs();
    void load();

};

#endif // MAINWINDOW_H
