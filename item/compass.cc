#include "compass.h"

void Compass::onPickup(Player *player) {
    player->inventoryAdd(this);
    player->setHasCompass();
}
