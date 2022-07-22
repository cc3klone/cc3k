#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <vector>
#include "character.h"
#include "item.h"

enum class PlayerRace { Human, Dwarf, Elves, Ore };
class Player : public Character {
    double score;
    Vector<Item *> inventory;
    int bonusAtk;
    int bonusDef;
    public:
        void inventoryAdd(Item *item);
        void inventoryDrop(Item *item);
        int inventoryFind(int uuid);
        void playerAttack(AttackType attackType, Character *target);
        ~Player();
};
#endif
