#include "conversion.h"
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int conversion (const string& input) {
    vector<char> alphabet = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    int toReturn = 0;
    int counter = 0;
    for (int i = input.length() - 1; i >= 0; i--) {
        int toAdd = 0;
        char x = input[i];
        for (int j = 0; j < alphabet.size(); j++) {
            if (x == alphabet[j]) {
                toAdd = j;
            }
        }
        toReturn = toReturn + (toAdd * int(pow(27,counter)));
        counter++;
    }
    return toReturn;
}

std::string reconversion (int input) {
    vector<char> alphabet = {' ','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    vector<int> toReverse;
    string toReturn;
    int index = 0;
    int mod = input;
    while (mod != 0) {
        index = mod % 27;
        toReturn = toReturn + alphabet[index];
        mod = mod / 27;
    }
    reverse(toReturn.begin(),toReturn.end());
    return toReturn;
}