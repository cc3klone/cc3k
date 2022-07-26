#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include <utility>

class Item;
class Enemy;
class Player;

enum class CellType {Invalid, Room, Wall, Passage, Stair, Item, Character};
enum class Direction {North, East, South, West, Northeast, Northwest, Southeast, Southwest};

class Floor {
    std::vector<std::vector<pair<char, void *>>> gameMap;
    std::vector<std::vector<pair<char>>> roomTracker;
    std::vector<Item *> floorItems;
    std::vector<Enemy *> floorEnemies;
    Player *player;

    public:
        Floor();
        ~Floor();

        void cmdDisplay();

        // Getters and Setters
        CellType checkCoord(int, int);
        Player *getPlayer();
        void setPlayer(Player *);
        Item *popItem(int, int);
        Enemy *checkEnemy(int, int);
        
        void generateEntities(); // Still need to track rooms
        void moveEnemies(); // Loop through map, check if enemy is next to player, if so, attack
        void killEnemy(pair<int, int>);
};

#endif

