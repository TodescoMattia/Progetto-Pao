#include "homeviewer.h"
#include "mainwindow.h"

#include "itemtab.h"
#include "usertab.h"

#include "../model/book.h"
#include "../model/bookserie.h"
#include "../model/film.h"
#include "../model/list.h"
#include "../model/user.h"
#include "listview.h"
#include "userinfo.h"

#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QTabWidget>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  // HomeViewer w;

  QFile stylesheet(":/assets/stylesheet.qss");
  stylesheet.open(QFile::ReadOnly);
  app.setStyleSheet(QLatin1String(stylesheet.readAll()));

  MainWindow w;
  w.show();

  return app.exec();
}
