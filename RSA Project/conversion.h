#ifndef CONVERSION_H
#define CONVERSION_H

#include <string>

//conversion and reconversion functions for strings to integers and vice versa.

//converts 26 english capital letters phrase to an integer
int conversion (const std::string& input);


//reconverts integer back to original 26 english capital letters phrase
std::string reconversion (int input);

#endif