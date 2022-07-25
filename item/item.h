#ifndef _ITEM_H_
#define _ITEM_H_
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

class Item {
    protected:
        Enemy *guardingEnemy;
  
    public:
        Item(Enemy *guardingEnemy = nullptr);
        virtual void onPickup(Player *player) = 0;
        Enemy *getGuardingEnemy();
        void setGuardingEnemy(Enemy *guardingEnemy);
};

#endif
