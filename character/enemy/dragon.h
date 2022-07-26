#ifndef _DRAGON_H_
#define _DRAGON_H_
#include "enemy.h"

class Dragon : public Enemy {
    public:
        Dragon(int positionX, int positionY, Floor *thisFloor, Item *inventory, Item *protecting);
};
#endif
