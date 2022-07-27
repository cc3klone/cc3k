#include "item.h"
#include "../character/player/player.h"
#include "../character/enemy/enemy.h"

Enemy *Item::getGuardingEnemy() {
    return guardingEnemy;
}

void Item::setGuardingEnemy(Enemy *enemy) {
    this->guardingEnemy = enemy;
}

