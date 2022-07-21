#ifndef _FLOOR_H_
#define _FLOOR_H_
#include <vector>
#include "../observer.h"
#include "../subject.h"
#include "../item/item.h"
#include "../character/enemy.h"

enum class CellType {Room, Wall, Passage, Stair};
enum class Direction {North, East, South, West};

class Floor : public Observer, public Subject {
    vector<vector<char>> map;
    vector<Items *> floorItems;
    vector<Enemy *> floorEnemies

    public:
        void cmdDisplay();
        CellType checkCoord(int, int);
};

#endif

