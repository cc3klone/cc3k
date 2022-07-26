#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"

enum class EffectType{ HP, AtkDmg, Def };


class Potion : public Item {
    private:
        EffectType potionEffect;
        int effectScalar;

    public:
    Potion();
    void onPickup(Player *player) override;
};

#endif
