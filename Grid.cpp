#include <algorithm>
#include <string>
#include <iostream>
#include <string>
#include <utility>
#include <array>
#include "Grid.h"
class Player; // Forward declaration
using namespace std;

//constructor
Grid::Grid () {
    std::memset(selfGrid, 0, sizeof(selfGrid));
    std::memset(tacGrid, 0, sizeof(tacGrid));
}

//function implementations
void Grid::showSelf() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << selfGrid[i][j] << " ";
        }
         cout << endl;
    }
}

void Grid::showTac() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << tacGrid[i][j] << " ";
        }
         cout << endl;
    }
}

int fire(int x, int y) {
    try {
        if (!(0 <= x < 10)||!(0 <= y < 10)) {
            throw "Please enter valid target coordinates.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
    }
    //return 2 (miss), 3 (hit)
    return 0;
    
}