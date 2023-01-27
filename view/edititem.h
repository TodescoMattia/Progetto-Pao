#ifndef EDITITEM_H
#define EDITITEM_H

#include <QDialog>
#include <QCheckBox>
#include "../model/item.h"
#include <QDialogButtonBox>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>


class EditItem: public QDialog{
     Q_OBJECT

private:
    Item* item;

    QLineEdit *idLine;
    QLineEdit *titleLine;
    QCheckBox *isLentCheck;

public:
   EditItem(Item* item);
   void set();
};

#endif // EDITITEM_H
