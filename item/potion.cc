#include "item.h"
#include "potion.h"

Potion::Potion(EffectType potionEffect, int effectScalar, PotionType type)
    : potionEffect{potionEffect},
      effectScalar{effectScalar}
{
    if (type == PotionType::NegativePotion) {
        effectScalar *= -1;
    }
}
