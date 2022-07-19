#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "floor.h"

enum class AttackType { Melee };

class Character {
    Floor *thisFloor;
    int positionX;
    int positionY;
    double gold;
    int health;
    int maxHealth;
    int baseAtk;
    int baseDef;
    int moveSpeed;
    Direction dirLooking;
    AttackType defaultAtk;
    public:
        void attack(Character::AttackType attackType);
        void move();
};
#endif
