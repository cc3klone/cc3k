#ifndef _GOBLIN_H_
#define _GOBLIN_H_
#include "enemy.h"

class Goblin : public Enemy {
    public:
        Goblin(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif

