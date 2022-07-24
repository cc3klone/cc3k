#include "potion.h"

Potion::Potion(EffectType potionEffect, int effectScalar, int uuid)
    : potionEffect{potionEffect},
      effectScalar{effectScalar},
      uuid{uuid}
{}

void Potion::onPickup(Player::Player *player) {
    switch (this->potionEffect) {
            case EffectType::HP:
                player->setHP(this->effectScalar);
                break;
            case EffectType::AtkDmg:
                player->setAtk(this->effectScalar);
                break;
    }
}
