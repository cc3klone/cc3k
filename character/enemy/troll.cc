#include "troll.h"

Troll::Troll(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 120;
    this->maxHealth = this->health;
    this->gold = 1;
    this->baseAtk = 25;
    this->baseDef = 15;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
}