#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "character.h"
#include "../../item/item.h"

class Enemy : public Character {
    Direction generateDirection();
    bool attackMissed();
    Item *inventory;

    public:
        virtual void specialAbility() = 0;
        void enemyAttack(AttackType attackType, Character *target);
        void enemyMove();
};
#endif