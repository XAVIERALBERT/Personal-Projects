#ifndef PLAYER_H
#define PLAYER_H

#include <utility>
#include <array>
#include "Grid.h"
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
        //getters: returns ships
        auto getCarrier();
        auto getBattleship();
        auto getDestroyer();
        auto getSub();
        auto getRhib();
};

#endif //PLAYER_H