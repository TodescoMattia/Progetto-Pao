#ifndef INFO_H
#define INFO_H

#include <QWidget>
#include <QPushButton>

class Info: public QWidget{
    Q_OBJECT
public:
    virtual QWidget* getWidget() const=0;
    virtual void edit()=0;
    virtual void remove()=0;

public slots:
  virtual void confirm()=0;

};

#endif // INFO_H
