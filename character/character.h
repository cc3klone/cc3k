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
        int currentAtk;
        int currentDef;
        int moveSpeed;
        AttackType defaultAtk;

    void changePosition(Direction direction, int &newPositionX, int &newPositionY);
    public:
        virtual void getAttacked(int damage);
        void attack(AttackType attackType, Character *target);
        void move(Direction direction);
        int getHealth();
        int getCurrentAtk();
        int getCurrentDef();
};
#endif
