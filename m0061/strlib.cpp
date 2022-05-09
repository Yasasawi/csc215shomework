#include "strlib.h"

int recCStrCmp(char cstr[], char cmp[], int index)
{
    char ch1 = cstr[index];
    char ch2 = cmp[index];

    if (isalpha(ch1) && isalpha(ch2))
    {
        ch1 = tolower(ch1);
        ch2 = tolower(ch2);
    }
    if ((ch1 - ch2) == 0 && ((ch1 == '\0') && (ch2 == '\0')))
    {
        return 0; 
    }
    else if ((ch1 - ch2) == 0 && (ch1 != '\0') && (ch2 != '\0'))
    {
        return recCStrCmp(cstr, cmp, index + 1);
    }
    return (ch1 - ch2);
}

int recCStrCmp(char* cstr, char* cmp)
{
    char ch1 = *cstr;
    char ch2 = *cmp; 
    if (isalpha(*cstr) && isalpha(*cmp))
    {
        ch1 = tolower(ch1);
        ch2 = tolower(ch2);
    }
    
    if ((ch1 == '\0') && (ch2 == '\0'))
    {
        return 0; 
    }
    
    if ((ch1 - ch2) != 0)
    {
        return (ch1 - ch2);
    }

    cstr = cstr + 1;
    cmp = cmp + 1;
    return recCStrCmp(cstr, cmp);
}
