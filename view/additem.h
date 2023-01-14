#ifndef ADDITEM_H
#define ADDITEM_H

#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include "itemtab.h"

class AddItem: public QDialog{
    Q_OBJECT
private:
    QLineEdit *idLine;
    QLineEdit *titleLine;
    QLineEdit *isLentLine;
    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;
public:
    AddItem();
    QString getId() const;
    QString getTitle() const;
    QString getIsLent() const;
};

#endif // ADDITEM_H
