#ifndef EDITBOOKSERIE_H
#define EDITBOOKSERIE_H

#include "../model/bookserie.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QButtonGroup>

#include "edititem.h"

class EditBookSerie: public EditItem{
    Q_OBJECT
private:
    BookSerie* bookSerie;

    QLineEdit* authorLine;
    QSpinBox* pageNumberLine;
    QButtonGroup *genreGroup;
    QSpinBox* volumeLine;

    QDialogButtonBox* buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
    EditBookSerie(BookSerie* bookSerie);

public slots:
    void setBookSerie();
};
#endif // EDITBOOKSERIE_H
