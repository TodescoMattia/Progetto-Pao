#ifndef EDITVIDEOGAME_H
#define EDITVIDEOGAME_H

#include "../model/videogame.h"
#include <QLineEdit>
#include <QSpinBox>
#include <QButtonGroup>

#include "edititem.h"

class EditVideogame: public EditItem{
    Q_OBJECT

private:
    Videogame* videogame;

    QButtonGroup *genreGroup;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
    EditVideogame(Videogame* videogame);

public slots:
    void setVideogame();
};

#endif // EDITVIDEOGAME_H
