#ifndef EDITITEMSELECTOR_H
#define EDITITEMSELECTOR_H

#include "qwidget.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class EditItemSelector: public QWidget
{
     Q_OBJECT

public:

   EditItemSelector(QWidget *parent = nullptr);


};

#endif // EDITITEMSELECTOR_H

