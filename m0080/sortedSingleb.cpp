#include "sortedSingle.h"

bool sortedSingle::insert(int item)
{
    node* temp;
    node* insert;
    insert = new node();
    insert->theItem = item;

    temp = headptr;

    if (headptr == nullptr || headptr->theItem >= item)
    {
        insert->next = headptr;
        headptr = insert;
        return true;
    }

    while (temp->next != nullptr && temp->next->theItem < item)
    {
        temp = temp->next;
    }
    insert->next = temp->next;
    temp->next = insert;

    return true;
}

void sortedSingle::print(ostream& out, string seperator)
{
    node* temp;
    temp = headptr;
    while (temp != nullptr)
    {
        if (temp->next == nullptr)
        {
            out << temp->theItem;
        }
        else
        {
            out << temp->theItem << seperator;
        }
        temp = temp->next;
    }
}