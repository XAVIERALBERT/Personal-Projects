#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include "conversion.h"
#include "rsa.h"
using namespace std;

//define p, q, e, n, d variables here

//Main Program
int main () {
    //test conversion/reconverison
    std::string input = "XAVIER";
    int result = conversion(input);
    std::cout << "Result: " << result << std::endl;
    string strResult = reconversion(result);
    std::cout << "Reconverted: " << strResult << std::endl;
    cout<< " "<< endl;
    
    std::string input2 = "ALBERT";
    int result2 = conversion(input2);
    std::cout << "Result: " << result2 << std::endl;
    string strResult2 = reconversion(result2);
    std::cout << "Reconverted: " << strResult2 << std::endl;
    cout<< " "<< endl;

    std::string input3 = "AAAA";
    int result3 = conversion(input3);
    std::cout << "Result: " << result3 << std::endl;
    string strResult3 = reconversion(result3);
    std::cout << "Reconverted: " << strResult3 << std::endl;
    cout<< " "<< endl;

    //test rsa encrypt/decrypt
    cout << "Message m = 2, p = 3, q = 11, n = p*q = 33, euler_phi(n) = 20, e = 7, d = 3" << endl;
    int rsa_encrypt = encryption(2, 7, 33);
    cout<< "The expected encryption of m = 2 is c = 2^7 % 33 = 29"<< endl;
    cout<< "Got encrypted message: " << rsa_encrypt << endl;
    int rsa_decrypt = decryption(rsa_encrypt, 3, 33);
    cout<< "The expected decryption of c = 29 is m = 29^3 % 33 = 2"<< endl; 
    cout<< "Got decryted message: " << rsa_decrypt<< endl;
    cout<< " "<< endl;

    //test prime number checker
    bool yesPrime = isPrime(37);
    cout<< "Should be True (or 1): "<< yesPrime<< endl;
    bool noPrime = isPrime(90);
    cout<< "Should be False (or 0): " << noPrime<<endl;
    cout<< " "<< endl;

    //testing eulerPhi 
    cout<< "Euler Phi of 37 and 61 are: " << eulerPhi(37,61) << endl;
    cout<< eulerPhi(12,71) << endl;
    cout<< eulerPhi(43,88) << endl;
    cout<< " "<< endl;

    //testing extended Euclidean Algo.
    int a = 41; int b = 50; int x; int y;
    cout<<"Finding x and y where a = 41 and b = 50 "<<endl;
    int euc = extndEuc(a,b,x,y);
    cout<<"Expected x = 11, Got x = "<< x << endl;
    cout<<"Expected y = -9, Got y = "<< y << endl;
    cout << " " << endl;

    //testing inverseMod
    int x1; int y1; int eul = eulerPhi(5,11);
    int d = inverseMod(27, eul);
    cout<< "From public key (n,e) = (55,27) --> Expected d = 3, Got d = " << d << endl;
    cout<< " " << endl;

    return 0;
}