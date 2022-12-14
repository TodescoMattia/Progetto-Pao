#ifndef HOMEVIEWER_H
#define HOMEVIEWER_H

#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QFrame>
#include <QLabel>
#include <QPushButton>
#include <QAction>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGroupBox>
#include <QPixmap>


class Homeviewer: public QWidget{
    Q_OBJECT

    void Schermata_principale(QVBoxLayout* MainLayout);

    void Bottoni(QVBoxLayout* MainLayout);

    QLayout* createDescriptionLayout(const QString& description);

public:
    explicit Homeviewer(QWidget* parent=nullptr);

signals:
};

#endif // HOMEVIEWER_H
