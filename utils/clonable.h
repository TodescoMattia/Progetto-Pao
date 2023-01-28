#ifndef CLONABLE_H
#define CLONABLE_H

class Clonable {
public:
    virtual Clonable* clone() const = 0;
    virtual ~Clonable() = 0;
};

#endif // CLONABLE_H
