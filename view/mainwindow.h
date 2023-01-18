#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "../model/item.h"
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

class MainWindow : public QWidget {
  Q_OBJECT
private:
  QVBoxLayout *MainLayout;
  List<Item *> listItem;
  QTabWidget *tabWidget;
  void Schermo(QVBoxLayout *MainLayout);
  void TabDialogViewer(QVBoxLayout *MainLayout);
  void BarraDeiMenu(QVBoxLayout *MainLayout);

public:
  explicit MainWindow(QWidget *parent = nullptr);

public slots:
  void refreshData();
signals:
};

#endif // MAINWINDOW_H
