#ifndef _ITEM_H_
#define _ITEM_H_

class Item {
        static bool passive;
        static bool consumable;
        int uuid;
  
    public:
        virtual void passiveEffect();
        virtual void consumableEffect();
};

#endif
