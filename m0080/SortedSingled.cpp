/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"


sortedSingle::sortedSingle(sortedSingle& l)
{
    node* src;
    node* dest;

    // handle copying an empty list
    headptr = nullptr;
    if (l.empty() == true)
        return;


    // attach the first node
    headptr = new(nothrow) node;
    headptr->theItem = l.headptr->theItem;
    headptr->next = nullptr;

    // attach the remaining node
    dest = headptr;
    src = l.headptr->next;
    while (src != nullptr)
    {
        dest->next = new(nothrow) node;
        dest = dest->next;
        dest->theItem = src->theItem;
        src = src->next;
    }
    dest->next = nullptr;
}
