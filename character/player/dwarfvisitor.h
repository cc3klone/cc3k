#ifndef _DWARFVISITOR_H_
#define _DWARFVISITOR_H_
#include "playervisitor.h"

class DwarfVisitor : public PlayerVisitor{
    public:
        void setGold(double &currentGold, int addGold) override; 
};

#endif

