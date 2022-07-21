#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include <vector>
#include <string>
#include "observer.h"
#include "floor/floor.h"

class GameController : public Observer {
    std::vector<Floor> floors;

    public:
        void loadFloors(std::string);
        void updateEnemies();
        void moveEnemies();
};

#endif

