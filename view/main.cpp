#include "homeviewer.h"
#include "mainwindow.h"

#include "itemtab.h"
#include "usertab.h"

#include "..\model\Book.h"
#include "..\model\BookSerie.h"
#include "..\model\Film.h"
#include "..\model\List.h"
#include "..\model\User.h"
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
