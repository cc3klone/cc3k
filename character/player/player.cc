#include <math.h>
#include <utility>
#include "player.h"
#include "humanvisitor.h"
#include "dwarfvisitor.h"
#include "elvesvisitor.h"
#include "orcvisitor.h"
#include "../../item/item.h"
#include "../../item/compass.h"
#include "../../item/gold.h"
#include "../enemy/merchant.h"
#include "../../floor/floor.h"
#include <iostream>

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
    this->playerVisitor = new HumanVisitor{};
    this->hasBarrierSuit = false;
    this->hasCompass = false;
    this->myRace = PlayerRace::Human;
}

Player::Player(PlayerRace playerRace, int positionX, int positionY, Floor *thisFloor) {
    switch (playerRace) {
    case PlayerRace::Human:
        this->health = 140;
        this->maxHealth = 140;
        this->baseAtk = 20;
        this->baseDef = 20;
        this->playerVisitor = new HumanVisitor{};
        break;
    
    case PlayerRace::Dwarf:
        this->health = 100;
        this->maxHealth = 100;
        this->baseAtk = 20;
        this->baseDef = 30;
        this->playerVisitor = new DwarfVisitor{};
        break;
    
    case PlayerRace::Elves:
        this->health = 140;
        this->maxHealth = 140;
        this->baseAtk = 30;
        this->baseDef = 10;
        this->playerVisitor = new ElvesVisitor{};
        break;
    
    case PlayerRace::Ore:
        this->health = 180;
        this->maxHealth = 180;
        this->baseAtk = 30;
        this->baseDef = 25;
        this->playerVisitor = new OrcVisitor{};
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
    this->myRace = playerRace;
}

void Player::inventoryAdd(Item *item) {
    this->inventory.push_back(item);
}

void Player::inventoryDrop(Item *item) {
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


bool Player::playerAttack(Direction attackDirection) {
    bool attackedMerchant = false;
    std::pair<int, int> attackPosn = changePosition(attackDirection, this->positionX, this->positionY, 1);
    Enemy *target = thisFloor->checkEnemy(attackPosn.first, attackPosn.second);
    if (target == nullptr) return false;
    Merchant *merchant = dynamic_cast<Merchant *>(target);
    if (merchant != nullptr) {
        attackedMerchant = true;
    }
    attack(target);
    return attackedMerchant;
}

bool Player::playerMove(Direction moveDirection) {
    std::pair<int, int> movePosn = changePosition(moveDirection, this->positionX, this->positionY, this->moveSpeed);
    std::cout << this->positionX << " : " << this->positionY << std::endl;
    CellType moveCell = thisFloor->checkCoord(movePosn.first, movePosn.second);

    //test if-statment
    std::cout << movePosn.first << " : " << movePosn.second << std::endl;
    if (moveCell == CellType::Room) {
        std::cout << "room" << std::endl;
    } else if (moveCell == CellType::Passage) {
        std::cout << "passage" << std::endl;
    } else if (moveCell == CellType::Stair) {
        std::cout << "stair" << std::endl;
    } else if (moveCell == CellType::Item) {
        std::cout << "item" << std::endl;
    } else {
        std::cout << "invalid" << std::endl;
    }
    

    if (moveCell == CellType::Room || moveCell == CellType::Passage || moveCell == CellType::Stair) {
        move(moveDirection);
        return true;
    }
    if (moveCell == CellType::Item) {
        Gold *item = dynamic_cast<Gold *> (thisFloor->checkItem(movePosn.first, movePosn.second));
        if (item == nullptr) {
            return false;
        } else {
            item->onPickup(this);
            std::cout << "Gold: " << this->gold << std::endl;
            move(moveDirection);
            delete item;
            return true;
        }
    }
    return false;
}

void Player::playerPickup(Direction pickupDirection) {
    std::pair<int, int> pickupPosn = changePosition(pickupDirection, this->positionX, this->positionY, 1);
    Item *item = thisFloor->popItem(pickupPosn.first, pickupPosn.second);
    if (item == nullptr) return;
    item->onPickup(this);
    std::cout << "Atk: " << this->currentAtk << std::endl;
    std::cout << "HP: " << this->health << std::endl;
    std::cout << "Def: " << this->currentDef << std::endl;
    delete item;
}

void Player::getAttacked(int damage) {
    if (hasBarrierSuit) {
        this->health -= ceil(damage/2);
    } else {
        this->health -= damage;
    }
    
}

void Player::resetStat() { //not sure if this is how you use dynamic_cast might have to change
    this->currentAtk = this->baseAtk;
    this->currentDef = this->baseDef;
    this->hasCompass = false;
    Compass *toBeRemoved = nullptr;
    for (int i = 0; i < inventory.size(); i++) {
        toBeRemoved = dynamic_cast<Compass *> (inventory[i]);
        if (toBeRemoved != nullptr) break;
    }
    delete toBeRemoved;
}

void Player::setAtk(int addAtk) {
    playerVisitor->setAtk(currentAtk, addAtk);
}

void Player::setDef(int addDef) {
    playerVisitor->setDef(currentDef, addDef);
}

void Player::setHp(int addHP) {
    playerVisitor->setHP(health, maxHealth, addHP);
}

void Player::setGold(int addGold) {
    playerVisitor->setGold(gold, addGold);
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

PlayerRace Player::getRace() {
    return this->myRace;
}

void Player::setFloor(Floor *floor) {
    this->thisFloor = floor;
}

Player::~Player() {
    for(int i = 0; i < this->inventory.size(); i++) {
        delete inventory[i];
    }
    delete playerVisitor;
}
