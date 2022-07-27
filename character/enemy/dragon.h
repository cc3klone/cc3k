#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "enemy.h"

class Dragon : public Enemy {
    public:
        int protectingX;
        int protectingY;
        Dragon(int positionX, int positionY, Floor *thisFloor, Item *inventory, Item *protecting, int protectingX, int protectingY);
};
#endif
