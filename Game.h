#ifndef GAME_H
#define GAME_H

#include <algorithm>
#include <iostream>
#include <utility>
#include <string>
#include <array>
using namespace std;

class Player {
    public:
        Player(); //constructor
        pair<int,int> carrier[5];
        pair<int,int> battleship[4];
        pair<int,int> destroyer[3];
        pair<int,int> sub[2];
        pair<int,int> rhib[1];

    private: 
        //setters
        void setCarrier(int x1, int y1, int x2, int y2); //set carrier array elements, (x1,y1) are start points and (x2,y2) are endpoints, can only go vertical or horizontal
        void setBattleship(int x1, int y1, int x2, int y2); //set battleship array elements, (x1,y1) are start points and (x2,y2) are endpoints, can only go vertical or horizontal
        void setDestroyer(int x1, int y1, int x2, int y2); //set destroyer array elements, (x1,y1) are start points and (x2,y2) are endpoints, can only go vertical or horizontal
        void setSub(int x1, int y1, int x2, int y2); //set sub array elements, (x1,y1) are start points and (x2,y2) are endpoints, can only go vertical or horizontal
        void setRhib(int x1, int y1); //set rhib array elements, (x1,y1) are start points and (x2,y2) are endpoints, can only go vertical or horizontal
        bool isLegal(int x, int y); //HELPER: boundary checker for x and y coords

};

class Grid {
    public:
        Grid(); //constructor
        //grid guide: 0: untouched, 1:player's ships, 2:miss, 3:hit
        int selfGrid[10][10]; //self grid where it shows your own ship locations
        int tacGrid[10][10]; //tac grid where it shows hits and misses and opponent ships

    private: 
        void showSelf(); //shows player ships and hits and targets performed by opponent (prints player 10x10 array)
        void showTac(); //shows player hits and targets on opponent (prints target 10x10 array)
        string fire(int x, int y, Player P); //fires on int,int coordinates (use isHit() bool to prevent repeat fire attempts) used to update grid     
};
#endif //GAME_H