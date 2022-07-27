#include "enemy.h"
#include "../../floor/floor.h"
#include "../../item/item.h"
#include "../../rng.h"
#include "../player/player.h"
#include <iostream>
#include <vector>
#include <algorithm>

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
    bool temp = attackMissed();
    if (attackMissed()) { // 50% chance that enemy misses
        std::cout << "enemy missed" << std::endl;
        return;
    }

    attack(target);
}

void Enemy::getAttacked(int damage) {
    this->health -= damage;
    if (this->health <= 0) {
        transferGold();
        thisFloor->killEnemy(std::make_pair(this->positionX, this->positionY));
    }
}

//enemyMove moves the enemy in a random direction
void Enemy::enemyMove() {
    Direction randomDirection;
    //uses a map to store the previous failed directions (directions that the enemy cannot move to ie. stairs)
    std::vector<Direction> failedDirections; 

    while (failedDirections.size() <= 8) { //if the size of the map = 8 then all directions have failed
        randomDirection = generateDirection(); 



        if (std::count(failedDirections.begin(), failedDirections.end(), randomDirection)) { //checks if the newly generated direction is already a failed direction
            //std::cout << "direction already invalid" << std::endl;
            continue;
        }

        int tempX = this->positionX;
        int tempY = this->positionY;
        std::pair<int, int> p = changePosition(randomDirection, tempX, tempY, this->moveSpeed);
        CellType nextCell = this->thisFloor->checkCoord(p.first, p.second);

        if (nextCell == CellType::Room) {
            move(randomDirection);
            return;
        }

        failedDirections.push_back(randomDirection);

    }

    if (failedDirections.size() == 8) {
        return;
    }

    
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
