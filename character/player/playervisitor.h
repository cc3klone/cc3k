#ifndef _PLAYERVISITOR_H_
#define _PLAYERVISITOR_H_
#include "player.h"

class PlayerVisitor {
    public:
        virtual void setAtk(int &currentAtk, int addAtk);
        virtual void setDef(int &currentDef, int addDef);
        virtual void setHP(int &currentHP, int maxHP, int addHP);
        virtual void setGold(double &currentGold, int addGold);
        ~PlayerVisitor();
};
#endif
