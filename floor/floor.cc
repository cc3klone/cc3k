#include <vector>
#include <algorithm>
#include <stdexcept>
#include "floor.h"
#include "../item/item.h"
using namespace std;

void Floor::cmddisplay() {
    for(auto i = map.begin(); i != map.end(); i++) {
        for(auto j = *i.begin(); j != *j.end(); j++) {
            cout << *j;
        }
        cout << endl;
    }
}

CellType Floor::checkCoord(int x, int y) {
    char val;

    try {
        val = map[x][y]i.first();
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
        object = map[x][y].second();
    } catch(out_of_range &e) {
        return nullptr;
    }

    // Checks that the object at x, y is actually an item; Removes it from the map and returns its pointer if so
    auto iter = find(floorItems.begin(), floorItems.end(), object);
    if(iter != floorItems.last()) {
        map[x][y].first() = '.';
        map[x][y].second() = nullptr;
        floorItems.erase(iter);

        return object;
    }

    return nullptr;
}

Enemy *Floor::checkEnemy(int x, int y) {
    void *object;

    try {
        object = map[x][y].second();
    } catch(out_of_range &e) {
        return nullptr;
    }
    
    // Checks that the object at x, y is actually an enemy
    if(find(floorEnemies.begin(), floorEnemies.end(), object) != floorEnemies.last()) return object;
    return nullptr;
}
