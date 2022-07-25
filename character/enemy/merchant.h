#ifndef _MERCHANT_H_
#define _MERCHANT_H_
#include "enemy.h"

class Merchant : public Enemy {
    public:
        Merchant(int positionX, int positionY, Floor *thisFloor, Item *inventory);
};
#endif
