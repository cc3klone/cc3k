#ifndef _ITEM_H_
#define _ITEM_H_

class Item {
        static bool passive;
        static bool consumable;
        int uuid;
  
    public:
        virtual void passiveEffect() = 0;
        virtual void consumableEffect() = 0;
};

#endif
