#include "compass.h"

void Compass::onPickup(Player::Player *player) {
    Player::inventoryAdd(this);
}
