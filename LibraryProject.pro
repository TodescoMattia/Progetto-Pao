QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    view/tabdialog.cpp \
    view\iteminfo.cpp \
    model\genre.cpp \
    model\item.cpp \
    model\book.cpp \
    model\bookserie.cpp \
    model\film.cpp \
    model\videogame.cpp \
    model\boardgame.cpp \
    view\bookviewer.cpp \
    view\homeviewer.cpp \
    view\iteminfovisitor.cpp \
    view\main.cpp \


HEADERS += \
    view/tabdialog.h \
    view\iteminfo.h \
    model\visitor.h \
    model\genre.h \
    model\item.h \
    model\book.h \
    model\bookserie.h \
    model\film.h \
    model\videogame.h \
    model\boardgame.h \
    view\bookviewer.h \
    view\homeviewer.h \
    view\iteminfovisitor.h\


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
