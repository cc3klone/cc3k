#ifndef _WEREWOLF_H_
#define _WEREWOLF_H_
#include "enemy.h"

class Werewolf : public Enemy {
    public:
        Werewolf(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif

