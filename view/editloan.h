#ifndef EDITLOAN_H
#define EDITLOAN_H

#include "qwidget.h"

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class EditLoan: public QWidget
{
     Q_OBJECT

public:

   EditLoan(QWidget *parent = nullptr);

};

#endif // EDITLOAN_H
