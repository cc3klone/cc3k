#include "enemy.h"
#include "../../floor/floor.h"
#include "../../item/item.h"
#include "../../rng.h"
#include "../player/player.h"
#include <iostream>

Direction Enemy::generateDirection() {
    RNG roll;
    int randomInt = roll.generateInt(7);
	Direction randomDirection = static_cast<Direction>(randomInt);
    return randomDirection;
}

bool Enemy::attackMissed() {
    RNG roll;
    int randomAttack = roll.generateInt(1);
    if (randomAttack == 0) {
        return true;
    }
    return false;
}

void Enemy::enemyAttack(Character *target) {
    if (attackMissed()) { // 50% chance that enemy misses
        return;
    }

    attack(target);
}

void Enemy::getAttacked(int damage) {
    this->health -= damage;
    std::cout << "Damage: " << damage << std::endl;
    std::cout << "Enemy HP: " << this->health << std::endl;
    if (this->health <= 0) {
        transferGold();
        std::cout << "enemy posn: " << positionX << " " << positionY << std::endl;
        thisFloor->killEnemy(std::make_pair(this->positionX, this->positionY));
        std::cout << "bro why does this shit not work" << std::endl;
    }
}

//enemyMove moves the enemy in a random direction
void Enemy::enemyMove() {
    Direction randomDirection;
    //uses a map to store the previous failed directions (directions that the enemy cannot move to ie. stairs)
    std::map<Direction, bool> failedDirections; 

    while (failedDirections.size() != 8) { //if the size of the map = 8 then all directions have failed
        randomDirection = generateDirection(); 

        if (failedDirections.count(randomDirection) == 1) { //checks if the newly generated direction is already a failed direction
            continue;
        }

        int tempX = this->positionX;
        int tempY = this->positionY;
        changePosition(randomDirection, tempX, tempY, this->moveSpeed);
        CellType nextCell = this->thisFloor->checkCoord(tempX, tempY);

        if (nextCell == CellType::Room) { //enemies can only move to the "Room" cell type
            break;
        }

        failedDirections[randomDirection] = true;
    }

    if (failedDirections.size() == 8) {
        return;
    }

    move(randomDirection);
}

void Enemy::inventoryDrop() {

}

void Enemy::transferGold() {
    Player *player = this->thisFloor->getPlayer();
    player->setGold(this->gold);
}


Item *Enemy::getInventory() {
    return inventory;
}

void Enemy::setInventory(Item *inventory) {
    this->inventory = inventory;
}

void Enemy::setProtect(Item *protectItem) {
    this->protecting = protectItem;
}

Item *Enemy::getProtect() {
    return protecting;
}

Enemy::~Enemy() {
}
