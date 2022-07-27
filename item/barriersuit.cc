#include "barriersuit.h"
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

void BarrierSuit::onPickup(Player *player) {
    player->inventoryAdd(this);
    player->setHasBarrierSuit();
}

