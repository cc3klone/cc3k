#include "character.h"
#include "../floor/floor.h"
#include <cmath>
#include <utility>
#include <iostream>

std::pair<int, int> Character::changePosition(Direction direction, int currentX, int currentY, int scalar) {
    int newPositionX = currentX;
    int newPositionY = currentY;
    switch (direction) {
        case Direction::North:
            newPositionX -= scalar;
            break;
        case Direction::South:
            newPositionX += scalar;
            break;
        case Direction::East:
            newPositionY += scalar;
            break;
        case Direction::West:
            newPositionY -= scalar;
            break;
        case Direction::Northeast:
            newPositionY += scalar;
            newPositionX -= scalar;
            break;
        case Direction::Northwest:
            newPositionY -= scalar;
            newPositionX -= scalar;
            break;
        case Direction::Southeast:
            newPositionY += scalar;
            newPositionX += scalar;
            break;
        case Direction::Southwest:
            newPositionY -= scalar;
            newPositionX += scalar;
            break;
        default:
            break;
    }
    return std::make_pair(newPositionX, newPositionY);
}


void Character::attack(Character *target) {
    std::cout << "Def: " << target->getCurrentDef() << std::endl;
    std::cout << "Atk: " << this->currentAtk << std::endl;
    int damage = ceil((100.0 / (100.0 + target->getCurrentDef())) * (this->currentAtk + 0.0));
    std::cout << damage << std::endl;
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

Character::~Character() {}

