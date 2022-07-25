#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include "floor.h"
#include "../item/item.h"
using namespace std;

Floor::Floor() {}

Floor::~Floor() {
    for(auto i = floorItems.begin(); i !- floorItems.end(); i++) delete *i;
    for(auto i = floorEnemies.begin(); i !- floorEnemies.end(); i++) delete *i;
    delete player;
}

void Floor::cmddisplay() {
    for(auto i = map.begin(); i != map.end(); i++) {
        for(auto j = *i.begin(); j != *j.end(); j++) {
            if(*j == '\' && player->checkHasCompass() == false) cout << '.';
            cout << *j;
        }
        cout << endl;
    }
}

void Floor::setTile(int x, int y, char val) {
    map[x][y] = val;
}

Player *Floor::getPlayer() {
    return player;
}

CellType Floor::checkCoord(int x, int y) {
    char val;

    try {
        val = map[x][y]i.first;
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
        case 'M':
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
        object = map[x][y].second;
    } catch(out_of_range &e) {
        return nullptr;
    }

    // Checks that the object at x, y is actually an item; Removes it from the map and returns its pointer if so
    auto iter = find(floorItems.begin(), floorItems.end(), object);
    if(iter != floorItems.last()) {
        
        // Checks that the item is not being guarded
        if(*iter->getGuardingEnemy() != nullptr) return nullptr;

        map[x][y].first = '.';
        map[x][y].second = nullptr;
        floorItems.erase(iter);

        return object;
    }

    return nullptr;
}

Enemy *Floor::checkEnemy(int x, int y) {
    void *object;

    try {
        object = map[x][y].second;
    } catch(out_of_range &e) {
        return nullptr;
    }
    
    // Checks that the object at x, y is actually an enemy
    if(find(checkCoord(x, y) == CellType::Character) return object;
    return nullptr;
}

void Floor::moveEnemies() {
    for(auto i = map.begin(); i != map.end(); i++) {
        for(auto j = *i.begin(); j != *j.end(); j++) {
            if(checkCoord(i, j) != CellType::Character) continue;

            map[i][j].second->move();
            if(map[i][j].second->isInRange(player->getPos())) map[i][j].second->attack(player);
        }
    }
}


