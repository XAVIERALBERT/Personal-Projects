#ifndef RSA_H
#define RSA_H

//RSA encryption and decryption functions as well as mathemtical functions for RSA

//encryption function
int encryption (int message, int e, int n);

//decryption function
int decryption (int cipher, int d, int n);

//prime checker function
bool isPrime(int num);

//euler phi function, ints p and q are guaranteed primes
int eulerPhi(int p, int q);

//extended euclidean algorithm function
int extndEuc(int a, int b, int& x, int& y);

//inverse mod function
int inverseMod(int a, int n);

#endif