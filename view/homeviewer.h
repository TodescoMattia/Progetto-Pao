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


class HomeViewer: public QWidget{
    Q_OBJECT
private:
    void Schermata_principale(QVBoxLayout* MainLayout);
    void Bottoni(QVBoxLayout* MainLayout);
    QLayout* createDescriptionLayout(const QString& description);

public:
    explicit HomeViewer(QWidget* parent=nullptr);

signals:
};

#endif // HOMEVIEWER_H
