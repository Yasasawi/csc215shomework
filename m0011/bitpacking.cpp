#include "bitpacking.h"

short int packThree(char high, char mid, char low) 
{
    unsigned char mask = 31;
    unsigned char highMask; 
    unsigned char midMask;
    unsigned char lowMask; 
    short int packedInt = 0;  

    highMask = high & mask; 
    midMask = mid & mask;
    lowMask = low & mask; 
    
    packedInt = packedInt | highMask;
    packedInt = packedInt << 5; 
    packedInt = packedInt | midMask;
    packedInt = packedInt << 5;
    packedInt = packedInt | lowMask;
    

    return packedInt;
}

void unpackThree(short int data, char& high, char& middle, char& low, CHARCASE charCase)
{
    unsigned char lowerCaseMask = 96; 
    unsigned char upperCaseMask = 64;
    unsigned char mask = 31;
    char tempH, tempM, tempL;
     

    if(charCase == LOWERCASE)
    {
        tempL = data & mask;
        data = data >> 5;
        tempM = data & mask;
        data = data >> 5;
        tempH = data & mask;

        tempL = tempL | lowerCaseMask;
        tempM = tempM | lowerCaseMask;
        tempH = tempH | lowerCaseMask;
    }
    else
    {
        tempL = data & mask;
        data = data >> 5;
        tempM = data & mask;
        data = data >> 5;
        tempH = data & mask;

        tempL = tempL | upperCaseMask;
        tempM = tempM | upperCaseMask;
        tempH = tempH | upperCaseMask;
    }

    high = tempH;
    middle = tempM;
    low = tempL; 
}