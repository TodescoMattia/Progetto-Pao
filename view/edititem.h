#ifndef EDITITEM_H
#define EDITITEM_H

#include "qwidget.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class EditItem: public QWidget
{
     Q_OBJECT

public:

   EditItem(QWidget *parent = nullptr);

};

#endif // EDITITEM_H
