#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"

class Enemy : public Character {
    Direction generateDirection();

    public:
        virtual bool checkSurrounding() = 0;
        virtual void specialAbility() = 0;
        void attack(AttackType attackType, Character *target) override;
        void move(Direction direction) override;
};
#endif