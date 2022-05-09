#include "strLib.h"

void replaceAllString(string& str, string lookFor, string replaceWith)
{
    //set pos to a size_type value of 0 to start at the beginning of string
    string::size_type pos = 0;
    //while loop that makes sure that position is not npos 
    while ((pos = str.find(lookFor, pos)) != string::npos)
    {
        //replaces the string from the beginning of the string that we are looking for and replaces it
        str.replace(pos, lookFor.length(), replaceWith);
        //moves to the end of the replaced string to then check for more
        pos += lookFor.length();
    }
}

void replaceAllCString(char* cstr, char* lookFor, char* replaceWith)
{
    char* src = cstr;
    char* start = strstr(src, lookFor); 
    char* end = nullptr;
    char* stop = nullptr;

    while (start != nullptr)
    {
        stop = new(nothrow) char[strlen(start)];
        if (stop == nullptr)
        {
            delete[] stop;
            return;
        }
        end = start + strlen(lookFor);
        strcpy(stop, end);
        strcpy(start, replaceWith);
        end = start + strlen(replaceWith);
        strcat(end, stop);
        delete[] stop;

        src = end;
        start = strstr(src, lookFor);
    }
}