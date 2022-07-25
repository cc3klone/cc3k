#include <iostream>
#include <string>
#include "gamecontroller.h"
using namespace std;

int main(int argc, char **argv) {
    if(argc != 2) {
        cerr << "Error: no map specified. Exiting." << endl;
        return 1;
    }

    string path(argv[1]);
    GameController *controller = new GameController(path);
    controller->initGame();

    delete controller;
    return 0;
}
