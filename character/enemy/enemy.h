#ifndef _ENEMY_H_
#define _ENEMY_H_
#include "../character.h"
#include "../../item/item.h"
#include "../../rng.h"
#include <map>

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
        void transferGold(Player *player);
        Item *getInventory();
        void setInventory(Item *inventory);
        void setProtect(Item *protectItem);
        Item *getProtect();
        ~Enemy();
};
#endif
