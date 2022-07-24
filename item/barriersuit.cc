#include "barriersuit.h"

void BarrierSuit::onPickup(Player::Player *player) {
    Player::inventoryAdd(this);
}
