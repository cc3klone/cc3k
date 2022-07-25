#include "enemy.h"
#include <random>
#include <map>
#include <chrono>

Direction Enemy::generateDirection() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(0, 7);
	Direction randomDirection = static_cast<Direction>(distr(rng));
    return randomDirection;
}

bool Enemy::attackMissed() {
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng{seed};
    std::uniform_int_distribution<> distr(0, 1);
	int randomAttack = static_cast<int>(distr(rng));
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
    /*
    if (check if character is dead) {
        transfer gold into player
        drop inventory item (kill character function to floor)
        remove itself from the map and dealloc its memory (kill character function to floor)
    }
    */
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
        changePosition(randomDirection, tempX, tempY);
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

void Enemy::transferGold(Player *player) {
    player->setGold(this->gold);
}


Item *Enemy::getInventory() {
    return inventory;
}

void Enemy::setInventory(Item *inventory) {
    this->inventory = inventory;
}

Enemy::~Enemy() {
    delete this;
}
