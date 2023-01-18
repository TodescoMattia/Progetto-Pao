#ifndef EDITFILM_H
#define EDITFILM_H


#include "../model/film.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QButtonGroup>

#include "edititem.h"

class EditFilm: public EditItem{
    Q_OBJECT
private:
    Film* film;

    QLineEdit* directorLine;
    QSpinBox* durationLine;
    QButtonGroup *genreGroup;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
    EditFilm(Film* film);

public slots:
    void setFilm();
};

#endif // EDITFILM_H
