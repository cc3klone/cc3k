#ifndef _PLAYER_H_
#define _PLAYER_H_
#include <vector>
#include "../character.h"
#include "playervisitor.h"
#include "humanvisitor.h"
#include "dwarfvisitor.h"
#include "elvesvisitor.h"
#include "orcvisitor.h"
#include "../../item/item.h"

enum class PlayerRace { Human, Dwarf, Elves, Ore };
class Player : public Character {
    double score;
    std::vector<Item *> inventory;
    PlayerVisitor playerVisitor;
    bool hasBarrierSuit = false;
    bool hasCompass = false;

    public:
        Player(int positionX, int positionY, Floor *thisFloor);
        Player(PlayerRace playerRace, int positionX, int positionY, Floor *thisFloor);
        void inventoryAdd(Item *item);
        void inventoryDrop(Item *item);
        int inventoryFind(int uuid);
        void playerAttack(AttackType attackType, Character *target);
        void getAttacked(int damage) override;
        void setAtk(int addAtk);
        void setDef(int addDef);
        void setHP(int addHP);
        void setGold(int addGold);
        void setHasCompass();
        void setHasBarrierSuit();
        bool getHasCompass();
        ~Player();
};
#endif
