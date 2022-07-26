#ifndef _GAMECONTROLLER_H_
#define _GAMECONTROLLER_H_
#include <vector>
#include <string>

class Floor;

class GameController {
    std::vector<Floor> floors;
    int currentFloor;
    string path;

    bool merchantIsHostile;

    public:
        GameController(std::string);
        ~GameController();

        void initGame();
        void loadFloor(std::string);
        void listenInput();

        void ascendFloor();
        void endGame();
};

#endif

