#include "item.h"
#include "gold.h"
#include "../rng.h"

Gold::Gold() {
    RNG *rng = new RNG();
    gType = rng->generateInt(7);
    if (gType < 5) {
        this->value = 1;
    } else if (gType == 5) {
        this->value = 6;
    } else {
        this->value = 2;
    }
    delete rng;
}

int Gold::getGold() {
    return value;
}

void Gold::onPickup(Player *player) {
    player->setGold(this->value);
    delete this;
    }
}
