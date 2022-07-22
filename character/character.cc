#include "character.h"

void Character::changePosition(Direction direction, int &newPositionX, int &newPositionY) {
        switch (direction) {
    case Direction::North:
        newPositionY -= 1;
        break;
    case Direction::South:
        newPositionY += 1;
        break;
    case Direction::East:
        newPositionX += 1;
        break;
    case Direction::West:
        newPositionX -= 1;
        break;
    case Direction::NorthEast:
        newPositionX += 1;
        newPositionY -= 1;
        break;
    case Direction::NorthWest:
        newPositionX -= 1;
        newPositionY -= 1;
        break;
    case Direction::SouthEast:
        newPositionX += 1;
        newPositionY += 1;
        break;
    case Direction::SouthWest:
        newPositionX -= 1;
        newPositionY += 1;
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