#ifndef GRID_H
#define GRID_H

#include <utility>
#include <string>
#include <array>
class Player; // Forward declaration
#include "Player.h"
using namespace std;

class Grid {
    public:
        Grid(); //constructor
        //grid guide: 0: untouched, 1:player's ships, 2:miss, 3:hit
        int selfGrid[10][10]; //self grid where it shows your own ship locations
        int tacGrid[10][10]; //tac grid where it shows hits and misses and opponent ships

    private: 
        void showSelf(); //shows player ships and hits and targets performed by opponent (prints player 10x10 array)
        void showTac(); //shows player hits and targets on opponent (prints target 10x10 array)
        int fire(int x, int y); //fires on int,int coordinates (use isHit() bool to prevent repeat fire attempts)
        auto getShip(const Player& ship); //gets ships coordinates to put into selfGrid
        bool isDestroyed(const Player& ship); //checks ship arrays are all pairs of {-1,-1} (if all array elements are {-1,-1} == true, else = false)
        bool isHit(int x, int y); //checks if (x,y) is a hit or a miss      
};

#endif //GRID_H