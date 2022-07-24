#ifndef _PHOENIX_H_
#define _PHOENIX_H_
#include "enemy.h"

class Phoenix : public Enemy {
    public:
        Phoenix(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif
