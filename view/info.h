#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QPushButton>

class Info
{
public:
    virtual QWidget* getWidget() const=0;
    //virtual QPushButton* getViewButton() const;
    //virtual QPushButton* getEditButton() const;
    //virtual QPushButton* getDeleteButton() const;
};

#endif // INFO_H
