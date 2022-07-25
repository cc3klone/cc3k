#include "phoenix.h"

Phoenix::Phoenix(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 50;
    this->maxHealth = this->health;
    this->gold = 1;
    this->baseAtk = 35;
    this->baseDef = 20;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(nullptr);
}