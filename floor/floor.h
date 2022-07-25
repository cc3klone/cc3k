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
enum class Direction {North, East, South, West, Northeast, Northwest, Southeast, Southwest};

class Floor {
    std::vector<std::vector<pair<char, void *>>> map;
    std::vector<Items *> floorItems;
    std::vector<Enemy *> floorEnemies
    Player *player;

    public:
        Floor();
        ~Floor();

        void cmdDisplay();
        CellType checkCoord(int, int);
        Player *getPlayer();
        Item *popItem(int, int);
        Enemy *checkEnemy(int, int);

        void generateEntities(); // Still need to track rooms
        void moveEnemies(); // Loop through map, check if enemy is next to player, if so, attack
        void killEnemy(pair<int, int>);
};

#endif

