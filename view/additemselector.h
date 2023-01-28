#ifndef ADDITEMSELECTOR_H
#define ADDITEMSELECTOR_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QVBoxLayout>
#include <QButtonGroup>
#include <QPushButton>
#include <QLabel>


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

