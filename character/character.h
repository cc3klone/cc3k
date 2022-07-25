#ifndef _CHARACTER_H_
#define _CHARACTER_H_
#include "../floor/floor.h"

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
        std::pair<int, int> changePosition(Direction direction, int currentX, int currentY, int scalar);

    public:
        virtual void getAttacked(int damage) = 0;
        void attack(Character *target);
        void move(Direction direction);
        bool isDead();
        std::pair<int, int> getPos();
        int getHealth();
        int getCurrentAtk();
        int getCurrentDef();
};
#endif
