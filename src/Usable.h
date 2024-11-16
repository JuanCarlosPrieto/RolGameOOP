#ifndef USABLE_H
#define USABLE_H

class Usable {
public:
    virtual void use(int) = 0;
    virtual void use(int, int) = 0;
    virtual ~Usable() = default;        
};

#endif
