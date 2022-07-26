#ifndef _ENEMY_H_
#define _ENEMY_H_
#include <map>
#include "../character.h"

enum class Direction;
enum class CellType;
class Item;

class Enemy : public Character {
    Direction generateDirection();
    bool attackMissed();
    Item *inventory;
    Item *protecting;

    public:
        virtual void specialAbility() = 0;
        void enemyAttack(Character *target);
        void getAttacked(int damage) override;
        void enemyMove();
        void inventoryDrop();
        void transferGold();
        Item *getInventory();
        void setInventory(Item *inventory);
        void setProtect(Item *protectItem);
        Item *getProtect();
        ~Enemy();
};
#endif
