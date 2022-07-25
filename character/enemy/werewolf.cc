#include "werewolf.h"

Werewolf::Werewolf(int positionX, int positionY, Floor *thisFloor, Item *inventory) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 120;
    this->maxHealth = this->health;
    this->gold = 1;
    this->baseAtk = 30;
    this->baseDef = 5;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    setInventory(inventory);
    setProtect(nullptr);
}