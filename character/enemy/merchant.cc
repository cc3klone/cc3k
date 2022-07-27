#include "merchant.h"

Merchant::Merchant(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 30;
    this->maxHealth = this->health;
    this->gold = 0;
    this->baseAtk = 70;
    this->baseDef = 5;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(nullptr);
}

