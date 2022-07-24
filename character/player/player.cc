#include "player.h"
#include <cmath>
#include <utility>

Player::Player(int positionX, int positionY, Floor *thisFloor) {
    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->health = 140;
    this->maxHealth = 140;
    this->gold = 0;
    this->baseAtk = 20;
    this->baseDef = 20;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    this->score = 0;
    this->playerVisitor = HumanVisitor{};
    this->hasBarrierSuit = false;
    this->hasCompass = false;
}

Player::Player(PlayerRace playerRace, int positionX, int positionY, Floor *thisFloor) {
    switch (playerRace) {
    case PlayerRace::Human:
        this->health = 140;
        this->maxHealth = 140;
        this->baseAtk = 20;
        this->baseDef = 20;
        this->playerVisitor = HumanVisitor{};
        break;
    
    case PlayerRace::Dwarf:
        this->health = 100;
        this->maxHealth = 100;
        this->baseAtk = 20;
        this->baseDef = 30;
        this->playerVisitor = DwarfVisitor{};
        break;
    
    case PlayerRace::Elves:
        this->health = 140;
        this->maxHealth = 140;
        this->baseAtk = 30;
        this->baseDef = 10;
        this->playerVisitor = ElvesVisitor{};
        break;
    
    case PlayerRace::Ore:
        this->health = 180;
        this->maxHealth = 180;
        this->baseAtk = 30;
        this->baseDef = 25;
        this->playerVisitor = OrcVisitor{};
        break;

    default:
        break;
    }

    this->thisFloor = thisFloor;
    this->positionX = positionX;
    this->positionY = positionY;
    this->gold = 0;
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->moveSpeed = 1;
    this->defaultAtk = AttackType::Melee;
    this->score = 0;
    this->hasBarrierSuit = false;
    this->hasCompass = false;
}

void Player::inventoryAdd(Item *item) {
    this->inventory.push_back(item);
}

void Player::inventoryDrop(Item *item) { //needs to be changed
    Item *toBeRemoved = nullptr;
    for (std::size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i] == item) {
            toBeRemoved = inventory[i];
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
    delete toBeRemoved;
}

int Player::inventoryFind(int uuid) {
    for (std::size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i]->getId() == uuid) {
            return i;
        }
    }
    return -1;
}

void Player::playerAttack(Direction attackDirection) {
    std::pair<int, int> attackPosn = changePosition(attackDirection, this->positionX, this->positionY, 1);
    Enemy *target = thisFloor->checkEnemy(attackPosn.first, attackPosn.second);
    if (target == nullptr) return;
    attack(target);
}

void Player::playerMove(Direction moveDirection) {
    std::pair<int, int> movePosn = changePosition(moveDirection, this->positionX, this->positionY, this->moveSpeed);
    CellType moveCell = thisFloor->checkCoord(movePosn.first, movePosn.second);
    
    if (moveCell == CellType::Room || moveCell == CellType::Passage || moveCell == CellType::Stair) {
        move(moveDirection);
        return;
    }
}

void Player::playerPickup(Direction pickupDirection) {
    std::pair<int, int> pickupPosn = changePosition(pickupDirection, this->positionX, this->positionY, 1);
    Item *item = thisFloor->popItem(pickupPosn.first, pickupPosn.second);
    if (item == nullptr) return;
    item->onPickup(this);
}

void Player::getAttacked(int damage) {
    if (hasBarrierSuit) {
        this->health -= ceil(damage/2);
    } else {
        this->health -= damage;
    }
    
}

void Player::resetStat() {
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->hasCompass = false;
}

void Player::setAtk(int addAtk) {
    playerVisitor.setAtk(currentAtk, addAtk);
}

void Player::setDef(int addDef) {
    playerVisitor.setDef(currentDef, addDef);
}

void Player::setHp(int addHP) {
    playerVisitor.setHP(health, maxHealth, addHP);
}

void Player::setGold(int addGold) {
    playerVisitor.setGold(gold, addGold);
}

void Player::setHasCompass() {
    this->hasCompass = true;
}

void Player::setHasBarrierSuit() {
    this->hasBarrierSuit = true;
}

bool Player::getHasCompass() {
    return this->hasCompass;
}

double Player::getScore() {
    this->score = this->gold;
    return this->score;
}