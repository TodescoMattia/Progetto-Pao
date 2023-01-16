#ifndef ADDITEMSELECTOR_H
#define ADDITEMSELECTOR_H

#include "qwidget.h"
#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QButtonGroup>

QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QLineEdit;
class QTextEdit;
QT_END_NAMESPACE

class AddItemSelector: public QDialog{
     Q_OBJECT
private:
    QVBoxLayout* layout;
    QButtonGroup *selectTypeGroup;
    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:

    AddItemSelector();
    int getTypeGroup();

};

#endif // ADDITEMSELECTOR_H

