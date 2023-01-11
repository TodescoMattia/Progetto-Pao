#ifndef EDITUSER_H
#define EDITUSER_H

#include "qwidget.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class EditUser: public QWidget
{
     Q_OBJECT

public:

   EditUser(QWidget *parent = nullptr);

};

#endif // EDITUSER_H
