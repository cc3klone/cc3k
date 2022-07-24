#include "item.h"

int Item::getId() {
    return uuid;
}

Enemy *Item::getGuardingEnemy() {
    return guardingEnemy;
}

void Item::setGuardingEnemy(Enemy *enemy) {
    this->guardingEnemy = enemy;
}
