#include "item.h"
#include "barriersuit.h"

void BarrierSuit::onPickup(Player *player) {
    player->inventoryAdd(this);
    player->setHassBarrierSuit();
}
