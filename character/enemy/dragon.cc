#include "dragon.h"

Dragon::Dragon(int positionX, int positionY, Floor *thisFloor, Item *inventory, Item *protecting, int protectingX, int protectingY) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 150;
    this->maxHealth = this->health;
    this->gold = 0;
    this->baseAtk = 20;
    this->baseDef = 20;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 0;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(protecting);
    this->protectingX = protectingX;
    this->protectingY = protectingY;
}