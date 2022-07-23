#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "floor.h"

enum class AttackType { Melee };

class Character {
    protected:
        Floor *thisFloor;
        int positionX;
        int positionY;
        double gold;
        int health;
        int maxHealth;
        int baseAtk;
        int baseDef;
        int bonusAtk;
        int bonusDef;
        int moveSpeed;
        AttackType defaultAtk;

    void changePosition(Direction direction, int &newPositionX, int &newPositionY);
    public:
        void attack(AttackType attackType, Character *target);
        void move(Direction direction);
};
#endif
