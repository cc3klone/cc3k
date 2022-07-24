#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include "gamecontroller.h"
using namespace std;

void GameController::initGame() {
    // Clear floors
    floors.clear();
    currentFloor = 0;
    for(int i = 0; i < 5; i++) floors.push_back(Floor());

    // Load floors
    loadFloors(path);
    for(int i = 1; i < 5; i++) floors[i].map = floors[0].map;

    // Spawn player

    // Spawn entities
    for(int i = 0; i < 5; i++) floors[i].spawnEntities();
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
    string cmd;
    bool attack = false, potion = false;
    Direction target;

    while(cin >> cmd) {
        switch(cmd) {
            case "u":
                potion = true;
                break;
            case "a":
                attack = true;
                break;
            case "r":
                cout << "Restart signal caught, restarting game" << endl;
                initGame();
                break;
            case "q":
                cout << "Quit signal caught, ending game";
                endGame();
                return;
            default:
                switch(cmd) {
                    case "no":
                        target = Direction::North;
                        break;
                    case "ea":
                        target = Direction::East;
                        break;
                    case "so":
                        target = Direction::South;
                        break;
                    case "we":
                        target = Direction::West;
                        break;
                    case "ne":
                        target = Direction::Northeast;
                        break;
                    case "nw":
                        target = Direction::Northwest;
                        break;
                    case "se":
                        target = Direction::Southeast;
                        break;
                    case "sw":
                        target = Direction::Southwest;
                        break;
                }

                if(attack) {
                    floors[currentFloor].player->playerAttack(target);
                    attack = false;
                } else if(potion) {
                    floors[currentFloor].player->playerPickup(target);
                    potion = false;
                } else floors[currentFloor].player->playerMove(target);

                break;
        }
    }
}

void GameController::ascendFloor() {
    floors[currentFloor].player->resetStat();

    if(currentFloor != 4) {
        floors[currentFloor + 1].player = floors[currentFloor].player;
        floors[currentFloor].player = nullptr;
        currentFloor++;
    } else {
        currentFloor++;
        endGame();
    }
}

void GameController::endGame() {
    if(currentFloor == 5) {
        // Score display on victory
        cout << "You Won." << endl;
        cout << "Score: " << floors[currentFloor].player->getScore << endl;

        char cmd = 0;
        while(cmd != 'c' && cmd != 'C') cin >> cmd;
        
        // Display credits
        cout << "Thanks for playing CC3k!" << endl;
        cout << endl << "Credits" << endl;
        cout << "Frank Tao" << endl;
        cout << "William Zhao" << endl;
        cout << "Lily Cao" << endl;

        // Diplay GPL
        cout << endl << "Copyright (C) 2022 Frank Tao, William Zhao, and Lily Cao" << endl;
        cout << endl << "This program is free software: you can redistribute it and/or modify" << endl;
        cout << "it under the terms of the GNU General Public License as published by" << endl;
        cout << "the Free Software Foundation, version 3 of the License." << endl;
        cout << endl << "This software is distributed in the hope that it will be useful," << endl;
        cout << "but WITHOUT ANY WARRANTY; without even the implied warranty of" << endl;
        cout << "MERCHANTABILITY or FITNESS FOR A PARTICULAR PRUPOSE. See the" << endl;
        cout << "GNU General Public License for more details." << endl;
        cout << endl << "You should have received a copy of the GNU General Public License" << endl;
        cout << "Along with this program. If not, see <https://www.gnu.org/licenses/>" << endl;


    } else {
        // Score display on loss
        cout << "You Died." << endl;
        cout << "Score: " << floors[currentFloor].player->getScore << endl;
    }
}
