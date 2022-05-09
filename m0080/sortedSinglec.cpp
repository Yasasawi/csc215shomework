#include "sortedSingle.h"

bool sortedSingle::remove(int item)
{
    node* temp;
    node* prev;
    temp = headptr;
    prev = nullptr;

    if (headptr == nullptr)
    {
        return false;
    }

    if (temp->theItem == item)
    {
        headptr = temp->next;
        delete temp;
        return true;
    }

    while (temp != nullptr && temp->theItem != item)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == nullptr)
    {
        return false;
    }

    prev->next = temp->next;

    delete temp;
    return true;
}

void sortedSingle::clear()
{
    node* temp;
    node* next;
    next = nullptr;
    temp = headptr;

    if (headptr == nullptr)
    {
        return;
    }
    while (temp != nullptr)
    {
        next = temp->next;
        free(temp);
        temp = next;
    }
    headptr = nullptr;
}