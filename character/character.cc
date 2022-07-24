#include "character.h"
#include <cmath>

void Character::changePosition(Direction direction, int &newPositionX, int &newPositionY) {
    switch (direction) {
        case Direction::North:
            newPositionY -= this->moveSpeed;
            break;
        case Direction::South:
            newPositionY += this->moveSpeed;
            break;
        case Direction::East:
            newPositionX += this->moveSpeed;
            break;
        case Direction::West:
            newPositionX -= this->moveSpeed;
            break;
        case Direction::NorthEast:
            newPositionX += this->moveSpeed;
            newPositionY -= this->moveSpeed;
            break;
        case Direction::NorthWest:
            newPositionX -= this->moveSpeed;
            newPositionY -= this->moveSpeed;
            break;
        case Direction::SouthEast:
            newPositionX += this->moveSpeed;
            newPositionY += this->moveSpeed;
            break;
        case Direction::SouthWest:
            newPositionX -= this->moveSpeed;
            newPositionY += this->moveSpeed;
            break;
        default:
            break;
    }
}

void Character::getAttacked(int damage) {
    this->health -= damage;
}

void Character::attack(AttackType attackType, Character *target) { //needs to be changed
    int damage = ceil((100 / (100 + target->getCurrentDef())) * this->currentAtk);
    target->getAttacked(damage);
}


void Character::move(Direction direction) {
    changePosition(direction, positionX, positionY);
}

int Character::getHealth () {
    return this->health;
}

int Character::getCurrentAtk() {
    return this->currentAtk;
}

int Character::getCurrentDef() {
    return this->currentDef;
}

