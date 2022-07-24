#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include "gamecontroller.h"
using namespace std;

void GameController::initGame() {
    floors.clear();
    for(int i = 0; i < 5; i++) floors.push_back(Floor());

    loadFloors(path);
    for(int i = 0; i < 5; i++) floors[i].map = floors[0].map;

    currentFloor = 0;
}

void GameController::loadFloor(string path) {
    string line;
    ifstream instream(path);

    int i = 0;
    while(getline(instream, line)) {
        stringstream ss(line);
        char tile;

        floors[0].map.push_back(vector<pair<char, void *>>());
        while(ss >> tile) map[i].push_back(pair<char, void *>(tile, nullptr));

        i++;
    }
}

void gameController::listenInput() {
    
