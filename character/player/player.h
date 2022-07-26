#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "../character.h"
#include "playervisitor.h"
#include <vector>

enum class Direction;
class Item;
class Floor;
class PlayerVisitor;

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
        bool playerAttack(Direction attackDirection);
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
        void setFloor(Floor *floor);
        PlayerRace getRace();
        ~Player();
};
#endif
