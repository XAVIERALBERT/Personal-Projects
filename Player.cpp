#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <array>
#include "Player.h"
using namespace std;

//constructor
Player::Player () {
    for (int i = 0; i < 5; i++) {
        carrier[i] = make_pair(0, 0);
    }

    for (int i = 0; i < 4; i++) {
        battleship[i] = make_pair(0, 0);
    }

    for (int i = 0; i < 3; i++) {
        destroyer[i] = make_pair(0, 0);
    }

    for (int i = 0; i < 2; i++) {
        sub[i] = make_pair(0, 0);
    }

    rhib[0] = make_pair(0, 0);
}

//setters
void Player::setCarrier(int x1, int y1, int x2, int y2) {
    //bound checks
    try {
        if (isLegal(x1,y1) == false || isLegal(x2,y2) == false) {
            throw "Out of Bounds.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
        return;
    }
    //vertical orientation
    if (y1 == y2) {
        try {
            if (x2 - x1 != 4) {
                throw "Please insure correct x coordinates for carrier size.";
            }
            if (x2 < x1) {
                throw "Please ensure coordinates x2 is greater than x1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int xcounter = x1;
        int xindex = 0;
        while (xcounter < x2) {
            auto xinsert = make_pair(xcounter, y1);
            carrier[xindex] = xinsert;
            xcounter++;
            xindex++;
        }
        return;
    }

    //horizontal orientation
    if (x1 == x2) {
        try {
            if (y2 - y1 != 4) {
                throw "Please insure correct y coordinates for carrier size.";
            }
            if (y2 < y1) {
                throw "Please ensure coordinates y2 is greater than y1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int ycounter = y1;
        int yindex = 0;
        while (ycounter < y2) {
            auto yinsert = make_pair(ycounter, x1);
            carrier[yindex] = yinsert;
            ycounter++;
            yindex++;
        }
        return;
    }
    return;
}

void Player::setBattleship(int x1, int y1, int x2, int y2) {
    //bound checks
    try {
        if (isLegal(x1,y1) == false || isLegal(x2,y2) == false) {
            throw "Out of Bounds.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
        return;
    }
    //vertical orientation
    if (y1 == y2) {
        try {
            if (x2 - x1 != 3) {
                throw "Please insure correct x coordinates for battleship size.";
            }
            if (x2 < x1) {
                throw "Please ensure coordinates x2 is greater than x1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int xcounter = x1;
        int xindex = 0;
        while (xcounter < x2) {
            auto xinsert = make_pair(xcounter, y1);
            battleship[xindex] = xinsert;
            xcounter++;
            xindex++;
        }
        return;
    }

    //horizontal orientation
    if (x1 == x2) {
        try {
            if (y2 - y1 != 3) {
                throw "Please insure correct y coordinates for battleship size.";
            }
            if (y2 < y1) {
                throw "Please ensure coordinates y2 is greater than y1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int ycounter = y1;
        int yindex = 0;
        while (ycounter < y2) {
            auto yinsert = make_pair(ycounter, x1);
            battleship[yindex] = yinsert;
            ycounter++;
            yindex++;
        }
        return;
    }
    return;
}

void Player::setDestroyer(int x1, int y1, int x2, int y2) {
    //bound checks
    try {
        if (isLegal(x1,y1) == false || isLegal(x2,y2) == false) {
            throw "Out of Bounds.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
        return;
    }
    //vertical orientation
    if (y1 == y2) {
        try {
            if (x2 - x1 != 2) {
                throw "Please insure correct x coordinates for destroyer size.";
            }
            if (x2 < x1) {
                throw "Please ensure coordinates x2 is greater than x1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int xcounter = x1;
        int xindex = 0;
        while (xcounter < x2) {
            auto xinsert = make_pair(xcounter, y1);
            destroyer[xindex] = xinsert;
            xcounter++;
            xindex++;
        }
        return;
    }

    //horizontal orientation
    if (x1 == x2) {
        try {
            if (y2 - y1 != 2) {
                throw "Please insure correct y coordinates for destroyer size.";
            }
            if (y2 < y1) {
                throw "Please ensure coordinates y2 is greater than y1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int ycounter = y1;
        int yindex = 0;
        while (ycounter < y2) {
            auto yinsert = make_pair(ycounter, x1);
            destroyer[yindex] = yinsert;
            ycounter++;
            yindex++;
        }
        return;
    }
    return;
}

void Player::setSub(int x1, int y1, int x2, int y2) {
    //bound checks
    try {
        if (isLegal(x1,y1) == false || isLegal(x2,y2) == false) {
            throw "Out of Bounds.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
        return;
    } 
    //vertical orientation
    if (y1 == y2) {
        try {
            if (x2 - x1 != 1) {
                throw "Please insure correct x coordinates for sub size.";
            }
            if (x2 < x1) {
                throw "Please ensure coordinates x2 is greater than x1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return;
        }
        int xcounter = x1;
        int xindex = 0;
        while (xcounter < x2) {
            auto xinsert = make_pair(xcounter, y1);
            sub[xindex] = xinsert;
            xcounter++;
            xindex++;
        }
        return;
    }

    //horizontal orientation
    if (x1 == x2) {
        try {
            if (y2 - y1 != 1) {
                throw "Please insure correct y coordinates for sub size.";
            }
            if (y2 < y1) {
                throw "Please ensure coordinates y2 is greater than y1.";
            }
        }
        catch (string errCode) {
            cout <<"Error: "<< errCode << endl;
            return; 
        }
        int ycounter = y1;
        int yindex = 0;
        while (ycounter < y2) {
            auto yinsert = make_pair(ycounter, x1);
            sub[yindex] = yinsert;
            ycounter++;
            yindex++;
        }
        return;
    }
    return;
}

void Player::setRhib(int x1, int y1) {
    //bound checks
    try {
        if (isLegal(x1,y1) == false) {
            throw "Out of Bounds.";
        }
    }
    catch (string errCode) {
        cout << errCode << endl;
        return;
    }
    auto insert = make_pair(x1,y1);
    rhib[0] = insert;
    return;
} 

bool Player::isLegal(int x, int y) {
    if (0 <= x < 10 && 0 <= y < 10) {
        return true;
    }
    return false;
}

//getter implementations
auto Player::getCarrier() {
    return this->carrier;
}

auto Player::getBattleship() {
    return this->battleship;
}

auto Player::getDestroyer() {
    return this->destroyer;
}

auto Player::getSub() { 
    return this->sub;
}

auto Player::getRhib() {
    return this->rhib;
}