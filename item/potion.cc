#include "potion.h"
#include "../rng.h"
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

Potion::Potion() {
    RNG *rng = new RNG();
    switch (static_cast<EffectType>(rng->generateInt(2))) {
        case EffectType::HP:
            this->potionEffect = EffectType::HP;
            this->effectScalar = rng->generateInt(10, 1);
            break;
        case EffectType::AtkDmg:
            this->potionEffect = EffectType::AtkDmg;
            this->effectScalar = 5;
            break;
        case EffectType::Def:
            this->potionEffect = EffectType::Def;
            this->effectScalar = 5;
            break;
    }
    if (rng->generateInt(1) == 1) {
        this->effectScalar *= -1;
    }
    delete rng;
}

void Potion::onPickup(Player *player) {
    switch (this->potionEffect) {
        case EffectType::HP:
            player->setHp(this->effectScalar);
            break;
        case EffectType::AtkDmg:
            player->setAtk(this->effectScalar);
            break;
        case EffectType::Def:
            player->setDef(this->effectScalar);
            break;
    }
    delete this;
}
