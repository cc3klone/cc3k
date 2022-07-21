#ifndef _PLAYERVISITOR_H_
#define _PLAYERVISITOR_H_
#include "player.h"

class PlayerVisitor {
    public:
        void intRace(PlayerRaces playerRace); 
        int getAtk();
        void setAtk(int setAtk);
        int getDef();
        void setDef(int setDef);
        int getHP();
        void setHP(int setHP);
};
#endif
