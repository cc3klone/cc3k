#include "character.h"
#include <cmath>
#include <utility>

std::pair<int, int> Character::changePosition(Direction direction, int currentX, int currentY, int scalar) {
    int newPositionX, newPositionY;
    switch (direction) {
        case Direction::North:
            newPositionY -= scalar;
            break;
        case Direction::South:
            newPositionY += scalar;
            break;
        case Direction::East:
            newPositionX += scalar;
            break;
        case Direction::West:
            newPositionX -= scalar;
            break;
        case Direction::Northeast:
            newPositionX += scalar;
            newPositionY -= scalar;
            break;
        case Direction::Northwest:
            newPositionX -= scalar;
            newPositionY -= scalar;
            break;
        case Direction::Southeast:
            newPositionX += scalar;
            newPositionY += scalar;
            break;
        case Direction::Southwest:
            newPositionX -= scalar;
            newPositionY += scalar;
            break;
        default:
            break;
    }
    return std::make_pair(newPositionX, newPositionY);
}


void Character::attack(Character *target) {
    int damage = ceil((100 / (100 + target->getCurrentDef())) * this->currentAtk);
    target->getAttacked(damage);
}


void Character::move(Direction direction) {
    std::pair<int, int> p = changePosition(direction, positionX, positionY, this->moveSpeed);
    this->positionX = p.first;
    this->positionY = p.second;
}

std::pair<int, int> Character::getPos() {
    return std::make_pair(positionX, positionY);
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

