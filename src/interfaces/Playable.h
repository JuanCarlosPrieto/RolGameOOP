#ifndef PLAYABLE_H
#define PLAYABLE_H

class Playable {
public:
    virtual void attack() = 0;
    virtual void defend(int) = 0;
    virtual int heal(int) = 0;
    virtual void takeDamage(int) = 0;
    virtual ~Playable() = default;
};

#endif
