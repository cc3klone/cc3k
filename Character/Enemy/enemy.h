#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"

class Enemy : public Character {
    public:
        virtual bool checkSurrounding() = 0;
        virtual void specialAbility() = 0;
};
#endif