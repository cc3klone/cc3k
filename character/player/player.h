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
#include "../../item/compass.h"

enum class PlayerRace { Human, Dwarf, Elves, Ore };
class Player : public Character {
    double score;
    std::vector<Item *> inventory;
    PlayerVisitor playerVisitor;
    bool hasBarrierSuit;
    bool hasCompass;
    PlayerRace myRace;

    public:
        Player(int positionX, int positionY, Floor *thisFloor);
        Player(PlayerRace playerRace, int positionX, int positionY, Floor *thisFloor);
        void inventoryAdd(Item *item);
        void inventoryDrop(Item *item);
        void playerAttack(Direction attackDirection);
        void playerMove(Direction moveDirection);
        void playerPickup(Direction pickupDirection);
        void getAttacked(int damage) override;
        void resetStat();
        void setAtk(int addAtk);
        void setDef(int addDef);
        void setHp(int addHP);
        void setGold(int addGold);
        void setHasCompass();
        void setHasBarrierSuit();
        bool getHasCompass();
        double getScore();
        PlayerRace getRace();
        ~Player();
};
#endif
