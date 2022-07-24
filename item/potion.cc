#include "potion.h"

Potion::Potion(EffectType potionEffect, int effectScalar, int uuid)
    : potionEffect{potionEffect},
      effectScalar{effectScalar},
      uuid{uuid}
{}

