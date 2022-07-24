#include "item.h"
#include "gold.h"

int Gold::getGold() {
    return value;
}

void Gold::onPickup(Player *player) {
    player->setGold(this->value);
    }
}
