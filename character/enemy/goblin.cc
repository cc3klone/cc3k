#include "goblin.h"

Goblin::Goblin(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 70;
    this->maxHealth = this->health;
    this->gold = 1;
    this->baseAtk = 5;
    this->baseDef = 10;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(nullptr);
}