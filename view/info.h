#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QPushButton>
#include "../utils/clonable.h"

class Info: public Clonable{

public:
    virtual QWidget* getWidget() const=0;
    virtual void edit()=0;
    virtual void remove()=0;
    Info* clone() const override = 0;

};

#endif // INFO_H
