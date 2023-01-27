#ifndef EDITBOARDGAME_H
#define EDITBOARDGAME_H

#include "../model/boardgame.h"
#include "edititem.h"

#include <QLineEdit>
#include <QSpinBox>
#include <QButtonGroup>



class EditBoardGame: public EditItem{
    Q_OBJECT
private:
    BoardGame* boardGame;

    QButtonGroup *genreGroup;
    QSpinBox* playerNumberLine;

    QDialogButtonBox *buttonBox;
    QPushButton* confirmButton;
    QPushButton* cancelButton;

public:
    EditBoardGame(BoardGame* boardGame);

public slots:
    void setBoardGame();
};


#endif // EDITBOARDGAME_H
