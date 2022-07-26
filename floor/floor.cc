#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include "floor.h"
#include "../item/item.h"
#include "../character/enemy/enemy.h"
#include "../character/player/player.h"
using namespace std;

Floor::Floor() {}

Floor::~Floor() {
    for(auto i = floorItems.begin(); i != floorItems.end(); i++) delete *i;
    for(auto i = floorEnemies.begin(); i != floorEnemies.end(); i++) delete *i;
    delete player;
}

void Floor::generateEntities() {}

// Fix this later to account for enemy attack too
void Floor::moveEnemies() {
    for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
        for(auto j = *i.begin(); j != *j.end(); j++) {
            if(checkCoord(i, j) != CellType::Character) continue;

            gameMap[i][j].second->move();
            if(gameMap[i][j].second->isInRange(player->getPos())) gameMap[i][j].second->attack(player);
        }
    }
}

void Floor::killEnemy(pair<int, int> coord) {
    Item *inventory = gameMap[coord.first, coord.second].second->getInventory();
    delete gameMap[coord.first, coord.second].second;

    if(inventory == nullptr) {
        // Remove Item from map
        gameMap[coord.first][coord.second].first = '.';
        gameMap[coord.first][coord.second].second = nullptr;
    } else {
        // DROP ITEM HERE
    }
}


void Floor::cmdDisplay() {
    for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
        for(auto j = *i.begin(); j != *j.end(); j++) {
            if(*j == '\\' && player->getHasCompass() == false) cout << '.';
            cout << *j;
        }
        cout << endl;
    }
}

void Floor::setTile(int x, int y, char val) {
    gameMap[x][y] = val;
}

Player *Floor::getPlayer() {
    return player;
}

void Floor::setPlayer(Player *p) {
    player = p;
    return;
}

CellType Floor::checkCoord(int x, int y) {
    char val;

    try {
        val = gameMap[x][y].first;
    } catch(out_of_range &e) {
        return CellType::Invalid;
    }

    switch(val) {
        case ' ':
            return CellType::Invalid;
            break;
        case '.':
            return CellType::Room;
            break;
        case '-':
            return CellType::Wall;
            break;
        case '|':
            return CellType::Wall;
            break;
        case '+':
        case '#':
            return CellType::Passage;
            break;
        case '\\':
            return CellType::Stair;
            break;
        case 'V':
        case 'W':
        case 'N':
        case 'D':
        case 'X':
        case 'T':
        case 'M':
            return CellType::Character;
            break;
        default:
            return CellType::Item;
            break;
    }

    return CellType::Invalid;
}

Item *Floor::popItem(int x, int y) {
    void *object;

    try {
        object = gameMap[x][y].second;
    } catch(out_of_range &e) {
        return nullptr;
    }

    // Checks that the object at x, y is actually an item; Removes it from the gameMap and returns its pointer if so
    auto iter = find(floorItems.begin(), floorItems.end(), object);
    if(iter != floorItems.end()) {
        
        // Checks that the item is not being guarded
        if(*iter->getGuardingEnemy() != nullptr) return nullptr;

        gameMap[x][y].first = '.';
        gameMap[x][y].second = nullptr;
        floorItems.erase(iter);

        return static_cast<Item *>(object);
    }

    return nullptr;
}

Enemy *Floor::checkEnemy(int x, int y) {
    void *object;

    // Checks if x, y
    try {
        object = gameMap[x][y].second;
    } catch(out_of_range &e) {
        return nullptr;
    }
    
    // Checks that the object at x, y is actually an enemy
    if(checkCoord(x, y) == CellType::Character) return static_cast<Enemy *>(object);
    return nullptr;
}

