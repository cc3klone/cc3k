#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <stdexcept>
#include "floor.h"
#include "../item/item.h"
#include "../item/potion.h"
#include "../item/gold.h"
#include "../character/enemy/enemy.h"
#include "../character/enemy/werewolf.h"
#include "../character/enemy/vampire.h"
#include "../character/enemy/goblin.h"
#include "../character/enemy/troll.h"
#include "../character/enemy/phoenix.h"
#include "../character/enemy/merchant.h"
#include "../character/player/player.h"
#include "../rng.h"
using namespace std;

Floor::Floor() {}

Floor::~Floor() {
    for(auto i = floorItems.begin(); i != floorItems.end(); i++) delete *i;
    for(auto i = floorEnemies.begin(); i != floorEnemies.end(); i++) delete *i;
    delete player;
}

pair<int, int> Floor::randCoord() {
    RNG *random = new RNG();

    pair<int, int> coord(random->generateInt(roomTracker.size() - 1), random->generateInt(roomTracker[0].size() - 1));
    while(checkCoord(coord.first, coord.second) != CellType::Room) {
         cout << "TESTING: " << coord.first << " " << coord.second << endl;

        coord.first = random->generateInt(roomTracker.size() - 1);
        coord.second = random->generateInt(roomTracker[0].size() - 1);
    }

    delete random;
    return coord;
}

// Generation order: Player, Stair, Potion, Gold, Enemy
// Player should already be generated at this point
void Floor::generateEntities() {
    // Generate stair location
    pair<int, int> playerCoord = player->getPos();
    char playerRoom = roomTracker.at(playerCoord.first).at(playerCoord.second);

    pair<int, int> stairCoord = randCoord();
    while(roomTracker.at(stairCoord.first).at(stairCoord.second) == playerRoom) {
        stairCoord = randCoord();
    }

    // Add stairs to map
    gameMap.at(stairCoord.first).at(stairCoord.second).first = '\\';
    gameMap.at(stairCoord.first).at(stairCoord.second).second = nullptr;


    RNG *random = new RNG();
    
    // Spawn potions
    for(int i = 0; i < 10; i++) {
        // Generate potion location
        int room = random->generateInt(4);
        pair<int, int> coord;
        while(roomTracker.at(coord.first).at(coord.second) != room + '0') {
            coord = randCoord();
        }

        // Generate potion and add to map
        Item *potion = new Potion();
        this->floorItems.push_back(potion);
        gameMap.at(coord.first).at(coord.second).first = 'P';
        gameMap.at(coord.first).at(coord.second).second = potion;
    }
    
    // Spawn gold
    for(int i = 0; i < 10; i++) {
        // Generate gold location
        int room = random->generateInt(4);
        pair<int, int> coord;
        while(roomTracker.at(coord.first).at(coord.second) != room + '0') {
            coord = randCoord();
        }

        // Generate gold and add to map
        Item *gold = new Gold();
        this->floorItems.push_back(gold);
        gameMap.at(coord.first).at(coord.second).first = 'G';
        gameMap.at(coord.first).at(coord.second).second = gold;
    }

    // Note: please spawn dragons beforehand so we know how many other enemies to spawn
    
    // Spawn enemies
    int numEnemies = 20 - floorEnemies.size();
    cout << "numEnemies = " << numEnemies << endl;
    for(int i = 0; i < numEnemies; i++) {
        // Generate enemy location
        int room = random->generateInt(4);
        pair<int, int> coord;
        while(roomTracker.at(coord.first).at(coord.second) != room + '0') {
            coord = randCoord();
        }

        // Generate enemies and add to map
        int n = random->generateInt(17);
        if (n < 4) {
	    cout << "W" << endl;
            Werewolf *werewolf = new Werewolf(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'W';
            gameMap.at(coord.first).at(coord.second).second = werewolf;
            this->floorEnemies.push_back(werewolf);
        } else if (n < 7) {
	    cout << "V" << endl;
            Vampire *vampire = new Vampire(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'V';
            gameMap.at(coord.first).at(coord.second).second = vampire;
            this->floorEnemies.push_back(vampire);
        } else if (n < 12) {
	    cout << "N" << endl;
            Goblin *goblin = new Goblin(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'N';
            gameMap.at(coord.first).at(coord.second).second = goblin;
            this->floorEnemies.push_back(goblin);
        } else if (n < 14) {
	    cout << "T" << endl;
            Troll *troll = new Troll(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'T';
            gameMap.at(coord.first).at(coord.second).second = troll;
            this->floorEnemies.push_back(troll);
        } else if (n < 16) {
	    cout << "X" << endl;
            Phoenix *phoenix = new Phoenix(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'X';
            gameMap.at(coord.first).at(coord.second).second = phoenix;
            this->floorEnemies.push_back(phoenix);
        } else {
	    cout << "M" << endl;
            Merchant *merchant = new Merchant(coord.first, coord.second, this, nullptr);
            gameMap.at(coord.first).at(coord.second).first = 'M';
            gameMap.at(coord.first).at(coord.second).second = merchant;
            this->floorEnemies.push_back(merchant);
        }
    }
    
    
    
    delete random;

    

}

// Fix this later to account for enemy attack too
void Floor::moveEnemies() {
    /*
    for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
        for(auto j = (*i).begin(); j != (*i).end(); j++) {
            if(checkCoord(i, j) != CellType::Character) continue;

            static_cast<Enemy *>((*j).second)->move();
            if(static_cast<Enemy *>((*j).second)->isInRange(player->getPos())) static_cast<Enemy *>((*j).second)->attack(player);
        }
    }
    */
}

void Floor::killEnemy(pair<int, int> coord) {
    std::cout << "enemy posn: " << coord.first << " " << coord.second << std::endl;
    Enemy *enemy = static_cast<Enemy *>(gameMap[coord.first][coord.second].second);
    Item *inventory = enemy->getInventory();
    delete gameMap[coord.first][coord.second].second;
    
    if(inventory == nullptr) {
        // Remove Item from map
        gameMap[coord.first][coord.second].first = '.';
        gameMap[coord.first][coord.second].second = nullptr;
        std::cout << "asdasd" << std::endl;
    } else {
        // DROP ITEM HERE
    }
}


void Floor::cmdDisplay() {
    for(auto i = gameMap.begin(); i != gameMap.end(); i++) {
        for(auto j = (*i).begin(); j != (*i).end(); j++) {
            // if((*j).first == '\\' && player->getHasCompass() == false) cout << '.';
            /*else*/ cout << (*j).first;
        }
        cout << endl;
    }
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
        val = gameMap.at(x).at(y).first;
    } catch(exception &e) {
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
        object = gameMap.at(x).at(y).second;
    } catch(out_of_range &e) {
        return nullptr;
    }

    // Checks that the object at x, y is actually an item; Removes it from the gameMap and returns its pointer if so
    auto iter = find(floorItems.begin(), floorItems.end(), object);
    if(iter != floorItems.end()) {
        
        // Checks that the item is not being guarded
        if((*iter)->getGuardingEnemy() != nullptr) return nullptr;

        gameMap[x][y].first = '.';
        gameMap[x][y].second = nullptr;
        floorItems.erase(iter);

        return static_cast<Item *>(object);
    }

    return nullptr;
}

Item *Floor::checkItem(int x, int y) {
    void *object;

    // Checks if x, y
    try {
        object = gameMap.at(x).at(y).second;
    } catch(out_of_range &e) {
        return nullptr;
    }
    
    // Checks that the object at x, y is actually an item
    if(checkCoord(x, y) == CellType::Item) return static_cast<Item *>(object);
    return nullptr;
}

Enemy *Floor::checkEnemy(int x, int y) {
    void *object;

    // Checks if x, y
    try {
        object = gameMap.at(x).at(y).second;
    } catch(out_of_range &e) {
        return nullptr;
    }
    
    // Checks that the object at x, y is actually an enemy
    if(checkCoord(x, y) == CellType::Character) return static_cast<Enemy *>(object);
    return nullptr;
}

