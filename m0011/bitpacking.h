#ifndef __BITPACKING__H__
#define __BITPACKING__H__
#include <iostream>
using namespace std; 

//write enum here
enum CHARCASE { UPPERCASE, LOWERCASE };

//write prototypes here
short int packThree(char high, char mid, char low);
void unpackThree(short int firstThree, char& high, char& middle, char& low, CHARCASE);

#endif