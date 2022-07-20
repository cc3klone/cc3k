#include "character.h"

void Character::attack(AttackType attackType, Character *target) {
    target->health = (target->health + target->baseDef + target->bonusDef) - 
                     (this->baseAtk + this->bonusAtk);
}

//Maybe this move method should return bool, true indicating that the move was successful, false otherwise
void Character::move(Direction direction) {
    int newPositionX = positionX;
    int newPositionY = positionY;

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

    //need to be implemented, need size varaible in thisFloor to check if the move is a valid move
    if (validMove) {
        positionX = newPositionX;
        positionY = newPositionY;
    } else {
        //invalid move
    }
}