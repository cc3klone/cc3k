#ifndef _ELVESVISITOR_H_
#define _ELVESVISITOR_H_
#include "playervisitor.h"
#include <cstdlib>

class ElvesVisitor : public PlayerVisitor{
    public:
        void setAtk(int &currentAtk, int addAtk) override;
        void setDef(int &currentDef, int addDef) override;
        void setHP(int &currentHP, int maxHP, int addHP) override;
};

#endif
