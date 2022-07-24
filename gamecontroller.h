#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include <vector>
#include <string>
#include "observer.h"
#include "floor/floor.h"

class GameController : public Observer {
    std::vector<Floor> floors;
    int currentFloor;
    string path;

    public:
        void initGame();
        void loadFloor(std::string);
        void spawnEntities();
        void listenInput();

        void ascendFloor();
        void endGame();
};

#endif

