#include "compass.h"
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

void Compass::onPickup(Player *player) {
    player->inventoryAdd(this);
    player->setHasCompass();
}

