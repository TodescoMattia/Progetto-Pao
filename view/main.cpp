#include "mainwindow.h"

#include <QApplication>
#include <QFile>
#include <QLabel>
#include <QTabWidget>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.setWindowIcon(QIcon(":assets/icons/icona.svg"));
  app.setApplicationName("Library Archive");

  QFile stylesheet(":/assets/stylesheet.qss");
  stylesheet.open(QFile::ReadOnly);
  app.setStyleSheet(QLatin1String(stylesheet.readAll()));

  MainWindow w;
  w.show();

  return app.exec();
}
