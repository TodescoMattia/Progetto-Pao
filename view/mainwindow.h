#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../model/item.h"
#include "../model/user.h"
#include "../utils/list.h"
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
#include "../utils/deepptr.h"

class MainWindow : public QWidget {
  Q_OBJECT

private:
    QString path;
    Json * json;
    QVBoxLayout *mainLayout;
    List<DeepPtr<Item>> listItem;
    List<DeepPtr<User>> listUser;
    QTabWidget *tabWidget;

    void tabViewer(QVBoxLayout *MainLayout, int index=0);
    void menuBar(QVBoxLayout *MainLayout);

public:
    explicit MainWindow(QWidget *parent = nullptr);

public slots:
    void refreshItem();
    void refreshUser();
    void save();
    void saveAs();
    void load();

};

#endif // MAINWINDOW_H
