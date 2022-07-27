#ifndef _TROLL_H_
#define _TROLL_H_
#include "enemy.h"

class Troll : public Enemy {
    public:
        Troll(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif

