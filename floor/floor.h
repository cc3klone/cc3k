#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include <utility>
#include "../observer.h"
#include "../subject.h"
#include "../item/item.h"
#include "../character/enemy/enemy.h"
#include "../character/player/player.h"

enum class CellType {Invalid, Room, Wall, Passage, Stair, Item, Character};
enum class Direction {North, East, South, West};

class Floor : public Observer, public Subject {
    std::vector<std::vector<pair<char, void *>>> map;
    std::vector<Items *> floorItems;
    std::vector<Enemy *> floorEnemies
    Player *player;

    public:
        void cmdDisplay();
        CellType checkCoord(int, int);
        Item *checkItem(int, int);
        Enemy *checkEnemy(int, int);
};

#endif

