#ifndef _ITEM_H_
#define _ITEM_H_

class Enemy;
class Player;

class Item {
    protected:
        Enemy *guardingEnemy = nullptr;
  
    public:
        Item();
        virtual void onPickup(Player *player) = 0;
        Enemy *getGuardingEnemy();
        void setGuardingEnemy(Enemy *guardingEnemy);
        virtual ~Item() = default;
};

#endif
