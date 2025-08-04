#include "rsa.h"
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

/*NOTE: public key: (n, e), where n = p*q (two primes selected beforehand) and e = gcd(e, euler_phi(n)) = 1
        private key: d = inverse.mod(e, euler_phi(n))
        where n = p* q (two primes selected beforehand), and euler_phi(n) = (p - 1) * (q - 1)*/

//encryption
int encryption (int message, int e, int n) {
    int encrypted = int(pow(message, e)) % n;
    return encrypted;
}

//decryption
int decryption (int cipher, int d, int n) {
    int decrypted = int(pow(cipher, d)) % n;
    return decrypted;
}

//prime number checker
bool isPrime(int num) {
    if (num <= 2) {
        return true;
    }
    for (int i = 2; i < num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

//since p and q are both primes euler phi = (p-1)*(q-1)
int eulerPhi(int p, int q) {
    try {
        if (isPrime(p) == false) {
            throw(p);
        }
        if (isPrime(q) == false) {
            throw(q);
        }
        return (p-1) * (q-1);
    }
    catch (int notPrime) {
        cout<<"This number (p or q) is not a prime that is needed to find 'n': "<< notPrime <<endl;
    }
    return -1;  
}

//implement inverse_mod using Extended Euclid Algo.

//extended euclidean gcd algorithm to help calculate inverse_mod
int extndEuc(int a, int b, int& x, int& y) {
    //base case
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1;
    int y1;
    int gcd = extndEuc(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

//inverse mod function SHOULD RETURN x FROM ax + by = gcd(a,b)
//NOTE: we are doing inverseMod(e, eulerPhi(n))
int inverseMod(int e, int n) {
    int x;
    int y;
    int inv = extndEuc(e,n,x,y);
    return x;
}

