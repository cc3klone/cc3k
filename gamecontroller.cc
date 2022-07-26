#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <utility>
#include "character/player/player.h"
#include "gamecontroller.h"
#include "floor/floor.h"

using namespace std;

GameController::GameController(string path): path{path} {}

GameController::~GameController() {
    floors.clear();
}

void GameController::initGame() {
    // Resets variables
    currentFloor = 0;
    merchantIsHostile = false;

    // Clear floors
    floors.clear();
    for(int i = 0; i < 5; i++) floors.push_back(Floor());

    // Load floors to first floor, then copies floor layout to all floors
    loadFloor(path);
    for(int i = 1; i < 5; i++) floors[i].gameMap = floors[0].gameMap;

    // Creates player object - DOES NOT PLACE IT ONTO THE MAP
    cout << "Please pick a class: (H)uman, (E)lf, (D)warf, (O)rc" << endl;
    char playerClass;
    cin >> playerClass;
    switch(playerClass) {
        case 'H':
        case 'h':
            floors[0].setPlayer(new Player(PlayerRace::Human, 0, 0, &floors[0]));
            cout << "You picked the human class!" << endl;
            break;
        case 'E':
        case 'e':
            floors[0].setPlayer(new Player(PlayerRace::Elves, 0, 0, &floors[0]));
            cout << "You picked the elf class!" << endl;
            break;
        case 'D':
        case 'd':
            floors[0].setPlayer(new Player(PlayerRace::Dwarf, 0, 0, &floors[0]));
            cout << "You picked the dwarf class!" << endl;
            break;
        case 'O':
        case 'o':
            floors[0].setPlayer(new Player(PlayerRace::Ore, 0, 0, &floors[0]));
            cout << "You picked the orc class!" << endl;
            break;
        default:
            // Human class is default
            floors[0].setPlayer(new Player(PlayerRace::Human, 0, 0, &floors[0]));
            cout << "You did not pick a valid class. You have been defaulted to the human class!" << endl;
            break;
    }

    // Spawn entities - Order: Player, Stair, Potion, Gold, Enemy
    for(int i = 0; i < 5; i++) floors[i].generateEntities();

    floors[0].cmdDisplay();
}

void GameController::loadFloor(string path) {
    // Loads floorplan to first floor only

    string line;
    ifstream instream(path);

    int i = 0;
    while(getline(instream, line)) {
        stringstream ss(line);
        char tile;

        // Read floor plan to Room Tracker and Game Map
        floors[0].roomTracker.push_back(vector<char>());
        floors[0].gameMap.push_back(vector<pair<char, void *>>());

        while(ss.get(tile)) {
            cout << "|" << tile << "|" << endl;
            floors[0].roomTracker[i].push_back(tile);
            if(tile >= '0' && tile <= '9') floors[0].gameMap[i].push_back(pair<char, void *>('.', nullptr));
            else floors[0].gameMap[i].push_back(pair<char, void *>(tile, nullptr));
        }

        i++;
    }

    instream.close();
}

void GameController::listenInput() {
    string cmd;
    bool attack = false, potion = false;
    Direction target;

    while(cin >> cmd) {
        /*
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
                    if(floors[currentFloor].getPlayer()->playerAttack(target)) merchantIsHostile = true;
                    attack = false;

                    floors[currentFloor].moveEnemies();
                } else if(potion) {
                    floors[currentFloor].getPlayer()->playerPickup(target);
                    potion = false;
                } else {
                    floors[currentFloor].getPlayer()->playerMove(target);
                    pair<int, int> coords = floors[currentFloor].getPlayer()->getPos();
                    
                    // Checks if player is on a stair, if so go up a floor
                    if(floors[currentFloor].checkCoord(coords.first, coords.second) == CellType::Stair) ascendFloor();
                    else floors[currentFloor].moveEnemies();
                }

                break;
        }
        */
        if (cmd == "u") {
            potion = true;
        } else if (cmd == "a") {
            attack = true;
        } else if (cmd == "r") {
            cout << "Restart signal caught, restarting game" << endl;
            initGame();
        } else if (cmd == "q") {
            cout << "Quit signal caught, ending game";
            endGame();
            return;
        } else {
            if (cmd == "no") {
                target = Direction::North;
            } else if (cmd == "ea") {
                target = Direction::East;
            } else if (cmd == "so") {
                target = Direction::South;
            } else if (cmd == "we") {
                target = Direction::West;
            } else if (cmd == "ne") {
                target = Direction::Northeast;
            } else if (cmd == "nw") {
                target = Direction::Northwest;
            } else if (cmd == "se") {
                target = Direction::Southeast;
            } else if (cmd == "sw") {
                target = Direction::Southwest;
            }

            if(attack) {
                if(floors[currentFloor].getPlayer()->playerAttack(target)) merchantIsHostile = true;
                attack = false;
                floors[currentFloor].moveEnemies();
            } else if(potion) {
                floors[currentFloor].getPlayer()->playerPickup(target);
                potion = false;
            } else {
                floors[currentFloor].getPlayer()->playerMove(target);
                pair<int, int> coords = floors[currentFloor].getPlayer()->getPos();
                    
                // Checks if player is on a stair, if so go up a floor
                if(floors[currentFloor].checkCoord(coords.first, coords.second) == CellType::Stair) ascendFloor();
                else floors[currentFloor].moveEnemies();
            }
        }


        // Output display after each command
        floors[currentFloor].cmdDisplay();
    }
}

void GameController::ascendFloor() {
    floors[currentFloor].getPlayer()->resetStat();
    
    if(currentFloor != 4) {
        // Update floor ptr for player
        floors[currentFloor].getPlayer()->setFloor(&floors[currentFloor]);

        floors[currentFloor + 1].setPlayer(floors[currentFloor].getPlayer());
        floors[currentFloor].setPlayer(nullptr);
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
        cout << "Score: " << floors[currentFloor].getPlayer()->getScore() << endl;

        cout << endl << "Press 'C' to Continue" << endl;

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
        cout << "Score: " << floors[currentFloor].getPlayer()->getScore() << endl;
    }
}
