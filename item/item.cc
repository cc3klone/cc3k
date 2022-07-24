#include "item.h"

int Item::getId() {
    return uuid;
}

Enemy *getGuardingEnemy() {
    return guardingEnemy;
}

void setGuardingEnemy(Enemy *enemy) {
    this->guardingEnemy = enemy;
}
