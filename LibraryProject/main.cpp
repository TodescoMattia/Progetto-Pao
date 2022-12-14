#include "bookviewer.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    BookViewer w;
    w.show();
    return a.exec();
}
