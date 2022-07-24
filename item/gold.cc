#include "item.h"
#include "gold.h"

void Gold::onPickup(Player::Player *player) {
    player->setGold(this->value);
    }
}
