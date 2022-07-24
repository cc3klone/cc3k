#ifndef _VAMPIRE_H_
#define _VAMPIRE_H_
#include "enemy.h"

class Vampire : public Enemy {
    public:
        Vampire(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif
