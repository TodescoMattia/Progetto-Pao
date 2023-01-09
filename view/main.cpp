#include "homeviewer.h"
#include "mainwindow.h"

#include "itemtab.h"
#include "usertab.h"
#include "loantab.h"

#include "..\model\Book.h"
#include "..\model\Film.h"
#include "..\model\User.h"
#include "..\model\BookSerie.h"
#include "..\model\List.h"
#include "listview.h"
#include "userinfo.h"


#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QFile>
#include <QTabWidget>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    //HomeViewer w;

    QFile stylesheet(":/assets/stylesheet.qss");
    stylesheet.open(QFile::ReadOnly);
    app.setStyleSheet(QLatin1String(stylesheet.readAll()));

    MainWindow w;
    w.show();

    return app.exec();
}
