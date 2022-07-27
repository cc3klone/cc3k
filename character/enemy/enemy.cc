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

        //std::cout << "failedDirection size: " << failedDirections.size() << std::endl;

        // if (nextCell == CellType::Room) {
        //     std::cout << "enemy room" << std::endl;
        // } else if (nextCell == CellType::Passage) {
        //     std::cout << "enemy passage" << std::endl;
        // } else if (nextCell == CellType::Stair) {
        //     std::cout << "enemy stair" << std::endl;
        // } else if (nextCell == CellType::Item) {
        //     std::cout << "enemy item" << std::endl;
        // } else {
        //     std::cout << "enemy invalid" << std::endl;
        // }

        if (nextCell == CellType::Room) { //enemies can only move to the "Room" cell type
        // if (randomDirection == Direction::North) {
        //     std::cout << "random direction north" << std::endl;
        // } else if (randomDirection == Direction::East) {
        //     std::cout << "random direction east" << std::endl;
        // } else if (randomDirection == Direction::West) {
        //     std::cout << "random direction west" << std::endl;
        // } else if (randomDirection == Direction::South) {
        //     std::cout << "random direction south" << std::endl;
        // } else if (randomDirection == Direction::Northeast) {
        //     std::cout << "random direction northeast" << std::endl;
        // } else if (randomDirection == Direction::Northwest) {
        //     std::cout << "random direction northwest" << std::endl;
        // } else if (randomDirection == Direction::Southeast) {
        //     std::cout << "random direction southeasat" << std::endl;
        // } else if (randomDirection == Direction::Southwest) {
        //     std::cout << "random direction southwest" << std::endl;
        // }
            std::cout << positionX << " " << positionY << std::endl;
            move(randomDirection);  
            std::cout << "second: " << std::endl;
            std::cout << positionX << " " << positionY << std::endl;
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
