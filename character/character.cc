#include "character.h"

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

void Character::attack(AttackType attackType, Character *target) {
    target->health = (target->health + target->baseDef + target->bonusDef) - 
                     (this->baseAtk + this->bonusAtk);
}

void Character::move(Direction direction) {
    changePosition(direction, positionX, positionY);
}