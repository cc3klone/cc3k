#ifndef _ORCVISITOR_H_
#define _ORCVISITOR_H_
#include "playervisitor.h"

class OrcVisitor : public PlayerVisitor{
    public:
        void setGold(double &currentGold, int addGold) override; 
};

#endif
