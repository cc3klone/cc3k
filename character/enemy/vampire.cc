#include "vampire.h"

Vampire::Vampire(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 50;
    this->maxHealth = this->health;
    this->gold = 1;
    this->baseAtk = 25;
    this->baseDef = 25;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(nullptr);
}