#ifndef ADDITEM_H
#define ADDITEM_H

#include <QLineEdit>
#include <QDialog>
#include <QDialogButtonBox>
#include <QButtonGroup>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include "itemtab.h"
#include "additemselector.h"

class AddItem: public QDialog{
    Q_OBJECT
private:
    QVBoxLayout *layout;
    AddItemSelector* itemSelector;
    QLineEdit *idLine;
    QLineEdit *titleLine;
    QButtonGroup *isLentGroup;
    QLineEdit *authorLine;
    QSpinBox *pageNumberLine;
    QComboBox *genreBox;
    QSpinBox *volumeNumberLine;
    QLineEdit *directorLine;
    QSpinBox *durationLine;
    QSpinBox *playerNumberLine;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;
public:
    AddItem(AddItemSelector* itemSelector);
    QString getId() const;
    QString getTitle() const;
    int getIsLent() const;
    QString getAuthor() const;
    int getPageNumber() const;
    int getVolumeNumber() const;
    int getGenre() const;
    QString getDirector() const;
    int getDuration() const;
    int getPlayerNumber() const;
    int getSelectedType() const;

signals:
    void refreshItemTab();
};

#endif // ADDITEM_H
