#ifndef PLAYABLE_H
#define PLAYABLE_H

class Playable {
public:
    virtual int attack_func() = 0;
    virtual int defend_func(int) = 0;
};

#endif
