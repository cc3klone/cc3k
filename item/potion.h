#ifndef _POTION_H_
#define _POTION_H_
#include "item.h"

enum class PotionType{PositivePotion, NegativePotion};
enum class EffectType{IncreaseHP, DecreaseHP, IncreaseAtkDmg, DecreaseAtkDmg};

class Potion : public Item {
    const static bool passive = false;
    const static bool consumable = true;
    EffectType potionEffect;
    int effectScalar;

    public:
        Potion(PotionType);
        void consumableEffect() override;
};

#endif

