#include "item.h"

Enemy *Item::getGuardingEnemy() {
    return guardingEnemy;
}

void Item::setGuardingEnemy(Enemy *enemy) {
    this->guardingEnemy = enemy;
}
