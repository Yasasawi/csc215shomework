#include "sortedSingle.h"

sortedSingle::sortedSingle()
{
    headptr = nullptr; 
}

sortedSingle::~sortedSingle()
{
    clear();
}

bool sortedSingle::empty()
{
    if (headptr == nullptr)
    {
        return true;
    }
    else
    {
        return false; 
    }
}

int sortedSingle::size()
{
    node* temp = headptr; 
    int size = 0;
    while (temp != nullptr)
    {
        size++;
        temp = temp->next;
    }
    return size;
}

bool sortedSingle::find(int item)
{
    node* temp = headptr;
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}

int sortedSingle::retrievePosition(int item)
{
    node* temp = headptr;
    int i = 1;
    while (temp != nullptr)
    {
        if (temp->theItem == item)
        {
            return i;
        }
        i++;
        temp = temp->next;
    }
    return 0;
}