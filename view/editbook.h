#ifndef EDITBOOK_H
#define EDITBOOK_H

#include "../model/book.h"
#include "edititem.h"

#include <QLineEdit>
#include <QSpinBox>
#include <QButtonGroup>



class EditBook: public EditItem{
    Q_OBJECT

private:
    Book* book;

    QLineEdit* authorLine;
    QSpinBox* pageNumberLine;
    QButtonGroup *genreGroup;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
    EditBook(Book* book);

public slots:
    void setBook();
};

#endif // EDITBOOK_H
